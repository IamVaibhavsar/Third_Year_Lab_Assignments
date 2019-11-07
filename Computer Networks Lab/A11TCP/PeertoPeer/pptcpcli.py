'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 11
PROBLEM STATEMENT:
Write a program using TCP sockets for wired network to implement
a. Peer to Peer Chat  (client side)

'''

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(('127.0.0.1',23000))
byt = str.encode("hi from client")
sock.send(byt)

while True:
	
	data = sock.recv(16)
	dt = data.decode()
	if "stop."==dt :
		break
	else:			
		print("server: " + dt)

	data = input("you: ")
	data = str.encode(data)
	sock.send(data)
	if "stop."==data.decode():
		break
sock.close()


'''
root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 14/tcp peer 2 peer# python pptcpcli.py 
server: hello!
you: hi
server: STOP.
you: stop.
root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 14/tcp peer 2 peer# 


'''

