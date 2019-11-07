/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 2
PROBLEM STATEMENT: Write a program for error detection and correction for 7/8 bits ASCII codes using CRC.*/

#include <iostream>
using namespace std;
int main()
{
    int i,j,k,l;
     
    //Get Frame
    int fs;
    cout<<"\n Enter Size of data: ";
    cin>>fs;
     
    int f[20];
     
    cout<<" Enter data:";
    for(i=0;i<fs;i++)
    {
        cin>>f[i];
    }
 
    //Get Generator
    int gs;
    cout<<"\n Enter key size: ";
    cin>>gs;
     
    int g[20];
     
    cout<<"\n Enter key:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }
 
    cout<<"\n Sender Side:";
    cout<<"\n data: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n key :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }
 
    //Append 0's
    int rs=gs-1;
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=fs;i<fs+rs;i++)
    {
        f[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    cout<<"\n Message after appending 0's :";
    for(i=0; i<fs+rs;i++)
    {
        cout<<temp[i];
    }
 
    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
 
    cout<<"\n Transmitted Frame: ";
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }
 
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
    
 	//Remainder
    cout<<"\n Remainder: ";
    int rrem[15];
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }
 
    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
      cout<<"\n Since Remainder is 0, Hence Message Transmitted from Sender to Receiver is correct";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0, Hence Message Transmitted from Sender to Receiver contains error";
    }
return 0;
}


/*
lenovo@lenovo:~/Desktop/CN Programs/CN_1/assignment2_CRC_Hamming$ ./a.out

 Enter Size of data: 6
 Enter data:1 0 0 1 0 0 

 Enter key size: 4

 Enter key:1 1 0 1 

 Sender Side:
 data: 100100
 key :1101
 Number of 0's to be appended: 3
 Message after appending 0's :100100000
 CRC bits: 001
 Transmitted Frame: 100100001
 Receiver side : 
 Received Frame: 100100001
 Remainder: 000
*/


