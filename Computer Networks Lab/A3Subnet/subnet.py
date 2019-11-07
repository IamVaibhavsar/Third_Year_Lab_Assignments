'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 3
PROBLEM STATEMENT: Write a program to demonstrate subnetting and find the subnet masks '''

import math
ip = input("Enter IP address: ")
n = int(input("Enter no of addresses: "))
bits = math.ceil(math.log(n,2))
print("Number of bits : {} ".format(bits))
mask = 32-bits
addr = ip.split('.')
binary_ip = ""
for ip in addr:
	b = bin(int(ip))[2:]		
	#s=bin(n) 
	#s1=s[2:]  to remove the 0b prefix
	b = b.zfill(8)		#returns a copy of the string with '0' characters padded to the leftside.
	binary_ip+=b
print("Binary IP is :" + binary_ip)
print("Subnet mask is (CIDR) : {} ".format(mask))
bip = []
for c in binary_ip:
	bip.append(int(c))
for i in range(31,31-bits,-1):
	bip[i]&=0
nums = []
for i in range(0,32,8):
	nums.append(int(''.join([str(x) for x in bip[i:i+8]]),2))
print("(Staring address)Network ID is : {}".format('.'.join([str(x) for x in nums])))

bip = []
for c in binary_ip:
        bip.append(int(c))
for i in range(31,31-bits,-1):
        bip[i]|=1
nums = []
for i in range(0,32,8):
        nums.append(int(''.join([str(x) for x in bip[i:i+8]]),2))
print("(Ending address)Broadcast ID is : {}".format('.'.join([str(x) for x in nums])))

'''
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A3Subnet$ python3 subnet.py 
Enter IP address: 192.168.3.254     
Enter no of addresses: 7
Number of bits : 3 
Binary IP is :11000000101010000000001111111110
Subnet mask is (CIDR) : 29 
(Staring address)Network ID is : 192.168.3.248
(Ending address)Broadcast ID is : 192.168.3.255
lenovo@lenovo:~/Desktop/CN Programs/Computer Networks Lab/A3Subnet$'''


