import json, serial

class EventController:
    def __init__(self, printer, action, connection):
        self.printer = printer
        self.action = action

        self.connection = connection

        self.dispatch()
    def dispatch(self):
        return self.connection.send()

        """ data_set = {'Printer': self.printer, 'Action': self.action}
        json_dump = json.dumps(data_set)

        return json_dump """
