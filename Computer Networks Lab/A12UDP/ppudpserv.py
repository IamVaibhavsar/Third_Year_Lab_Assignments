'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 12
PROBLEM STATEMENT:
Write a program using UDP sockets for wired network to implement
a. Peer to Peer chat (server side)'''

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('', 10000))

msg, (ip, port) = sock.recvfrom(100)
print "client connected to ip: " + ip + " and port: " + str(port)
print "received message: " + msg
sock.sendto("Hello from server", (ip,port))



while True:    	
	msg, (ip, port) = sock.recvfrom(100)
	print "client connected to ip: " + ip + " and port: " + str(port)
	if "stop." in msg:
		break
	else:			
		print "client: " + msg
	
	msg = raw_input("you: ")
	sock.sendto(msg, (ip,port))
	if "stop." in msg:
		break
sock.close()
        
'''
root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 15/udp peer 2 peer# python ppudpserv.py 
client connected to ip: 127.0.0.1 and port: 47082
received message: Hi from client
client connected to ip: 127.0.0.1 and port: 47082
client: hi
you: stop.
root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 15/udp peer 2 peer# 


'''
