from flask import redirect, render_template, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/0.12/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def brl(value):
    """Format value as BRL."""
    return f"R${value:,.2f}".replace(".", "x").replace(",", ".").replace("x", ",")

def calculate_totals(base_tables):
    values = [item["value"] for table in base_tables for item in list(table.values())[0]]
    entradas = sum(item["value"] for table in base_tables if "entradas" in table for item in list(table.values())[0])
    saidas = sum(values) - entradas if sum(values) >= entradas else sum(values)
    total = entradas - saidas

    return entradas, saidas, total
