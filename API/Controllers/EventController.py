import json, serial

class EventController:
    def __init__(self, printer, action, connection):
        self.printer = printer
        self.action = action

        self.connection = connection

        self.dispatch()
    def dispatch(self):
        return self.connection.send()
