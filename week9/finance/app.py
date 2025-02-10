import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # get stocks and shares of user
    stocks = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", session["user_id"])

    # get cash balance of user
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    # Loop over stock and add price & total value
    for stock in stocks:
        quote = lookup(stock["symbol"])
        stock["price"] = quote["price"]
        stock["value"] = stock["price"] * stock["total_shares"]

    return render_template("index.html", stocks=stocks, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        if not symbol:
            return apology("symbol must be entered", 400)
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("positive number of shares must be entered", 400)

        quote = lookup(symbol)
        if quote is None:
            return apology("symbol not found", 400)

        price = quote["price"]
        total_cost = int(shares) * price
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        if cash < total_cost:
            return apology("not enough cash", 400)

        # update users table
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, session["user_id"])

        # add purchase to the history table
        db.execute("INSERT INTO transactions(user_id, symbol, shares, price) VALUES(?, ?, ?, ?)",
                   session["user_id"], symbol, shares, price)

        flash(f"Bought {shares} shares of {symbol} for {usd(total_cost)}")

        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # query database for all transactions of user order by most recent on top
    transactions = db.execute(
        "SELECT * FROM transactions WHERE user_id = ? ORDER BY timestamp DESC", session["user_id"])

    # render history page with transactions
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol", 400)
        return render_template("quote.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # forget any user_id
    session.clear()

    # user form submitted via POST
    if request.method == "POST":

        # check username was submitted
        if not request.form.get("username"):
            return apology("username must be provided", 400)

        # check password was submitted
        elif not request.form.get("password"):
            return apology("password must be provided", 400)

        # check password confirmation
        elif not request.form.get("confirmation"):
            return apology("password must be confirmed", 400)

        # check password and it's confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # check if user already exists
        if len(rows) != 0:
            return apology("username already exists", 400)

        # insert new user into database
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)",
                   request.form.get("username"), generate_password_hash(request.form.get("password")))

        # query databse for user inserted recently
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # remeber the user that logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to homepage
        return redirect("/")

    # user form submitted via GET
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # get stocks and shares of user
    stocks = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0", session["user_id"])

    # if user submits the form
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        if not symbol:
            return apology("symbol must be provided", 403)
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("positive number of shares must be provided")
        else:
            shares = int(shares)

        for stock in stocks:
            if stock["symbol"] == symbol:
                if stock["total_shares"] < shares:
                    return apology("not enough shares", 400)
                else:
                    # get quote
                    quote = lookup(symbol)
                    if quote is None:
                        return apology("symbol not found", 404)
                    price = quote["price"]
                    total_sale = shares * price

                    # update users table
                    db.execute("UPDATE users SET cash = cash + ? WHERE id = ?",
                               total_sale, session["user_id"])

                    # add sale of stocks to history table
                    db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
                               session["user_id"], symbol, shares, price)

                    flash(f"Sold {shares} shares of {symbol} for {usd(total_sale)}!")
                    return redirect("/")

            return apology("symbol not found", 404)

    # if user visits the page
    else:
        return render_template("sell.html", stocks=stocks)
