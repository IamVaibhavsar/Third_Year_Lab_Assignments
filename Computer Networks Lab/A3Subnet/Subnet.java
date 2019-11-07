/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 3
PROBLEM STATEMENT: Write a program to demonstrate subnetting and find the subnet masks */

import java.util.Scanner;
class Subnet
{
public static void main(String args[])
{
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter the ip address: ");
	String ip = sc.nextLine();
	String split_ip[] = ip.split("\\."); //Split the string after every .
	String split_bip[] = new String[4]; //split binary ip
	String bip = "";
	System.out.println("IP Address in binary is"); 

	for(int i=0;i<4;i++)
	{
		split_bip[i] = appendZeros(Integer.toBinaryString(Integer.parseInt(split_ip[i]))); 
// "18" => 18 => 10010 => 00010010
		System.out.println(split_bip[i]);
		bip += split_bip[i];
	}

	System.out.print("Enter the number of addresses: ");
	int n = sc.nextInt();

//Calculation of mask
	int bits = (int)Math.ceil(Math.log(n)/Math.log(2)); 
/*eg if address = 120, log 120/log 2 gives log to the base 2 => 6.9068, ceil gives us upper integer */
	System.out.println("Number of bits required for address = "+bits);
	int mask = 32-bits;
	System.out.println("The subnet mask is = "+mask);
	
//Calculation of first address and last address
	int fbip[] = new int[32];
	for(int i=0; i<32;i++) 
		fbip[i] = (int)bip.charAt(i)-48; 
//convert cahracter 0,1 to integer 0,1
	for(int i=31;i>31-bits;i--)
//Get first address by ANDing last n bits with 0
		fbip[i] &= 0;
		String fip[] ={"","","",""};
	for(int i=0;i<32;i++)
		fip[i/8] = new String(fip[i/8]+fbip[i]);
		System.out.print("Subnet address is = ");
	for(int i=0;i<4;i++)
	{
		System.out.print(Integer.parseInt(fip[i],2));
		if(i!=3) 
			System.out.print(".");
	}
	System.out.println();

	int lbip[] = new int[32];
	for(int i=0; i<32;i++) 
		lbip[i] = (int)bip.charAt(i)-48; 
//convert cahracter 0,1 to integer 0,1
	for(int i=31;i>31-bits;i--)
//Get last address by ORing last n bits with 1
		lbip[i] |= 1;
		String lip[] = {"","","",""};
	for(int i=0;i<32;i++)
		lip[i/8] = new String(lip[i/8]+lbip[i]);
		System.out.print("Broadcast address is = ");
	for(int i=0;i<4;i++)
	{
		System.out.print(Integer.parseInt(lip[i],2));
		if(i!=3) 
			System.out.print(".");
	}
	System.out.println();
}

static String appendZeros(String s)
{
	String temp = new String("00000000");
	return temp.substring(s.length())+ s;
}
}


/****************OUTPUT*****************

Enter the ip address: 192.168.3.254
IP in binary is 11000000101010000000001111111110
Enter the number of addresses: 4
Number of bits required for address = 2
The subnet mask is = 30
Subnet address is = 192.168.3.252
Broadcast address is = 192.168.3.255

*/

