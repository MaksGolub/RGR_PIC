from flask import Flask, request
from flask import render_template



app = Flask(__name__) #create the Flask app

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

@app.route('/query-example')
def query_example():
	language = request.args.get('language') 
	framework = request.args['framework']
	website = request.args.get('website')

	return '''<h1>The language value is: {}</h1>
		<h1>The framework value is: {}</h1>
		<h1>The website value is: {}'''.format(language, framework, website)

@app.route('/form-example', methods=['GET', 'POST'])
def form_example():
	if request.method == 'POST':  
		language = request.form.get('language')
		framework = request.form['framework']

		return '''<h1>The language value is: {}</h1>
			<h1>The framework value is: {}</h1>'''.format(language, framework)

	return '''<form method="POST">
                  Language: <input type="text" name="language"><br>
                  Framework: <input type="text" name="framework"><br>
                  <input type="submit" value="Submit"><br>
		</form>'''

application = app

if __name__ == '__main__':
    from os import environ as env
    port=int(env.get('PORT', 5000))
    app.run(host='0.0.0.0', port=port) #run app in debug mode on port 
5000
