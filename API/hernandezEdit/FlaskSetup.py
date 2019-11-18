from flask import Flask
from flask_restful import Api, Resource, reqparse

app = Flask(__name__)
api = Api(app)
users = [
    {
        "name": "Music",
        "result": 0
    },
    {
        "name": "Speech",
        "result": 0
    },
    {
        "name": "Noise",
        "result": 0
    }
]

countM = 0
countS = 0
countN = 0
class User(Resource):
    def get(self, name):
        for user in users:
            if(name == user["name"]):
                return user, 200
        return "User not found", 404

    def post(self, name):
        global countM
        global countS
        global countN
        parser = reqparse.RequestParser()
        parser.add_argument("result")
        args = parser.parse_args()

        for user in users:
            if('Music' == user["name"]):
                countM += 1
                user.update({'result': countM})
                
                return user, 201
            if('Speech' == user["name"]):
                countS += 1
                user.update({'result': countS})
                
                return user, 201
            if('Noise' == user["name"]):
                countN += 1
                user.update({'result':countN})
                
                return user, 201
          #      return "User with name {} already exists".format(name), 400

        user = {
            "name": name,
            "result": args["result"]
        }
        users.append(user)
        return user, 201

    def put(self, name):
        parser = reqparse.RequestParser()
        parser.add_argument("result")
        args = parser.parse_args()

        for user in users:
            if(name == user["name"]):
                user["result"] = args["result"]
                return user, 200
        
        user = {
            "name": name,
            "result": args["result"]
        }
        users.append(user)
        return user, 201

    def delete(self, name):
        global users
        users = [user for user in users if user["name"] != name]
        return "{} is deleted.".format(name), 200
      
api.add_resource(User, "/user/<string:name>")

app.run(debug=True)
	
