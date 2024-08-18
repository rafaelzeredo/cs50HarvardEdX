from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():

    # Validar Inscrição
    if not request.form.get("name") or request.form.get("tipo de aula") not in ["Pilates", "Hidroginástica", "Personalizado"]:
        return render_template("failure.html")

    # Confirmar Inscrição
    return render_template("success.html")