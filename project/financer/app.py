from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, brl, calculate_totals

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["brl"] = brl

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


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    base_tables = [{"entradas": db.execute("SELECT description, value FROM entradas WHERE user_id = ?", session["user_id"])},
                   {"contas": db.execute("SELECT description, value FROM contas WHERE user_id = ?", session["user_id"])},
                   {"dividas": db.execute("SELECT description, value FROM dividas WHERE user_id = ?", session["user_id"])},
                   {"lazer": db.execute("SELECT description, value FROM lazer WHERE user_id = ?", session["user_id"])},
                   {"outros": db.execute("SELECT description, value FROM outros WHERE user_id = ?", session["user_id"])}]

    tables = [[*table.keys()] for table in base_tables]

    if request.method == "GET":
        entradas, saidas, total = calculate_totals(base_tables)
        return render_template("index.html", tables=tables, base_tables=base_tables, entradas=entradas, saidas=saidas, total=total)

    table = request.form.get("table")
    desc = request.form.get("descricao").strip().lower().replace("á", "a").replace("ç", "c").replace("ã", "a")
    valor = request.form.get("valor")

    if desc is None or valor is None or table is None:
        return apology("Must provide table/description/value", 400)

    descricoes = [descricao["description"] for descricao in db.execute("SELECT description FROM ? WHERE user_id = ?", table, session["user_id"])]

    if desc not in descricoes:
        db.execute("INSERT INTO ? (user_id, description, value) VALUES (?, ?, ?)", table, session["user_id"], desc, valor)

    base_tables = [{"entradas": db.execute("SELECT description, value FROM entradas WHERE user_id = ?", session["user_id"])},
                   {"contas": db.execute("SELECT description, value FROM contas WHERE user_id = ?", session["user_id"])},
                   {"dividas": db.execute("SELECT description, value FROM dividas WHERE user_id = ?", session["user_id"])},
                   {"lazer": db.execute("SELECT description, value FROM lazer WHERE user_id = ?", session["user_id"])},
                   {"outros": db.execute("SELECT description, value FROM outros WHERE user_id = ?", session["user_id"])}]

    entradas, saidas, total = calculate_totals(base_tables)

    return render_template("index.html", tables=tables, base_tables=base_tables, entradas=entradas, saidas=saidas, total=total)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    username = request.form.get("username").strip()
    password = request.form.get("password").strip()
    confirmation = request.form.get("confirmation").strip()

    if username == None or password == None:
        return apology("must provide username/password", 403)

    if confirmation == None:
        return apology("must provide confirmation of password", 403)

    if " " in username or " " in password:
        return apology("Username/Password invalid", 403)

    if len(password) < 8:
        return apology("must provide 8 charcters for password!", 403)

    if password != confirmation:
        return apology("Password different from confirmation", 403)

    user = db.execute(
        "SELECT id, username FROM users WHERE username = ?",
        username,
        )

    if len(user) >= 1:
        return apology("Username already exists", 403)

    db.execute(
        "INSERT INTO users (username, hash) VALUES (?, ?)",
        username,
        generate_password_hash(password),
        )

    session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", username)[0]["id"]

    return redirect("/")


@app.route("/delete", methods=["POST"])
@login_required
def delete():
    table = request.form.get("table")
    item = request.form.get("item")

    if table and item:
        db.execute("DELETE FROM ? WHERE user_id = ? AND description = ?", table, session["user_id"], item)

    return redirect("/")


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
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
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
