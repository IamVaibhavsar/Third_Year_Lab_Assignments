/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 5
PROBLEM STATEMENT: Write a program using UDP Sockets to enable file transfer (Script, Text, Audio and Video
one file each) between two machines.
 server side */
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<error.h>
#define ERROR -1
#define BUFFER 1024
#define MAX_CLIENTS 2
int main(int argc, char **argv)
{
	int sock, cli; // sock: server socket descriptor, cli: client socket descriptor
	struct sockaddr_in server, client;
	char send_data[BUFFER]= "Hello"; // send buffer: hold information to send to client
	char recv_data[BUFFER]; // receive buffer: hold information to received from client
	int sockaddr_len = sizeof(struct sockaddr_in); // socket address length
	int data_len; // store data length of send_data or recv_data length   
	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{	
		perror("socket error. ");
		exit(-1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero , 8);
	if((bind(sock, (struct sockaddr *)&server, sockaddr_len)) == -1)
	{
		perror("bind error");	
		exit(-1);
	}
//	recvfrom(listenfd,buff,buffsize,0, (struct sockaddr *) &clientaddr, &sin_size) != buffsize)		  
	data_len = recvfrom(sock,recv_data,BUFFER, 0,(struct sockaddr *)&client,&sockaddr_len);
	printf("New client connected to port: %d and IP %s \n", ntohs(client.sin_port), inet_ntoa(client.sin_addr));
	recv_data[data_len] = '\0';
	FILE *f;
	f=fopen(recv_data,"r");
	fgets(send_data,BUFFER,f);
	fclose(f);
	sendto(sock,send_data,strlen(send_data),0,(struct sockaddr *)&client,sockaddr_len);
	printf("data received = %s \n", recv_data );
	close(sock);
	return 0;
}

/*
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A5 UDP Socket$ gcc ftserverudp.c 
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A5 UDP Socket$ ./a.out 8000
New client connected to port: 37969 and IP 127.0.0.1 
data received = add.txt*/




