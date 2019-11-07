'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 11
PROBLEM STATEMENT:
Write a program using TCP sockets for wired network to implement
a. Multi chat (client side)
'''

import sys, socket, select
 
def chat_client():
    if(len(sys.argv) < 3) :
        print 'Usage : python chat_client.py hostname port'
        sys.exit()

    host = sys.argv[1]
    port = int(sys.argv[2])
     
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(2)
     
    # connect to remote host
    try :
        s.connect((host, port))
    except :
        print 'Unable to connect'
        sys.exit()
     
    print 'Connected to remote host. You can start sending messages'
    sys.stdout.write('[Me] '); sys.stdout.flush()
     
    while 1:
        socket_list = [sys.stdin, s]
         
        # Get the list sockets which are readable
        read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])
         
        for sock in read_sockets:            
            if sock == s:
                # incoming message from remote server, s
                data = sock.recv(4096)
                if not data :
                    print '\nDisconnected from chat server'
                    sys.exit()
                else :
                    #print data
                    sys.stdout.write(data)
                    sys.stdout.write('[Me] '); sys.stdout.flush()     
            
            else :
                # user entered a message
                msg = sys.stdin.readline()
                s.send(msg)
                sys.stdout.write('[Me] '); sys.stdout.flush() 

if __name__ == "__main__":

    sys.exit(chat_client())
'''
client 1:: on 1st terminal

root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 14/Multi_Chat_server# python chat_client.py 127.0.0.1 9008
Connected to remote host. You can start sending messages
[Me] hello
[('127.0.0.1', 33670)] hi
[Me] 



client 2::on 2nd terminal

root@res-HP-280-G2-MT-Legacy:/home/res/Desktop/FINAL 1/assignment 14/Multi_Chat_server# python chat_client.py 127.0.0.1 9008
Connected to remote host. You can start sending messages
[Me] [127.0.0.1:33672] entered our chatting room
[('127.0.0.1', 33672)] hello
[Me] hi
[Me] 

'''
