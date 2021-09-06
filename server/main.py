import socket

import keyboard
from flask import Flask, request


app = Flask(__name__)

@app.route('/shortcut', methods=['POST'])
def shortcut():
    """
    The JSON must contain a 'command' key, and one of the following values:
    - 'minimize_all': windows + d
    - 'mute_unmute_meet': ctrl + d
    """
    data = request.get_json()
    if not data.get('command', False):
        return {
            "success": False,
            "message": "send command name in 'command' field"
        }
    if data.get('command') == 'minimize_all':
        keyboard.press_and_release('windows+d')
    elif data.get('command') == 'mute_unmute_meet':
        keyboard.press_and_release('ctrl+d')
    else:
        return {"success": False, "message": "command not found"}
    return {"success": True}


if __name__ == '__main__':
    # Get local IP, and show it on run
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(('8.8.8.8', 1))
    local_ip = s.getsockname()[0]
    print(f"* Server running on: {local_ip}")
    app.run(host='0.0.0.0')
