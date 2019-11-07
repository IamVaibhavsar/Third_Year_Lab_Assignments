
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # create socket object

sock.bind(('',23002)) #bind to the port

sock.listen(100) # server is in the listening mode        listen(backlog)  backlog = queue of connection

clisock, addr = sock.accept() # establishing connecton with client
data = clisock.recv(16)
data1=data.decode('utf-8')
			
print ("client: " + data1)
f = open("kkwieer.txt",'w')
data1 = clisock.recv(1024)
#clisock.send(str.encode(data))
f.write(data1)
f.close()
sock.close()
            
