#EROROR: ModuleNotFoundError: No module named 'flask_mail'

import os
from cs50 import SQL
from flask import Flask, render_template, request, redirect

# CẤU HÌNH MAIL
from flask_mail import Mail, Message


app = Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"]=os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_USER_NAME"]= os.getenv("MAIL_USER_NAME")
app.config["MAIL_PASSWORD"]=os.getenv("MAIL_PASSWORD")
app.config["MAIL_SERVER"]="smtp.gmail.com"
app.config["MAIL_PORT"]=587
app.config["MAIL_USE_TLS"]=True
mail = Mail(mail)

# REGISTRIANS = {}

# You need to create a table
# db = SQL("sqlite:///froshims.db")

SPORTS = [
    "Volleyball",
    "Soccer",
    "Badminton",
    "Shuttlecock Kicking",
    "Tennis"
    ]



@app.route("/")
def index():
     return render_template("index.html", sports=SPORTS)



@app.route("/register", methods=["POST"])
def register():
    email  = request.form.get("email")
    if not email:
        return render_template("error.html", messages="Missing email")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", messages="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", messages="Invalid sport")
    else:
        # REGISTRIANS[name]=sport

        # db.execute("INSERT INTO froshims (name, sport) VALUES(?, ?)", email, sport)
        message = Message("You are registered!", recipients=[email])
        mail.send(message)
        return render_template("success.html")
#         return redirect("/registrants")



# @app.route("/registrants")
# def registrants():
#     registrants = db.execute("SELECT * FROM froshims")
#     return render_template("registrians.html", registrians = registrants)