import serial, time, json

class ConnectService:
    def __init__(self, usb, baudrate, printer_id, action_id, timeout = 2):
        self.usb = usb
        self.baudrate = baudrate

        self.printer_id = printer_id
        self.action_id = action_id

        self.timeout = timeout

        self.init()

    def init(self):
        self.conn = serial.Serial(self.usb, self.baudrate, timeout=self.timeout) 
        self.close()

    def close(self):
        self.conn.close()

    def open(self):
        self.conn.open()
    
    def send(self):
        self.open()
        time.sleep(1)

        data_to_send = f"{self.printer_id};{self.action_id}\n"
        self.conn.write(data_to_send.encode())

        response = self.conn.readline().decode()

        data_set = {"response": response}
        json_dump = json.dumps(data_set)

        self.close()
        return json_dump
