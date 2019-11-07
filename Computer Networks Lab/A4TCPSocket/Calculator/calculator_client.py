'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 4
PROBLEM STATEMENT: Write a program using TCP socket for wired network for following
 Calculator (Arithmetic) : client side '''

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(('127.0.0.1',23000))


while True:

	op=input("ENter the operator")
	sock.send(str.encode(op))
	v=input("Enter the first NO")
	sock.send(str.encode(v))
	v2=input("secnd variable")
	sock.send(str.encode(v2))
	
	data = sock.recv(16)
	dt = data.decode()
	print(dt)
	if "stop."==dt :
		break
	else:			
		print("server: " + dt)

sock.close()



