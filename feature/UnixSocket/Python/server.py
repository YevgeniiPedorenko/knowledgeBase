import os
import socket

SOCKET_FILE = './echo.socket'

if os.path.exists(SOCKET_FILE):
    os.remove(SOCKET_FILE)

print("Open UNIX socket...")
server = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
server.bind(SOCKET_FILE)

print("Listen...")
while True:
    datagram = server.recv(1024)
    if not datagram:
        break
    else:
        print("-" * 20)
    print(datagram)
    if "DONE" == datagram:
        break
print("-" * 20)
print("Shutdown...")
server.close()
os.remove(SOCKET_FILE)
print("Done")
