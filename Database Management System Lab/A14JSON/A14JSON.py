'''
NAME: VAIBHAV BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO 14: 
Create employee array objects containing employee id , name, designation, salary using json and write a program in python to read and display the employee information.
'''


import json

with open('dbms.json') as f:
    data = json.load(f)

def main():
    def displayAll():
        for i in range(len(data["Employee"])):
            for j,k in data["Employee"][i].items():
                print(j," : ",k)
            print('\n')

        return('Total Number of Records are {}'.format(len(data["Employee"])))
        
    def displayById():
        id_ = int(input('Enter the id'))
        flag = 0
        for i in range(len(data["Employee"])):
            if data["Employee"][i]["id"] == id_:
                flag = 1
                for j,k in data["Employee"][i].items():
                    print(j," : ",k)
                print('\n')
        return('Record Not Present \n\n ') if flag == 0 else ('Record Present')


    def insertNewRecord():
        global data
        newRecord = {}
        listOfIds = [i["id"] for i in data["Employee"]]
        id_= int(input('Enter the id number\n '))
        if id_ in listOfIds:
            return('Id Already Present\n ')
        else:
            newRecord["id"] = id_
            newRecord["name"] = input('Enter the name')
            newRecord["designation"] = input('Enter the Designation')
            newRecord["salary"] = int(input('Enter the Salary of the Employee'))
            newRecord["hobbies"] = input('Enter the hobbies\n').split()
            with open('dbms.json','w') as f1:
                data['Employee'].append(newRecord)
                json.dump(data,f1,indent=4)
                return('Record Inserted Successfully\n')

 
    boolvalue = True        
    while boolvalue:
        print('1. To display all data')
        print('2. To display by id')
        print('3. To insert a new Data')
        ch = input()
        print('\n')

        switcher = {
            "1":displayAll,
            "2":displayById,
            "3":insertNewRecord
        }
        try:
            fun = switcher[ch]
            print(fun())
        except TypeError:
            print('Enter a valid choice\n ')

        choice = input('Do you want to continue Y/N')

        boolvalue = True if choice in ['y','Y'] else False
        
        
main()
