/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 5
PROBLEM STATEMENT: Write a program using UDP Sockets to enable file transfer (Script, Text, Audio and Video
one file each) between two machines.
 client side */
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
int main(int argc, char **argv){
	int sock; // client socket descriptor 
	struct sockaddr_in remote_server;	
	// send buffer: hold information to send to server
	char send_data[BUFFER]= "add.txt"; 
	// receive buffer: hold information to received from server
	char recv_data[BUFFER];	
	int sockaddr_len = sizeof(struct sockaddr_in); // socket address length
	int data_len; // store data length of send_data or recv_data length
	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1){	
		perror("socket error. ");
		exit(-1);
	}
	remote_server.sin_family = AF_INET; //IPv4
	remote_server.sin_port = htons(atoi(argv[2])); //htons: host to network short byte order, atoi: convert a string to an integer
	remote_server.sin_addr.s_addr = inet_addr(argv[1]); //inet_addr: function converts the Internet host address cp IPv4 numbers-and-dots notation into binary 									data in network byte order. 
	bzero(&remote_server.sin_zero , 8);// function sets the first 8 bytes of the area starting at &remote_server.sin_zero to zero 
	sendto(sock,send_data,sizeof(send_data),0,(struct sockaddr *)&remote_server,sockaddr_len);
	data_len = recvfrom(sock,recv_data,BUFFER, 0,(struct sockaddr *)&remote_server,&sockaddr_len);
	recv_data[data_len] = '\0';
printf("data received = %s \n", recv_data );
	FILE *fp;
	fp=fopen("add1.txt","w");
	fprintf(fp,"%s",recv_data);
	fclose(fp);
	close(sock);
	return 0;
}

/*
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A5 UDP Socket$ gcc ftclientudp.c 
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A5 UDP Socket$ ./a.out 127.0.0.1 8000
data received = Welcome to KKWIEER.
 
*/
