import json

class EventController:
    def __init__(self, printer, event):
        self.printer = printer
        self.event = event

        self.dispatch()
    def dispatch(self):
        data_set = {'Printer': self.printer, 'Event': self.event}
        json_dump = json.dumps(data_set)

        return json_dump
