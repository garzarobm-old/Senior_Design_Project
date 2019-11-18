
from flask import Flask, jsonify

app = Flask(__name__)

@app.errorhandler(400)
def not_found(error):
	return make_response(jsonify({'error': 'bad request'}),400)


@app.errorhandler(404)
def not_found(error):
	return make_response(jsonify({'error': 'Not found'}),404)

tasks = [
    {
	
        'id': 1,
        'title': u'testing',
        'mochaTests': 7, 
		'junitTests' : 4,
        'done': False
    },
    {
	
        'id': 2,
        'title': u'example2',
        'mochaTests': 0, 
		'junitTests' : 0,
        'done': False
    }
]

@app.route('/linedrivebetting', methods=['GET'])
def get_tasks():
    return jsonify({
	'tasks': tasks})
@app.route('/linedrivebetting/<int:task_id>', methods=['GET'])
def	get_task(task_id):
	task = [task for task in tasks if task['id'] == task_id]
	if len(task) == 0:
		abort(404)
	return jsonify({'task': task[0]})



if __name__ == '__main__':
    app.run(debug=True)

