# Libraries
from flask import *
# App
from app import *
# Controllers
from Controllers.EventController import *

@app.route("/", methods=["GET"])
def home_page(): 
    data_set = {'Page': 'Home'}
    json_dump = json.dumps(data_set)

    return json_dump

@app.route("/event/", methods=["GET"]) # /printer/?
def printer():
    printer_id = str(request.args.get("printer"))
    event = str(request.args.get("event"))

    controller = EventController(printer_id, event)
    return controller.dispatch()