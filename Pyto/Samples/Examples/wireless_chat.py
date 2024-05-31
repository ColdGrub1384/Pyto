"""
Send text or images to other devices running this script remotely.
"""

import multipeer
import threading
import json
import photos
import base64
from PIL import Image
from io import BytesIO
from datetime import datetime
from UIKit import UIDevice


DEVICE_NAME = str(UIDevice.currentDevice.name)


def listen():
    
    while True:
        data = multipeer.wait()
        
        if data is None:
            break
        
        data = json.loads(data)
        
        device_name = data["device_name"]
        try:
            message = data["message"]
            time = data["time"]
            
            if isinstance(message, dict):
                image_str = message["image"]
                message = ""
            
            print("")
            print(f"[{device_name} {time}] {message}")
            
            try:
                imgdata = base64.b64decode(str(image_str))
                img = Image.open(BytesIO(imgdata))
                img.show()
            except NameError:
                pass
            
        except KeyError:
            print("")
            print(f"* {device_name} has joined the chat")

        print(f"[{DEVICE_NAME}] ", end="")


def send_image():
    image = photos.pick_photo()
    buffered = BytesIO()
    image.save(buffered, format="JPEG")
    img_str = base64.b64encode(buffered.getvalue()).decode("utf-8")
    
    data = {
        "device_name": DEVICE_NAME,
        "message": { "image": img_str },
        "time": datetime.now().strftime("%H:%M")
    }
    data = json.dumps(data)
    multipeer.send(data)


def main():
    multipeer.connect()
    
    listener_thread = threading.Thread(target=listen)
    listener_thread.start()
    
    multipeer.send(json.dumps({
        "device_name": DEVICE_NAME
    }))
    
    print("Commands: :image, :quit")
    
    try:
        while True:
            text = input(f"[{DEVICE_NAME}] ")
            
            if text == ":image":
                send_image()
                continue
            elif text == ":quit":
                multipeer.disconnect()
                break
            
            data = {
                "device_name": DEVICE_NAME,
                "message": text,
                "time": datetime.now().strftime("%H:%M")
            }
            data = json.dumps(data)
            multipeer.send(data)
    except (KeyboardInterrupt, SystemExit):
        multipeer.disconnect()
    

if __name__ == "__main__":
    main()

