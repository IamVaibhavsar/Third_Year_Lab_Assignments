/*NAME: VAIBHAV BHAVSAR
TE-B
ROLL NO: 08
ASSIGNMENT NO 09: 
Create a database with following schemas in mysql   - Group C
Student(Roll,Name,Deptid)  
Write a menu driven program in Java/Python  to connect with a database using Jdbc-Odbc Connectivity 
1. to display the student’s details,            2. to insert the student’s details
3. to Update students record                    4. to delete a student record */


import java.io.*;
import java.util.Scanner;
import java.sql.*;
class MysqlCon{
//__________________________________________________________________________________________________
	public void Display(){
		try{
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ass5","TEBsakshi","sakshi2019");
			Statement stmt=con.createStatement();
			ResultSet rs=stmt.executeQuery("select * from Student_Data");
			while(rs.next())				
			System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getInt(3)+" "+rs.getString(4));
			con.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
//__________________________________________________________________________________________________	
	public void Insert(int i1,String nm,int i2,String ct){
		try{
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ass5","TEBsakshi","sakshi2019");
			String query = "insert into Student_Data (Student_Id,Student_Name,Instructor_Id,Student_City)" + " values("+i1+",'"+nm+"',"+i2+",'"+ct+"')";
			PreparedStatement pstmt=con.prepareStatement(query);
			pstmt.execute();
			//Statement stmt=con.createStatement();
			//stmt.executeUpdate("insert into Student_Data values(21,'Apurva',4,'Pune');");
			con.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
//________________________________________________________________________________________________
	public void Update(){
		try{
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ass5","TEBsakshi","sakshi2019");
			Statement stmt=con.createStatement();
			ResultSet rs=stmt.executeQuery("update Student_Data set Student_Name='Aarti' where Student_Id=18");
			//while(rs.next())				
			//System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getInt(3)+" "+rs.getString(4));
			con.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
		
//________________________________________________________________________________________________
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		MysqlCon obj1=new MysqlCon();
		int ch;
		String n1,c1;
		int id1,id2;
		do
		{
			System.out.println("--------------------------------------------");
			System.out.println("	1.Display all Records");
			System.out.println("	2.Insert new Record");
			//System.out.println("	3.Update a Record");
			System.out.println("	4.Delete a Record");
			System.out.println("	5.Exit");
			System.out.println("--------------------------------------------");
			System.out.println("	Enter your Choice");
			ch=sc.nextInt();
			switch(ch){
				case 1: obj1.Display();
					break;
				case 2: System.out.println("Enter Student Id: ");
					id1=sc.nextInt();
					System.out.println("Enter Student Name: ");
					n1=sc.next();
					System.out.println("Enter Instructor Id: ");
					id2=sc.nextInt();
					System.out.println("Enter Student City: ");
					c1=sc.next();
					obj1.Insert(id1,n1,id2,c1);
					break;
				//case 3: obj1.Update();
				//	break;
			}
		}while(ch!=5);
		
	}
}
