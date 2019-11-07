/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 4
PROBLEM STATEMENT: Write a program using TCP socket for wired network for following
 Calculator (Arithmetic) : server side */
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
	int n1,n2,res=0;
	char operator;
	
	int sock, cli; // sock: server socket descriptor, cli: client socket descriptor
	struct sockaddr_in server, client;

	char send_data[BUFFER]= "Hello from lalit"; // send buffer: hold information to send to client
	char recv_data[BUFFER]; // receive buffer: hold information to received from client

	int sockaddr_len = sizeof(struct sockaddr_in); // socket address length
	int data_len; // store data length of send_data or recv_data length   

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
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
	
	if((listen(sock,10)) == -1)
	{
		perror("listen error");
		exit(-1);
	}	

	while(1)
	{
		if((cli = accept(sock, (struct sockaddr*)&client, &sockaddr_len )) == -1)
		{
			perror("accept error");
			exit(-1);			
		}
	
		printf("New client connected to port: %d and IP %s \n", ntohs(client.sin_port), inet_ntoa(client.sin_addr)); //  inet_ntoa: network byte order, to a string in IPv4 dotted-decimal notation.
		



		read(cli,&n1,sizeof(n1));
		read(cli,&n2,sizeof(n2));
		read(cli,&operator,sizeof(operator));

		switch(operator)
		{
			case '+': res=n1+n2;
			break;
			case '-': res=n1-n2;
			break;
			case '*': res=n1*n2;
			break;
			case '/': res=n1/n2;
			break;
			default:
			printf("invalid operation\n");
		}

		printf("From CLIENT:n1=%d\n",n1);
		printf("From CLIENT:n2=%d\n",n2);
		printf("From CLIENT:operator=%c\n",operator);  
   
		int b=write(cli,&res,sizeof(res));

		close(cli);
	}
	close(sock);
	return 0;
}

/*

res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Calculator$ gcc arithserver.c 
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Calculator$ sudo ./a.out 5122 47304

New client connected to port: 47304 and IP 127.0.0.1 
From CLIENT:n1=5
From CLIENT:n2=4
From CLIENT:operator=*

*/
