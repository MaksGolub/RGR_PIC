from flask import render_template
from app import app

@app.route('/')
@app.route('/index')
def index():
    user = {'username': 'Maks'}
    posts = [
        {
            'author': {'username': 'Info1'},
            'body': 'string1'
        },
        {
            'author': {'username': 'info2'},
            'body': 'string2'
        }
    ]
    return render_template('index.html', title='Home', user=user, posts=posts)