/*
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 09
PROBLEM STATEMENT:
Implementation of IP spoofing assignments using c++ multicore programming
*/

#include<iostream>
#include <crafter.h>
/* Collapse namespaces */
using namespace std;
using namespace Crafter;
int main() 
{
        /* Set the interface */
        string iface = "eth0";
        /* Get the IP address associated to the interface */
       string MyIP = GetMyIP(iface);
 	cout << "[@] My IP address is  : " << MyIP  << endl;
        MyIP = "192.168.0.102";
        /* Create an IP header */
        IP ip_header;-
        /* Set the Source and Destination IP address */
        ip_header.SetSourceIP(MyIP);
        //ip_header.SetDestinationIP("www.google.com");
        ip_header.SetDestinationIP("192.168.0.102");
        /* Create an TCP - SYN header */
        TCP tcp_header;
        tcp_header.SetSrcPort(11);
        tcp_header.SetDstPort(80);
        tcp_header.SetSeqNumber(RNG32());/*0 to 2^32 bit random nuber assign*/
        tcp_header.SetFlags(TCP::SYN);/*tcp syn flag 1 set out of 6 flag*/
        /* A raw layer, this could be any array of bytes or chars */
        RawLayer payload("ArbitraryPayload");/* extra layer for row packet*/
        /* Create a packets */
        Packet tcp_packet = ip_header/tcp_header/payload;
        cout << endl << "[@] Print before sending: " << endl;
        tcp_packet.Print();
        /* Write the packet on the wire */
        tcp_packet.Send();
        cout << endl << "[@] Print after sending: " << endl;
        tcp_packet.Print();
        return 0;
}
/*
output:
unix@unix-HP-280-G1-MT ~/Desktop $ g++ ip_spoofing.cpp -lcrafter
unix@unix-HP-280-G1-MT ~/Desktop $ sudo ./a.out
[@] My IP address is  : 192.168.20.82

[@] Print before sending: 
< IP (20 bytes) :: Version = 4 , HeaderLength = 5 , DiffServicesCP = 0 , ExpCongestionNot = 0 , TotalLength = 0 , Identification = 0x0 , Flags = 2 , FragmentOffset = 0 , TTL = 64 , Protocol = 0x6 , CheckSum = 0x0 , SourceIP = 192.168.0.102 , DestinationIP = 192.168.0.102 , >
< TCP (20 bytes) :: SrcPort = 11 , DstPort = 80 , SeqNumber = 3618782368 , AckNumber = 0 , DataOffset = 5 , Reserved = 0 , Flags = ( SYN ) , WindowsSize = 5840 , CheckSum = 0x0 , UrgPointer = 0 , >
< RawLayer (16 bytes) :: Payload = ArbitraryPayload>

[@] Print after sending: 
< IP (20 bytes) :: Version = 4 , HeaderLength = 5 , DiffServicesCP = 0 , ExpCongestionNot = 0 , TotalLength = 56 , Identification = 0x0 , Flags = 2 , FragmentOffset = 0 , TTL = 64 , Protocol = 0x6 , CheckSum = 0xb8a3 , SourceIP = 192.168.0.102 , DestinationIP = 192.168.0.102 , >
< TCP (20 bytes) :: SrcPort = 11 , DstPort = 80 , SeqNumber = 3618782368 , AckNumber = 0 , DataOffset = 5 , Reserved = 0 , Flags = ( SYN ) , WindowsSize = 5840 , CheckSum = 0xdfd9 , UrgPointer = 0 , >
< RawLayer (16 bytes) :: Payload = ArbitraryPayload>
*/oblem Statement:
