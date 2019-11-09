'''
NAME: VAIBHAV BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO 15: 
   Write a menu driven program in python to connect with the database  and to perform the following operation
    1. Insert details of the student
    2. Update the address of John to Dwarka
    3. Display the students information
    4. Delete a student’s record
'''


import pymongo				#pip install pymongo
client=pymongo.MongoClient()
db=client.TEB08		#database name
def menu():
	print 'Menu:\n'
	print '1.Insert.\n'
	print '2.Update.\n'
	print '3.Delete.\n'
	print '4.Display.\n'
	print '5.Exit.\n'
	return input('Enter your choice : \n')
loop=1			#always true
choice=0		#initially choice set to 0
while loop==1:
	choice=menu()
	if choice==1:
		roll=input('Enter the Roll No. :\n')
		name=raw_input('Enter the name :\n')
		add=raw_input('Enter the address :\n')
		cont=input('Enter the contact no. :\n')
		dept=raw_input('Enter the Department :\n')
		db.student.insert({'Rollno':roll,'Name':name,'Address':add,'Contact':cont,'Dept':dept})
		print '\nINSERTED.\n'
	elif choice==2:
		nme=raw_input('\nEnter the name whose address you want to update:\n')
		addr=raw_input('Enter the new address :\n')
		db.student.update({'Name':nme},{'$set':{'Address':addr}})
		print '\nUPDATED.\n'
	elif choice==3:
		rno=input('\nEnter the roll no. that you want to delete:\n')
		db.student.remove({'Rollno':rno})
		print '\nDELETED.\n'
	elif choice==4:
		for item in db.student.find():
			print item
	elif choice==5:
		exit()
		

