from flask import Flask, render_template, request
# Flask and render_template belong to flask library
# render_template: đi đến thu mục index.html  và render =>

# __name__ : đề cập đến tên của tệp hiện tại: Web Folder
app =Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method=="GET":
        return render_template("index.html")

    # @app.route("/greet")
    # @app.route("/greet", methods=["POST"])

    elif request.method=="POST":
    # request.args: for method="GET", request.form: for method: POST
        return render_template("greet.html", name=request.form.get("name"))