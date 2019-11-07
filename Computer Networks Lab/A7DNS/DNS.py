'''
NAME: VAIBHAV SUDHAKAR BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO: 7
PROBLEM STATEMENT:
Write a program for DNS lookup. Given IP address input, 
it should return URL and vice-versa    '''

import socket
choose=True
while choose:
        
        print("\n Menu\n 1.Get host by name \n 2.Get host by address \n 3.Quit")
        choose=input(" \n Enter your choice: ")
        
        if choose=="1":
                a=input(" \n Enter URL: ")
                addr1=socket.gethostbyname(a)
                print("IP address is:",addr1)
        
        elif choose=="2":
               b=input("\n Enter IP :  ")
               addr2=socket.gethostbyaddr(b)
               print("URL is:",addr2)
        
        elif choose=="3":
               exit()
        
        else:
                print("\n Invalid choice,please try again \n")
        
        

""" ************OUTPUT************
kkw@kkw-HP-280-G2-MT-Legacy:~/assignment_7$ python3 dns.py

 Menu
 1.Get host by name 
 2.Get host by address 
 3.Quit
 
 Enter your choice: 1
 
 Enter URL: www.facebook.com
IP address is: 157.240.16.35

 Menu
 1.Get host by name 
 2.Get host by address 
 3.Quit
 
 Enter your choice: 2

 Enter IP :  157.240.16.35
URL is: ('edge-star-mini-shv-01-bom1.facebook.com', [], ['157.240.16.35'])

 Menu
 1.Get host by name 
 2.Get host by address 
 3.Quit
 
 Enter your choice: 3
kkw@kkw-HP-280-G2-MT-Legacy:~/assignment_7$ 

 

"""
        
        
        

