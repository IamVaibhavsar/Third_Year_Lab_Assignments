/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 4
PROBLEM STATEMENT: Write a program using TCP socket for wired network for following
 Calculator (Arithmetic) : client side */

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
	
	int sock; // client socket descriptor 

	struct sockaddr_in remote_server;	

	char send_data[BUFFER]= "hi from lalit"; // send buffer: hold information to send to server
	char recv_data[BUFFER];	// receive buffer: hold information to received from server

	int sockaddr_len = sizeof(struct sockaddr_in); // socket address length
	int data_len; // store data length of send_data or recv_data length   
	
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{	
		perror("socket error. ");
		exit(-1);
	}

	remote_server.sin_family = AF_INET; //IPv4
	remote_server.sin_port = htons(atoi(argv[2])); //htons: host to network short byte order, atoi: convert a string to an integer
	remote_server.sin_addr.s_addr = inet_addr(argv[1]); //inet_addr: function converts the Internet host address cp IPv4 numbers-and-dots notation into binary 									data in network byte order. 
	bzero(&remote_server.sin_zero , 8);// function sets the first 8 bytes of the area starting at &remote_server.sin_zero to zero 

	if((connect(sock, (struct sockaddr*)&remote_server, sockaddr_len)) == -1)
	{
		perror("connect error");
		exit(-1);
	}	
	
	

	printf("\nEnter Operator: ");
	scanf("%c", &operator);

	printf("\nEnter value of n1: ");
	scanf("%d",&n1);

	printf("\nEnter value of n2: ");
	scanf("%d",&n2);

	write(sock,&n1,sizeof(n1));
	write(sock,&n2,sizeof(n2));
	write(sock,&operator,sizeof(operator));

	int ret1 = read(sock,&res,sizeof(res));
	printf("FROM SERVER:%d \t Bytes=%d\n",res,ret1);

	close(sock);
	return 0;
}


/*
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Calculator$  sudo ./a.out 127.0.0.1 5122 47304

Enter Operator: *

Enter value of n1: 5

Enter value of n2: 4
FROM SERVER:20 	 Bytes=4
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Calculator$ 
*/


