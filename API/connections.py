import json


def load_config():
    with open("connections.json", "r") as config_file:
        config = json.load(config_file)
    return config


def get_printer_config(config, index):
    printers = config["printers"]
    if 1 <= index <= len(printers):
        return printers[index - 1]
    else:
        return None


# Inicializacia konfiguracia
config = load_config()
