#include "matthew.h"
#define NEW "NEW"
#define GUEST "GUEST"
#define MAX 10
int mangermenu();
int menu();
void loading();
int login();
int error();
int manger();
int mangermenu();
void employee(int num);
int employeemenu();
int customers();
int customersmenu();
int addaccount();
int editaccount(int num);
int removeaccount();
int addcustomer();
int logoff();
struct account
{
	char firstname[30],
		lastname[30],
		password[30],
		email[30],
		phonenumber[10];
	int accounttype;
};
void loading()//the loading screen
{
	int num;
	unsigned int seed=(unsigned int)time(NULL);
	srand(seed);
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0;
	system("cls");
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\n\n\t\t\t\t";
	SetConsoleTextAttribute(hConsole, 55);
	cout << "***";
	SetConsoleTextAttribute(hConsole, 63);
	cout << "LOADING";
	SetConsoleTextAttribute(hConsole, 55);
	cout << "***";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\t\t\t\t";
	SetConsoleTextAttribute(hConsole, 255);
	for(i=0;i<13;i++)
	{
		num=rand() % 501+500;//Finds a random time between .5 and 1 second
		cout << "-";
		Sleep(num);
	}
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\t\t\t\t";
	SetConsoleTextAttribute(hConsole, 71);
	cout << "*";
	SetConsoleTextAttribute(hConsole, 79);
	cout << "PRESS ENTER";
	SetConsoleTextAttribute(hConsole, 71);
	cout << "*";
	_getch();
	SetConsoleTextAttribute(hConsole, 15);
}
int lognin()
{
	int flag = 1;
	int l,		
		num=0;
	FILE *file1;
	string first_name, last_name, password = "";
	HANDLE hConsole;
	account info;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	do
	{
		file1=fopen("accounts.txt","r");
		flag = 1;
		system("cls");
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";
        SetConsoleTextAttribute(hConsole, 63);
		cout << "---MOORES Clothing for men---\n\n";                                                   
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\tEnter 'NEW' to create a new account\n";
		cout << "\t\tEnter 'GUEST' to log in as guest\n\n";
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\t\t";
		SetConsoleTextAttribute(hConsole, 79);
		cout << "First name:";
		SetConsoleTextAttribute(hConsole, 1);
		cout << " ";
		SetConsoleTextAttribute(hConsole, 240);
		getchar();
		getline(cin,first_name);
		if (first_name==NEW)
		{
			SetConsoleTextAttribute(hConsole, 15);
			addcustomer();
		}
		if (first_name != GUEST && first_name != NEW)
		{			
			SetConsoleTextAttribute(hConsole, 1);
			cout << "\n\t\t";
			SetConsoleTextAttribute(hConsole, 79);
			cout << "Last name:";
			SetConsoleTextAttribute(hConsole, 1);
			cout << " ";
			SetConsoleTextAttribute(hConsole, 240);
			getline(cin,last_name);
			SetConsoleTextAttribute(hConsole, 1);
			cout << "\n\t\t";
			SetConsoleTextAttribute(hConsole, 79);
			cout << "Password:";
			SetConsoleTextAttribute(hConsole, 1);
			cout << " ";
			SetConsoleTextAttribute(hConsole, 255);
			getline(cin,password);			
			if (password.length() > 16 || password.length() < 4)
			{
				SetConsoleTextAttribute(hConsole, 1);
				cout << "\n\n\t\t";
				SetConsoleTextAttribute(hConsole, 55);
				cout << "Error! Invalid password! Try again!";
				_getch();
				flag = 0;
				SetConsoleTextAttribute(hConsole, 15);
			}
			while (fread( &info,sizeof(info),1,file1))
			{
				if(info.firstname==first_name&&info.lastname==last_name&&info.password==password)
				{
					num=info.accounttype;
					break;
				}
			}
			fclose(file1);			
		}		
	SetConsoleTextAttribute(hConsole, 15);
	}
	while(flag==0);	
	return num;
}
int error()//Function for when ever there's an error
{
	int i;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\t\t";

	SetConsoleTextAttribute(hConsole, 79);
	cout<<"Error! Please try again!!";
	Sleep(100);

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\t\t";

	for(i=0;i<25;i++)
	{
		SetConsoleTextAttribute(hConsole, 255);
		cout << "*";
		Sleep(40);
	}

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\t\t";

	SetConsoleTextAttribute(hConsole, 63);
    cout << "Press any key to continue";
	_getch();
	SetConsoleTextAttribute(hConsole, 15);
	return 0;

}
int main(void)
{
	int choice;
	//loading();
	choice=login();
	do
	{
		//loading();		
		switch(choice)
		{
		case 0:
			//loading();
			customers();
			break;
		case 1:
			//loading();
			manger();
			break;
		case 2:
			//loading();
			employee(choice);
			break;		
		}
	}
	while (choice>1||choice<5);
	return EXIT_SUCCESS;
}
int manger()//Menu for manger accounts
{	
	int choice;
	do
	{
		//loading();
		choice=mangermenu();//Goes to an are to let the manger pick what option they want
		switch(choice)
		{
		case 1:
			//loading();
			//editaccount();
			break;
		case 2:
			//loading();
			addaccount();
			break;
		case 3:
			//loading();
			removeaccount();
			break;
		case 4:
			//loading();
			//addinventory();
			break;
		case 5:
			//loading();
			//editinventory();
			break;
		case 6:
			//loading();
			//viewinventory();
			break;
		case 7:
			//loading();
			logoff();
			break;
		}	
	}
	while (choice<7 || choice>1);
	return 0;
}
int mangermenu()//Displays all the options for manger accounts
{
	system("cls");
	int choice=0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		SetConsoleTextAttribute(hConsole, 63);//Changes the clour of the text
		cout<<"Manger Menu"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cout<<"1: Edit Account"<<endl;
		cout<<"2: Add Account"<<endl;
		cout<<"3: Remove Account"<<endl;
		cout<<"4: Add Inventory"<<endl;
		cout<<"5: Edit Inventory"<<endl;
		cout<<"6: View Inventory"<<endl;
		cout<<"7: Logout"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		cin>>choice;
		if (choice>7||choice<1)
		{
			error();
			system("cls");
		}
	}
	while (choice>7||choice<1);	
	return choice;
}
void employee(int num)//Menu for employee accounts
{
	int choice;
	do 
	{
		//loading();
		choice=employeemenu();
		switch(choice)
		{
		case 1:
			//loading();
			editaccount(num);
			break;
		case 2:
			//loading();
			//editinventory();
			break;
		case 3:
			//loading();
			//viewinventory();
			break;
		case 4:
			//loading();
			logoff();
			break;
		}
	}
	while(choice>1||choice<4);	
}
int employeemenu()//Displays All the options for employee accounts
{
	system("cls");
	int choice=0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		SetConsoleTextAttribute(hConsole, 63);//Changes the clour of the text
		cout<<"Employee Menu"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cout<<"1: Edit Account"<<endl;
		cout<<"2: Edit Inventory"<<endl;
		cout<<"3: View Inventory"<<endl;
		cout<<"4: Log Out"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		cin>>choice;
		if (choice>4||choice<1)
		{
			error();
			system("cls");
		}
	}
	while(choice>4||choice<1);	
	return choice;
}
int customers()//Menu for customers accounts
{
	int choice;
	do
	{
		//loading();
		choice=customersmenu();
		switch(choice)
		{
		case 1:
			//loading();
			//viewinventory();
			break;
		case 2:
			//loading();
			//storedirectory();
		case 3:
			//loading();
			//help();
			break;
		case 4:
			//loading();
			logoff();
			break;
		}
	}
	while (choice<2||choice>1);
	return 0;
}
int customersmenu()
{
	system("cls");
	int choice=0;
	int selection;
	//Customer Menu
	HANDLE hConsole;
	do
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		system("cls");
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t_______________\n\t\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout << "***Customer Menu***";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\t\t\t_______________\n\n\t\t\t";	
		SetConsoleTextAttribute(hConsole, 15);
		cout << "--- ";//Inventory menu
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Inventory menu  ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(1)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Store Directory
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Store directory ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(2)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Help
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Help            ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(3)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Log off
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Log off         ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(4)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\n\t\t\tEnter choice: ";
		SetConsoleTextAttribute(hConsole, 79);
		cin >> selection;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while (selection<1||selection>4);
	{
		error();
	}
	return selection;
}
int editaccount(int num)
{	
	FILE *file1,
		*temp;
	int counter=0,
		choice=0,
		accountnum,
		ammount=0;
	account info[MAX];
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	file1=fopen("accounts.txt","r");//Opens the file with all the account information
	system("cls");	
	cout<<"\n\n";	
	cout<<"Number\tFirstName   LastName   Password   Email   PhoneNumber  AccountType";
	cout<<"\n\n";
	counter=0;
	while (fread( &info,sizeof(info),1,file1))
	{
		if (num==info[0].accounttype||1==info[0].accounttype)
		{
			cout<<counter+1<<"\t    "<<info[0].firstname<<"    "<<info[0].lastname<<"    "<<info[0].password<<"    "<<info[0].email<<"     "<<info[0].phonenumber<<"     "<<info[0].accounttype<<"\n";
		}
		counter++;
	}
	ammount=counter;
	fclose(file1);
	cout<<"\n\n\t\t";	
	cout<<"Please Enter The Account Number You Want To Edit Or 0 To Go Back To The Last Menu";	
	cout<<"\n\n\t";	
	cin>>choice;
	while (choice<0||choice>counter)
	{
		error();	
		cout<<"Please Enter The Account Number You Want To Edit Or 0 To Go Back To The Last Menu";	
		cout<<"\n\n\t\t";	
		cin>>choice;
	}
	if (choice==0)//Goes back to the last menu
	{
		return 0;
	}
	accountnum=choice-1;
	system("cls");	
	cout<<"\n\n";	
	cout<<"FirstName\tLastName\tPassword\tEmail\tPhoneNumber\tAccount";	
	cout<<"\n\n";
	counter=0;
	file1=fopen("accounts.txt","r");//Opens the file with all the account information
	while (fread( &info,sizeof(info),1,file1))//Reads the file till everything is read
	{		
		if ((counter+1)==choice)
		{			
			cout<<info[0].firstname<<"\t"<<info[0].lastname<<"\t"<<info[0].password<<"\t"<<info[0].email<<"\t"<<info[0].phonenumber<<"\t"<<info[0].accounttype<<endl;
		}
		counter++;
	}
	fclose(file1);
	do
	{
		if (info[accountnum].accounttype==2||info[accountnum].accounttype==0)
		{
			cout<<"Please Enter The Number Of The Part That You Would Like To Edit"<<endl;	
			cout<<"1. First Name"<<endl;
			cout<<"2. Last Name"<<endl;
			cout<<"3. Password"<<endl;
			cout<<"4. Email"<<endl;
			cout<<"5. Phonenumber"<<endl;			
			cout<<"6. Back To Main Menu"<<endl;	
			cin>>choice;
			if (choice<1||choice>6)
			{			
				error();	
				system("cls");
			}
		}
		else if (info[accountnum].accounttype==1)
		{
			cout<<"Please Enter The Number Of The Part That You Would Like To Edit"<<endl;	
			cout<<"1. First Name"<<endl;
			cout<<"2. Last Name"<<endl;
			cout<<"3. Password"<<endl;
			cout<<"4. Email"<<endl;
			cout<<"5. Phonenumber"<<endl;
			cout<<"6. Accounttype"<<endl;
			cout<<"7. Back To Main Menu"<<endl;	
			cin>>choice;
			if (choice<1||choice>7)
			{			
				error();	
				system("cls");
			}
		}
	}
	while (choice<1||choice>7);
	system("cls");
	temp=fopen("temp","w");
	counter=0;
	while (fread(&info,sizeof(info),1,file1))//Reads the file
	{
		if (counter!=accountnum)
		{
			fwrite(&info,sizeof(info),1,temp);//Write to a temp file
		}
		counter++;
	}
	fclose(temp);//Closes the temp file
	temp=fopen("temp","a");//Opens the temp file to save what is changed
	if (choice==1)
	{	
		cout<<"Please Enter The New First Name"<<endl;	
		cin>>info[accountnum].firstname;
		system("cls");		
		fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==2)
	{	
		cout<<"Please Enter The New Last Name"<<endl;	
		cin>>info[accountnum].lastname;
		system("cls");		
		fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==3)
	{	
		cout<<"Please Enter The New Password"<<endl;
		cin>>info[accountnum].password;
		system("cls");		
		fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==4)
	{
		cout<<"Please Enter The New Email"<<endl;
		cin>>info[accountnum].email;		
		system("cls");
		fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==5)
	{	
		cout<<"Please Enter The New Phone Number"<<endl;	
		cin>>info[accountnum].phonenumber;
		system("cls");		
		fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==6&&info[accountnum].accounttype==1)
	{	
		cout<<"Please Enter 1 For Manger, 2 for Employee, 0 for Customer"<<endl;	
		cin>>info[accountnum].accounttype;
		system("cls");		
		fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==7||info[accountnum].accounttype!=1&&choice==6)
	{
		return 0;
	}
	fclose(temp);
	fclose(file1);
	file1=fopen("accounts.txt","w");
	temp=fopen("temp","r");	
	while (fread(&info,sizeof(info),1,temp))
	{	
		for (counter=0;counter<=accountnum;counter++)
		{			
			cout<<info[0].firstname;
			cout<<"\t";
			cout<<info[0].lastname;
			cout<<"\t";
			cout<<info[0].password;
			cout<<"\t";
			cout<<info[0].email;
			cout<<"\t";
			cout<<info[0].phonenumber;
			cout<<"\t";
			cout<<info[0].accounttype;
			system("cls");
			fwrite(&info,sizeof(info),1,file1);//Writes To The Account Text File			
		}
	}
	//Closes All The Text Files
	fclose(temp);
	fclose(file1);
	remove("temp");//Deletes The Temp Text File
	return 0;
}
int addaccount()//Function To Let The User To Add An Account
{	
	int counter=0,
		choice=0;
	FILE *file1;
	account info[MAX];
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	file1=fopen("accounts.txt","a");//Opens the file with all the account information
	do 
	{		
		system("cls");
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"ADD ACCOUNT";
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The First Name For The New Account"<<endl;		
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].firstname;
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";		
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Last Name For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].lastname;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Password For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].password;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Email For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].email;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Phone Number For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].phonenumber;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t";
		SetConsoleTextAttribute(hConsole, 15);		
		cout<<"Please Enter A 1 For A Manger Account 2 For Employee Or 0 For Customer Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].accounttype;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		while (info[counter].accounttype>2||info[counter].accounttype<0)//Checks to make sure it's a vaild option
		{
			error();//Loads The Error Function
			system("cls");
			SetConsoleTextAttribute(hConsole, 15);
			cout<<"Please Enter A 1 For A Manger Account 2 For Employee Or 0 For Customer Account"<<endl;
			SetConsoleTextAttribute(hConsole, 240);
			cin>>info[counter].accounttype;
			SetConsoleTextAttribute(hConsole, 1);
			cout<<"\n\n\t\t";
		}		
		SetConsoleTextAttribute(hConsole, 15);
		cout<<counter+1<<"\t"<<info[counter].firstname<<"\t"<<info[counter].lastname<<"\t"<<info[counter].password<<"\t"<<info[counter].email<<"\t"<<info[counter].phonenumber<<"\t"<<info[counter].accounttype<<endl;		
		system("pause");
		system("cls");
		if (info[counter].firstname!=NULL)
		{
			fwrite(&info,sizeof(info),1,file1);//Saves To The Text File	
		}
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Account Was Saved";
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);	
		cout<<"Enter A 1 If You Want To Add Another Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		choice=0;
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";		
		counter++;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while(choice==1);
	fclose(file1);
	//loading();
	return 0;
}
int removeaccount()
{
	FILE *file1,
		*temp;
	int counter=0,
		choice=0,
		accountnum=0,
		ammount=0;
	account info[MAX];
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	file1=fopen("accounts.txt","r");//Opens the file with all the account information
	system("cls");	
	cout<<"\n\n";	
	cout<<"Number\tFirst Name\tLast Name\tPassword\tEmail\tPhone Number\tAccount Type";
	cout<<"\n\n";	
	while (fread( &info,sizeof(info),1,file1))
	{
		cout<<counter+1<<"\t"<<info[0].firstname<<"\t"<<info[0].lastname<<"\t"<<info[0].password<<"\t"<<info[0].email<<"\t"<<info[0].phonenumber<<"\t"<<info[0].accounttype<<endl;
		counter++;
	}
	ammount=counter;
	fclose(file1);
	cout<<"\n\n\t";	
	cout<<"Please Enter The Account Number You Want To Delete Or 0 To Go Back To The Menu";	
	cout<<"\n\n\t";	
	cin>>choice;
	while (choice<0||choice>counter)
	{
		error();	
		cout<<"Please Enter The Account Number You Want To Delete Or 0 To Go Back To The Menu";	
		cout<<"\n\n\t";	
		cin>>choice;
	}
	if (choice==0)
	{
		return 0;
	}
	accountnum=choice-1;
	temp=fopen("temp","w");
	file1=fopen("accounts.txt","r");
	counter=0;
	while (fread(&info,sizeof(info),1,file1))//Reads the file	
	{
		if (counter!=accountnum&&counter<ammount)
		{
			cout<<info[0].firstname<<endl;
			cout<<info[0].lastname<<endl;
			cout<<info[0].password<<endl;
			cout<<info[0].email<<endl;
			cout<<info[0].phonenumber<<endl;
			cout<<info[0].accounttype<<endl;
			fwrite(&info,sizeof(info),1,temp);//Write to a temp file
		}
		counter++;
	}
	fclose(file1);
	fclose(temp);//Closes the temp file
	rename("accounts.txt","hi");//Deletes The Accounts Text File
	rename("temp","accounts.txt");//Renames the temp to the accounts text file
	remove("hi");
	system("cls");
	return 0;
}
int addcustomer()
{
	int counter=0,
		choice=0;
	FILE *file1;
	account info[MAX];
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	file1=fopen("accounts.txt","a");//Opens the file with all the account information
	//loading();
	do 
	{		
		system("cls");
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"ADD ACCOUNT";
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The First Name For The New Account"<<endl;		
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].firstname;
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";		
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Last Name For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].lastname;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Password For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].password;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Email For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].email;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);
		cout<<"Please Enter The Phone Number For The New Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		cin>>info[counter].phonenumber;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t";			
		info[counter].accounttype=0;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";				
		SetConsoleTextAttribute(hConsole, 15);
		cout<<counter+1<<"\t"<<info[counter].firstname<<"\t"<<info[counter].lastname<<"\t"<<info[counter].password<<"\t"<<info[counter].email<<"\t"<<info[counter].phonenumber<<"\t"<<info[counter].accounttype<<endl;		
		system("pause");
		system("cls");
		if (info[counter].firstname!=NULL)
		{
			fwrite(&info,sizeof(info),1,file1);//Saves To The Text File	
		}
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Account Was Saved";
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 15);	
		cout<<"Enter A 1 If You Want To Add Another Account"<<endl;
		SetConsoleTextAttribute(hConsole, 240);
		choice=0;
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		counter++;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while(choice==1);
	fclose(file1);	
	return 0;
}
int logoff()
{
	string answer;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout << "Are you sure you want to log off? ";
		SetConsoleTextAttribute(hConsole, 55);
		cout << "(Y or N)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t---> ";
		SetConsoleTextAttribute(hConsole, 79);
		cin >> answer;

		if((answer != "Y") && (answer != "y") && (answer != "N") && (answer != "n"))
		{
			error();
			SetConsoleTextAttribute(hConsole, 15);
		}

	}
	while((answer != "Y") && (answer != "y") && (answer != "N") && (answer != "n"));

	if(answer == "Y" || answer == "y")
	{
		SetConsoleTextAttribute(hConsole, 15);
		login();
	}

	if(answer == "N" || answer == "n")
	{
		SetConsoleTextAttribute(hConsole, 15);
		return 0;
	}

	SetConsoleTextAttribute(hConsole, 15);
	return EXIT_SUCCESS;
}