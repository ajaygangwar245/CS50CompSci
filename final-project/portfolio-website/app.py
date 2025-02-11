import os

from cs50 import SQL
from flask import Flask, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///mails.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/education")
def education():
    return render_template("education.html")


@app.route("/tech")
def tech():
    return render_template("tech.html")


@app.route("/soft")
def soft():
    return render_template("soft.html")


@app.route("/hobby")
def hobby():
    return render_template("hobby.html")


@app.route("/contact", methods=["GET", "POST"])
def contact():
    if request.method == "POST":

        # Access form data
        # Name
        name = request.form.get("name")
        if not name:
            return redirect("/contact")

        # Query
        query = request.form.get("query")
        if not query:
            return redirect("/contact")

        # E-mail
        email = request.form.get("email")
        if not email:
            return redirect("/contact")

        # Insert data into DB
        db.execute("INSERT INTO mails (name, query, email) VALUES(?, ?, ?)", name, query, email)

        # Go back to homepage
        return redirect("/contact")

    else:
        # Render contact page
        return render_template("contact.html")
