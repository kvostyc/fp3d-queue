# Libraries
from flask import *

# App
from app import *

# Controllers
from Controllers.EventController import *

# Services
from Services.ConnectService import *

# Connections
from connections import config, get_printer_config

@app.route("/", methods=["GET"])
def home_page():
    data_set = {"Page": "Home"}
    json_dump = json.dumps(data_set)

    return json_dump


@app.route("/event/", methods=["GET"])  # /event/?
def printer():
    printer_id = str(request.args.get("printer"))
    action_id = str(request.args.get("action"))

    # Config init
    printer_config = get_printer_config(config, int(printer_id))

    if printer_config:
        printer_id = printer_config["id"]
        port = printer_config["port"]
        baud_rate = printer_config["baud_rate"]
        
        connection = ConnectService(port, baud_rate, printer_id, action_id)

        controller = EventController(printer_id, action_id, connection)
        return controller.dispatch()
    else:
        data_set = {"response": "Tlačiareň sa nenachádza v configu"}
        json_dump = json.dumps(data_set)
        return json_dump
