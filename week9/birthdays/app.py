import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        # Access form data
        name = request.form.get("name")
        if not name:
            return redirect("/")

        # Months
        month = request.form.get("month")
        if not month:
            return redirect("/")

        #  if the user doesn’t provide a numeric value for month
        try:
            month = int(month)
        except ValueError:
            return redirect("/")

        #  if the user doesn’t provide value within range for month (i.e., 1 - 12)
        if month < 1 or month > 12:
            return redirect("/")

        # Days
        day = request.form.get("day")
        if not day:
            return redirect("/")

        #  if the user doesn’t provide a numeric value for day
        try:
            day = int(day)
        except ValueError:
            return redirect("/")

        #  if the user doesn’t provide value within range for day (i.e., 1 - 31)
        if day < 1 or day > 31:
            return redirect("/")

        # Insert data into DB
        db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        # Go back to homepage
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        # Query for all birthdays
        birthdays = db.execute("SELECT * FROM birthdays")

        # Render birthdays page
        return render_template("index.html", birthdays=birthdays)
