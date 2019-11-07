'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 12
PROBLEM STATEMENT:
Write a program using UDP sockets for wired network to implement
a. Peer to Peer chat (client side)'''

import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto("Hi from client", ('', 10000))
while True:    	
	msg, (ip, port) = sock.recvfrom(100)

	if "stop." in msg:
		break
	else:			
		print "server: " + msg
	
	msg = raw_input("you: ")
	sock.sendto(msg, (ip,port))
	if "stop." in msg:
		break
sock.close()

'''
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL 1/assignment 15/udp peer 2 peer$ sudo su
[sudo] password for res: 
root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 15/udp peer 2 peer# python ppudpcli.py 
server: Hello from server
you: hi
root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 15/udp peer 2 peer# 

'''
