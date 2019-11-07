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

sock.bind(('localhost',23000))

sock.listen(1)

clisock, (ip,port) = sock.accept()

while True:    	
		
	data = clisock.recv(16)
	op = data.decode()
	data = clisock.recv(16)
	v1 = data.decode()
	data = clisock.recv(16)
	v2 = data.decode()

	print(op,v1,v2)
	w1=int(v1)
	w2=int(v2)

	if(op=='+'):
		res=w1+w2
		clisock.send(str.encode(str(res)))
		
		
	if(op=='-'):
		res=w1-w2
		clisock.send(str.encode(str(res)))	
			

sock.close()
            

