
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 



sock.connect(('127.0.0.1',23002)) #addind host ip and port nuSSSmber
str1="HI FROM CLIENT"
sock.send(str.encode(str1))
filename='abc.txt'
f= open(filename,'rb')
l=f.read(1024)
sock.send(l)
l=f.read(1024)
f.close()
print("WHOLE FILE SENT")
sock.close()




