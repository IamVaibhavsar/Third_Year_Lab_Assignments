/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 4
PROBLEM STATEMENT: Write a program using TCP socket for wired network for following
 Say Hello to each other (chat): client side */

#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80
#define PORT 43454
#define SA struct sockaddr
void func(int sockfd)
{
	char buff[MAX];
	int n;
	for(;;)
	{
		bzero(buff,sizeof(buff));
		printf("Enter the string : ");
		n=0;
		while((buff[n++]=getchar())!='\n');
		write(sockfd,buff,sizeof(buff));
		bzero(buff,sizeof(buff));
		read(sockfd,buff,sizeof(buff));
		printf("From Server : %s",buff);
		if((strncmp(buff,"exit",4))==0)
		{
			printf("Client Exit...\n");
			break;
		}
	}
}

int main()
{
	int sockfd,connfd;
	struct sockaddr_in servaddr,cli;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);
	if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0)
	{
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");
	func(sockfd);
	close(sockfd);
}
/*OUTPUT:
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Chat_server$ gcc client.c
client.c: In function ‘func’:
client.c:26:1: warning: implicit declaration of function ‘write’ [-Wimplicit-function-declaration]
 write(sockfd,buff,sizeof(buff));
 ^
client.c:28:1: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
 read(sockfd,buff,sizeof(buff));
 ^
client.c: In function ‘main’:
client.c:52:26: warning: implicit declaration of function ‘inet_addr’ [-Wimplicit-function-declaration]
 servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
                          ^
client.c:62:1: warning: implicit declaration of function ‘close’ [-Wimplicit-function-declaration]
 close(sockfd);
 ^
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/Chat_server$ ./a.out
Socket successfully created..
connected to the server..
Enter the string : hello
From Server : hello!!!
Enter the string : 

*/

