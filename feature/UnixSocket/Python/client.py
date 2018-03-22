import os
import socket

SOCKET_FILE = './echo.socket'

print("Connection...")
if os.path.exists(SOCKET_FILE):
    client = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
    client.connect(SOCKET_FILE)
    print("Connection done.")
    print("Ctrl-C to EXIT.")
    print("Send 'DONE' for server Off.")
    while True:
        try:
            x = raw_input("> ")  # for py2 use raw_input
            if "" != x:
                print("Sent: %s" % x)
                client.send(x.encode('utf-8'))
                if "DONE" == x:
                    print("Shutdown.")
                    break
        except KeyboardInterrupt as k:
            print("Shutdown.")
            break
    client.close()
else:
    print("Cant connect!")
print("Done")
