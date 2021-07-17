#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
string fname,lname,phone_no;
void Add_contact();
bool check_no(string);
bool check_digit(string);
void Search_contact();
void Display_all_contact();
void Delete_contact();
void Self_Exit();
void Help();
int main()
{
    int choice;
    system("cls");
    system("color A4");
//    cout<<"   ****Welcome to contact system,where you can do following activity***";
    
	cout<<"\n   ****Please Enter integer as a your choice***:\n1:for add contact \n2:for display all contact \n3:for search \n4:for delete \n5:for Help \n6:for exit"<<endl;
	cout<<"   ****Welcome to contact system,where you can do following activity***\n:";
	cin>>choice;
    if(choice>0 && choice<=6)
    {
	switch(choice)
	{
		case 1:Add_contact();
		       break;
		case 2:Display_all_contact();
		       break;
		case 3:Search_contact();
		       break;
		case 4:Delete_contact();
		       break;
		case 5:Help();
		       break;
		case 6:Self_Exit();
		       break;
		default:
			cout<<"invalid input!";
			cout<<"\nPress any key to continue";
			getch();
			main();
	}
    }
	else
	  {
	  	cout<<"put integer between 1 to 6";
	  	getch();
	  	main();
	  }
	return 0;
}
void Add_contact()
{
	ofstream of("lap.txt",ios::app);
	system("cls");
	cout<<"\nEnter first name:";
	cin>>fname;
	cout<<"Enter last name: ";
	cin>>lname;
	cout<<"Enter mobile no:";
	cin>>phone_no;
	if(check_digit(phone_no)==true)
	{
		if(check_no(phone_no)==true)
		{
			if(of.is_open())
			{
				of<<fname<<" "<<lname<<"\n"<<phone_no<<endl;
				cout<<"Contact save succesfully";
				getch();
			}
			else
			    cout<<"File cant open";
		}
		else
		{
			cout<<"************no.contain only digit********"<<endl;
	        getch();
	    }
	}
	else
	{
		cout<<"********No,have 10 digit only*******"<<endl;
	    getch();
	}
of.close();
getch();	
main();	
}
bool check_digit(string x)
{
	if(x.length()==10)
	  return true;
	else
	  return false;
}
bool check_no(string x)
{
   bool check=true;
   for(int i=0;i<x.length();i++)
   {
      if(!(int (x[i]>=48) && int (x[i]<=57)))
       {
   	     check=false;
       }
   }
   if(check==true)
   {
   	return true;
   }
   else
    return false;
}
void Search_contact()
{
	bool f=false;
	ifstream myfile("lap.txt");
	string key;
	cout<<"\nEnter contact to search:";
	cin>>key;
	while(myfile>>fname>>lname>>phone_no)
	{
		if(key==fname || key==lname)
		{
			f=true;
			cout<<"\n Contact found"<<endl;
			cout<<fname<<" "<<lname<<"\n"<<phone_no;
			break;
		}
	}
	if(f=false)
	{
		cout<<"\n No such contact found"<<endl;
	}
	myfile.close();
	getch();
	main();
}
void Display_all_contact()
{
   	ifstream myfile("lap.txt");
   	cout<<"\n Contact details:";
   	while(myfile>>fname>>lname>>phone_no)
   	{
   		cout<<fname<<" "<<lname<<"\n"<<phone_no<<endl;
	}
	myfile.close();
	getch();
	main();
}
void Delete_contact()
{
	ifstream myfile("lap.txt");
	ofstream of("copy.txt");
	string key;
	bool f=false;
	cout<<"Enter the contact that u want to delete:"<<endl;	
	cin>>key;
	system("cls");
	while(myfile>>fname>>lname>>phone_no)
	{
		if(!(key==fname || key==lname))
		{
			of<<fname<<" "<<lname<<"\n"<<phone_no<<endl;
		}
	}	
	myfile.close();
	of.close();
	
	ofstream of1("lap.txt");
	ifstream myfile2("copy.txt");
	while(myfile2>>fname>>lname>>phone_no)
    {		
	 of1<<fname<<" "<<lname<<"\n"<<phone_no<<endl;
	
    }
    of1.close();
    myfile2.close();
	getch();
	main();
}
void Help()
{
	cout<<"\nIts programme to add contact,display all contact ,search contact,delete contact.";
	cout<<"\nYou have toenter the choices as per the requirement."<<endl;
	main();
}

void Self_Exit()
{
	cout<<"Thanks for using my service,wish you a bright future.";
	exit(1);
	
}
