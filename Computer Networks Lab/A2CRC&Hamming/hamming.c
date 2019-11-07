/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO : 2
PROBLEM STATEMENT: Write a program for error detection and correction for 7/8 bits ASCII codes using Hamming codes */


#include<stdio.h>
void main() 
{
    int data[10];
    int dataatrec[10],c,c1,c2,c3,i;
 
    printf("Enter 4 bits of data one by one\n");
    scanf("%d",&data[2]);
    scanf("%d",&data[4]);
    scanf("%d",&data[5]);
    scanf("%d",&data[6]);
 
    //Calculation of even parity
    data[0]=data[2]^data[4]^data[6];
    data[1]=data[2]^data[5]^data[6];
    data[3]=data[4]^data[5]^data[6];
 
    printf("\nEncoded data is\n");
    for(i=0;i<7;i++)
        printf("%d\t",data[i]);
 
    printf("\n\nEnter received data bits one by one\n");
    for(i=0;i<7;i++)
        scanf("%d",&dataatrec[i]);
    //Calculation of parity to check error on receiver side
    c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
    c2=dataatrec[6]^dataatrec[5]^dataatrec[2]^dataatrec[1];
    c3=dataatrec[6]^dataatrec[5]^dataatrec[4]^dataatrec[3];
    c=c3*4+c2*2+c1 ;
 
    if(c==0)
    {
        printf("\nNo error while transmission of data\n");
    }//if
    else 
    {
        printf("\nError on position %d",c);
        
        printf("\nData sent : ");
        for(i=0;i<7;i++)
            printf("%d",data[i]);
        
        printf("\nData received : ");
        for(i=0;i<7;i++)
            printf("%d",dataatrec[i]);
        
        printf("\nCorrect message is\n");
 
        //if errorneous bit is 0 we complement it else vice versa
        if(dataatrec[c-1]==0)
            dataatrec[c-1]=1;
        else
            dataatrec[c-1]=0;
        
        for (i=0;i<7;i++) 
        {
            printf("%d\t",dataatrec[i]);
        }
    }//else
}// main

/*lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A2CRC&Hamming$ gcc hamming.c
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A2CRC&Hamming$ ./a.out
Enter 4 bits of data one by one
1 1 0 1

Encoded data is
1	0	1	0	1	0	1	

Enter received data bits one by one
1 0 1 0 0 0 1

Error on position 5
Data sent : 1010101
Data received : 1010001
Correct message is
1	0	1	0	1	0	1	lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A2CRC&Hamming$ 
*/

