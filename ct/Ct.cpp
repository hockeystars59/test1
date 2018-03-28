#include "matthew.h"
#define NEW "NEW"
#define GUEST "GUEST"
#define MAX 10
int mangermenu();
int menu();
void loading();
int login();
int error();
int manger(int num);
int mangermenu();
void employee(int num);
int employeemenu();
int customers(int num);
int customersmenu();
int addaccount();
int editaccount(int num);
int removeaccount();
int addcustomer();
int logoff();
int viewinventorymenu();
int viewinventory();
int removeinventory();
int store_directory();
int removeinvmenu();
int editinventory();
int editmenu();
int viewaccounts();
int shirts();
int suits();
int other();
int addinvmenu();
int addshirts();
int addsuits();
int addother();
int delshirts();
int delsuits();
int delother();
int editshirts();
int editsuits();
int editother();
int addinventory();
void help();
int webscher();
struct account
{
	char firstname[30],
		lastname[30],
		password[30],
		email[30],
		phonenumber[10];
	int accounttype;
};
void loading()//The loading screen
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
int login()
{
	int flag=0,
		 l,		
		num=0;
	FILE *file1;
	string first_name, last_name, password = "";
	HANDLE hConsole;
	account info;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	webscher();
	do
	{
		file1=fopen("accounts.txt","r");		
		system("cls");
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\n\n\t\t";
        SetConsoleTextAttribute(hConsole, 63);
		cout << "---MOORES Clothing for men---\n\n";                                                   
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\tEnter 'NEW' to create a new account\n\n";
		SetConsoleTextAttribute(hConsole, 1);
		cout << "\t\t";
		SetConsoleTextAttribute(hConsole, 79);
		cout << "First name:";
		SetConsoleTextAttribute(hConsole, 1);
		cout << " ";
		SetConsoleTextAttribute(hConsole, 240);		
		getline(cin,first_name);				
		if (first_name != GUEST&&first_name != NEW)//If the user enters login information
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
			if (password.length() > 16 || password.length() < 4)//Makes sure the password is long infomation
			{
				SetConsoleTextAttribute(hConsole, 1);
				cout << "\n\n\t\t";
				SetConsoleTextAttribute(hConsole, 55);
				cout << "Error! Invalid password! Try again!";
				_getch();				
				SetConsoleTextAttribute(hConsole, 15);
			}
			while (fread( &info,sizeof(info),1,file1))//Checks to see if the user has an account
			{
				if(info.firstname==first_name&&info.lastname==last_name&&info.password==password)
				{	
					flag=1;
					num=info.accounttype;
					break;
				}
			}
			fclose(file1);//Closes the text file			
		}
		else if (first_name==NEW&&last_name=="")//Goes to the add customer function which adds a customer account only
		{
			SetConsoleTextAttribute(hConsole, 15);
			system("cls");
			addcustomer();//Goes to a function where you can add a customer account
			system("cls");
		}
		else if(first_name==GUEST&&last_name=="")
		{
			SetConsoleTextAttribute(hConsole, 15);
			system("cls");
			store_directory();//Goes to the store directory if you have no account	
			system("cls");
		}
	SetConsoleTextAttribute(hConsole, 15);
	}
	while(flag==0);	
	return num;//Returns the account level of the user
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
	return 0;//Returns to the last function the user was at
}
int main(void)
{
	int choice=1;	
	loading();
	choice=login();//Lets the user login and checks what user level they have
	do
	{			
		switch(choice)//Uses the varible from login to see
		{
		case 0:			
			customers(choice);
			break;
		case 1:			
			manger(choice);
			break;
		case 2:		
			employee(choice);
			break;		
		}
	}
	while (choice>0||choice<2);
	return EXIT_SUCCESS;
}
int manger(int num)//Menu for manger accounts
{	
	int choice;
	do
	{	
		loading();
		choice=mangermenu();//Goes to an are to let the manger pick what option they want
		switch(choice)
		{
		case 1:
			loading();
			editaccount(num);
			break;
		case 2:
			loading();
			addaccount();
			break;
		case 3:
			loading();
			removeaccount();
			break;
		case 4:			
			addinventory();
			break;
		case 5:
			editinventory();
			break;
		case 6:			
			viewinventory();
			break;
		case 7:
			loading();
			viewaccounts();
			break;
		case 8:
			loading();
			help();
			break;
		case 9:
			loading();
			logoff();
			break;
		}	
	}
	while (choice<9 || choice>1);
	return 0;//Returns user to the pervious menu
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
		cout<<"7: View Accounts"<<endl;
		cout<<"8: Help"<<endl;
		cout<<"9: Logout"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		cin>>choice;
		if (choice>9||choice<1)//If not a vaild option then the error message is displayed
		{
			error();
			system("cls");
		}
	}
	while (choice>9||choice<1);	
	return choice;//Returns the option picked by the user
}
void employee(int num)//Menu for employee accounts
{
	int choice;
	do 
	{
		loading();
		choice=employeemenu();//Checks to see what opiton was picked
		switch(choice)
		{
		case 1:
			loading();
			editaccount(num);
			break;
		case 2:
			loading();
			editinventory();
			break;
		case 3:
			loading();
			viewinventory();
			break;
		case 4:
			loading();
			help();
			break;
		case 5:
			loading();
			logoff();
			break;
		}
	}
	while(choice>1||choice<5);
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
		cout<<"4: Help"<<endl;
		cout<<"5: Log Out"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		cin>>choice;
		if (choice>5||choice<1)//Displays the error message if a vaild option is not picked
		{
			error();
			system("cls");
		}
	}
	while(choice>5||choice<1);	
	return choice;//Returns the option picked
}
int customers(int num)//Menu for customers accounts
{
	int choice;
	do
	{
		loading();
		choice=customersmenu();//Checks to see what option was picked
		switch(choice)
		{
		case 1:
			loading();
			viewinventory();
			break;
		case 2:
			loading();
			store_directory();
		case 3:
			loading();
			help();
			break;
		case 4:
			loading();
			logoff();
			break;
		}
	}
	while (choice<4||choice>1);
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
		cout<<  "Help            ";
		SetConsoleTextAttribute(hConsole, 8);
		cout<<"(3)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Logoff
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
	while (selection<1||selection>4);//Displays the error screen if a vaild option was not entered
	{
		error();
	}
	return selection;//Returns the option picked
}
int editaccount(int num)
{    
	FILE *file1,
    	*temp;
	int* counter=0;
    int	choice=0,
    	accountnum,
    	ammount=0;
	account info[MAX];
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleTextAttribute(hConsole, 15);

	file1=fopen("accounts.txt","r");//Opens the file with all the account information
	system("cls");    
	cout<<"\n\n";
    SetConsoleTextAttribute(hConsole, 11);
	cout<<"#\tFirst\t   Last\t  Password\t   Email\t   Phone\t  Account";
	cout<<"\n\n";
	*counter=0;

    SetConsoleTextAttribute(hConsole, 15);
	while (fread(&info,sizeof(info),1,file1))//Displays all the accounts that are saved
	{
    	if (num==0&&info[0].accounttype==0)
    	{
        	cout<<counter+1<<"\t  "<<info[0].firstname<<"	"<<info[0].lastname<<"	"<<info[0].password<<"	"<<info[0].email<<" 	"<<info[0].phonenumber<<" 	"<<info[0].accounttype<<"\n";
        	counter++;
    	}
    	else if (num==2&&info[0].accounttype==2)
    	{
        	cout<<counter+1<<"\t  "<<info[0].firstname<<"   "<<info[0].lastname<<"	"<<info[0].password<<"	"<<info[0].email<<" 	"<<info[0].phonenumber<<" 	"<<info[0].accounttype<<"\n";
        	counter++;
    	}
    	else
    	{
        	cout<<counter+1<<"\t   "<<info[0].firstname<<"	"<<info[0].lastname<<"	"<<info[0].password<<"	"<<info[0].email<<" 	"<<info[0].phonenumber<<" 	"<<info[0].accounttype<<"\n";
        	counter++;
    	}
	}
    SetConsoleTextAttribute(hConsole, 15);
	ammount=*counter;
	fclose(file1);
	cout<<"\n\n\t";    

    SetConsoleTextAttribute(hConsole, 63);
	cout<<"Enter The Account Number You Want To Edit Or 0 To Go Back To The Last Menu";    

    SetConsoleTextAttribute(hConsole, 15);
	cout<<"\n\n\t";    
	cin>>choice;
	while (choice<0||choice**counter)//Displays if user entered an invaild option
	{
    	error();    
   		 SetConsoleTextAttribute(hConsole, 63);
    	cout<<"Enter The Account Number You Want To Edit Or 0 To Go Back To The Last Menu";    

   		SetConsoleTextAttribute(hConsole, 15);
    	cout<<"\n\n\t\t";   	 
    	cin>>choice;
	}
	if (choice==0)//Goes back to the last menu
	{   	 
    	return 0;
	}
    SetConsoleTextAttribute(hConsole, 15);
	accountnum=choice-1;
	system("cls");    
	cout<<"\n\n";    

    SetConsoleTextAttribute(hConsole, 11);
	cout<<"FirstName\tLastName\tPassword\tEmail\tPhoneNumber\tAccount";  

	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\n\n";
	counter=0;
	file1=fopen("accounts.txt","r");//Opens the file with all the account information
	while (fread( &info,sizeof(info),1,file1))//Reads the file till everything is read
	{   	 
    	if ((*counter+1)==choice)
    	{
   			 SetConsoleTextAttribute(hConsole, 11);
        	cout<<info[0].firstname<<"\t"<<info[0].lastname<<"\t"<<info[0].password<<"\t"<<info[0].email<<"\t"<<info[0].phonenumber<<"\t"<<info[0].accounttype<<endl;
    	}
    	counter++;
	}
	fclose(file1);
	do
	{
    	if (num==0||num==2)//If the user is employee or customer
    	{
   			 SetConsoleTextAttribute(hConsole, 15);
        	cout<<"\n\t\t1. First Name"<<endl;
        	cout<<"\t\t2. Last Name"<<endl;
        	cout<<"\t\t3. Password"<<endl;
        	cout<<"\t\t4. Email"<<endl;
        	cout<<"\t\t5. Phonenumber"<<endl;       	 
        	cout<<"\t\t6. Back To Main Menu\n\n";          	 

   			 SetConsoleTextAttribute(hConsole, 11);
        	cout<<"Enter The Number Of The Part That You Would Like To Edit: ";   
   			 SetConsoleTextAttribute(hConsole, 15);
        	cin>>choice;
    	}
    	else if (num==1)//If user is manger account
    	{        	 
   			SetConsoleTextAttribute(hConsole, 15);
        	cout<<"\n\t\t1. First Name"<<endl;
        	cout<<"\t\t2. Last Name"<<endl;
        	cout<<"\t\t3. Password"<<endl;
        	cout<<"\t\t4. Email"<<endl;
        	cout<<"\t\t5. Phonenumber"<<endl;    
        	cout<<"\t\t6. Account Type"<<endl;
        	cout<<"\t\t7. Back To Main Menu\n\n";

   			SetConsoleTextAttribute(hConsole, 11);
        	cout<<"Enter The Number Of The Part That You Would Like To Edit: ";  
   			SetConsoleTextAttribute(hConsole, 15);
        	cin>>choice;
    	}
    	if (choice<1||choice>7||choice>6&&num==0||num==2)//If not a vaild choice then the error screen is displayed
    	{           	 
        	error();    
        	system("cls");
        	choice=0;
    	}
	}    
	while (choice<1||choice>7||choice>6&&num==0||num==2);    
	system("cls");
	temp=fopen("temp","w");
	counter=0;
	while (fread(&info,sizeof(info),1,file1))//Reads the file
	{
    	if (*counter!=accountnum)//If it's not the account they want to edit then it's saved to a temp file
    	{
        	fwrite(&info,sizeof(info),1,temp);//Write to a temp file
    	}
    	counter++;
	}
	fclose(temp);//Closes the temp file
	temp=fopen("temp","a");//Opens the temp file to save what is changed
	if (choice==1)
	{   
		 SetConsoleTextAttribute(hConsole, 11);
    	cout<<"\n\n\t\tEnter The New First Name: "<<endl;    
   		 SetConsoleTextAttribute(hConsole, 15);
    	cin>>info[accountnum].firstname;   	 
    	system("cls");   	 
    	fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==2)
	{     	 
   		 SetConsoleTextAttribute(hConsole, 11);
    	cout<<"\n\n\t\tEnter The New Last Name"<<endl;    
   		 SetConsoleTextAttribute(hConsole, 15);
    	cin>>info[accountnum].lastname;   	 
    	system("cls");   	 
    	fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==3)
	{    
   		 SetConsoleTextAttribute(hConsole, 11);
    	cout<<"\n\n\t\tEnter The New Password"<<endl;
   		SetConsoleTextAttribute(hConsole, 15);
    	cin>>info[accountnum].password;   	 
    	system("cls");   	 
    	fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==4)
	{   	 
   	 SetConsoleTextAttribute(hConsole, 11);
    	cout<<"\n\n\t\tEnter The New Email"<<endl;   
   	 SetConsoleTextAttribute(hConsole, 15);
    	cin>>info[accountnum].email;   	 
    	system("cls");
    	fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==5)
	{    
   		 SetConsoleTextAttribute(hConsole, 11);
    	cout<<"\n\n\t\tEnter The New Phone Number"<<endl;
   		SetConsoleTextAttribute(hConsole, 15);
    	cin>>info[accountnum].phonenumber;   	 
    	system("cls");   	 
    	fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==6&&num==1)//If option 6 is picked and user is a manger
	{   	 
   		SetConsoleTextAttribute(hConsole, 11);
    	cout<<"\n\n\t\tEnter 1 For Manger, 2 for Employee, 0 for Customer"<<endl;
   		 SetConsoleTextAttribute(hConsole, 15);
    	cin>>info[accountnum].accounttype;    
    	system("cls");   	 
    	fwrite(&info,sizeof(info),1,temp);
	}
	else if (choice==7||choice==6&&num==0||num==2)//If option 7 is picked or option 6 and user is not a manger
	{   	 
    	return 0;
	}
	fclose(temp);
	fclose(file1);
	file1=fopen("accounts.txt","w");
	temp=fopen("temp","r");    
	while (fread(&info,sizeof(info),1,temp))
	{    
    	for (*counter=0;*counter<=accountnum;*counter++)
    	{             	
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
		if (info[counter].firstname!=NULL)//If there's a value
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
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";		
		counter++;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while(choice==1);
	fclose(file1);
	loading();//Displays the loading screen
	return 0;//Returns to the last menu the user was at
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
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Number\tFirst Name\tLast Name\tPassword\tEmail\tPhone Number\tAccount Type";
	SetConsoleTextAttribute(hConsole, 1);
	cout<<"\n\n";	
	while (fread( &info,sizeof(info),1,file1))//Reads all the different accounts that are in the file
	{
		cout<<counter+1<<"\t"<<info[0].firstname<<"\t"<<info[0].lastname<<"\t"<<info[0].password<<"\t"<<info[0].email<<"\t"<<info[0].phonenumber<<"\t"<<info[0].accounttype<<endl;
		counter++;
	}
	ammount=counter;//The ammount of accounts is saved
	fclose(file1);//Closes the file
	cout<<"\n\n\t";	
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter The Account Number You Want To Delete Or 0 To Go Back To The Menu";
	SetConsoleTextAttribute(hConsole, 1);
	cout<<"\n\n\t";
	cin>>choice;//Gets the number of the account the user wants to delete
	while (choice<0||choice>counter)//Displays the error screen if they enter an invaild choice
	{
		SetConsoleTextAttribute(hConsole, 1);
		error();
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The Account Number You Want To Delete Or 0 To Go Back To The Menu";
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t";	
		cin>>choice;
	}
	if (choice==0)//If they enter 0 it goes back to the last menu the user was at
	{
		return 0;
	}
	accountnum=choice-1;//The account they want to delete as the number displayed is one higher then it's saved
	temp=fopen("temp","w");//Opens A Temp file where all the accounts not getting deleted go
	file1=fopen("accounts.txt","r");
	counter=0;
	while (fread(&info,sizeof(info),1,file1))//Reads the file	
	{
		if (counter!=accountnum&&counter<ammount)//If the counter dosn't equal the account they want to delete
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
	remove("hi");//Removes the old accounts file
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
	loading();
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
		info[counter].accounttype=0;//Makes the account a customer account
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";			
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
		choice=0;//Checks if they want to add another account
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 1);
		cout<<"\n\n\t\t";
		counter++;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while(choice==1);
	fclose(file1);//Closes the file	
	return 0;//Returns to the last screen the user was at
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
		if((answer != "Y") && (answer != "y") && (answer != "N") && (answer != "n"))//If it's not Y or N then it displays the error screen
		{
			error();
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	while((answer != "Y") && (answer != "y") && (answer != "N") && (answer != "n"));
	if(answer == "Y" || answer == "y")//Goes back to the login screen to let another user log in
	{
		SetConsoleTextAttribute(hConsole, 15);
		login();
	}
	if(answer == "N" || answer == "n")//Goes back to the last function they were in
	{
		SetConsoleTextAttribute(hConsole, 15);
		return 0;
	}
	SetConsoleTextAttribute(hConsole, 15);
	return EXIT_SUCCESS;
}
int viewinventory()
{
	int choice,
		num=0;
	do
	{
		loading();
		choice=viewinventorymenu();//Checks to see what option was picked
		switch (choice)
		{
		case 1:
			loading();
			shirts();
			break;
		case 2:
			loading();
			suits();
			break;
		case 3:
			loading();
			other();
			break;
		case 4:
			num=1;
			break;
		}
	}
	while (num==0);
	return 0;
}
int viewinventorymenu()
{
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice=0;
	do 
	{
		cout << "\n\n\t\t\t_______________\n\t\t";		
		SetConsoleTextAttribute(hConsole, 15);		
		cout << "--- ";//Inventory menu
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Shirts ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(1)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t--- ";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Suits ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(2)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t--- ";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Other          ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(3)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t--- ";
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Back To Menu        ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(4)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\n\t\t\tEnter choice: ";
		SetConsoleTextAttribute(hConsole, 79);
		cin >> choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while (choice>4||choice<1);//Displays the error screen if a vaild option was not entered
	{
		error();
	}
	system("cls");
	return choice;
}
int addinventory()
{
	int choice,
		num=0;
	do
	{
		loading();//Loads the loading screen
		choice=addinvmenu();//Checks to see the option the user picked
		switch(choice)
		{
		case 1:
			loading();
			addshirts();
			break;
		case 2:
			loading();
			addsuits();
			break;
		case 3:
			loading();
			addother();
			break;
		case 4:
			num=1;
			break;
		}
	}
	while(num==0);
	system("cls");
	return 0;
}
int store_directory()
{
	//Store Directory
	//This function will allow users/employees to find items within the store
	string choice;
	HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string height;
	string neck;
	string color;
	string accessory;
	do
	{
		do
		{
			//begins store directory function
			//First menu asks user to enter the item they are searching for
			system("cls");
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\n\t\t";
			SetConsoleTextAttribute(hConsole, 79);
			cout << "***STORE DIRECTORY***";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\n\t\t";
			SetConsoleTextAttribute(hConsole, 63);
			cout << "What kind of item are you looking for today?";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\n\t\t--- Suits        ";
			SetConsoleTextAttribute(hConsole, 8);
			cout << "(1)";

			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\t\t--- Shirts       ";
			SetConsoleTextAttribute(hConsole, 8);
			cout << "(2)";

			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\t\t--- Ties         ";
			SetConsoleTextAttribute(hConsole, 8);
			cout << "(3)";

			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\t\t--- Accessories  ";
			SetConsoleTextAttribute(hConsole, 8);
			cout << "(4)";

			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\t\t--- Back to menu ";
			SetConsoleTextAttribute(hConsole, 8);
			cout << "(5)";
			cout << "\n\n\t\t";

			SetConsoleTextAttribute(hConsole, 63);
			cout << "Choice:";

			SetConsoleTextAttribute(hConsole, 15);
			cout << " ";

			SetConsoleTextAttribute(hConsole, 79);
			cin >> choice;

			if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
			{
				error();
			}
		}
		while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");

		SetConsoleTextAttribute(hConsole, 15);

		if(choice == "1")
		{
			//If the user chose to look for suits
			do
			{
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "SHORT: 5 foot 8 and lower               (1)";

				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "REGULAR: Between 5 foot 8 and 6 foot 2  (2)";

				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "TALL: 6 foot 2 and higher               (3)";

				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\n\t\t";

				SetConsoleTextAttribute(hConsole, 63);
				cout << "Enter height class:";

				SetConsoleTextAttribute(hConsole, 15);
				cout << " ";

				cin >> height;

				if(height != "1" && height != "2" && height != "3")
				{
					error();
				}
			}
			while(height != "1" && height != "2" && height != "3");

			SetConsoleTextAttribute(hConsole, 15);

			if(height == "1")
			{
				//If user chose short height class
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "            8888            |  |\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "                            |  |\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(height == "2")
			{
				//if user chose regular height class
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "SSSSSSSS                    |  |\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "                            |  |\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "         ||||||||||         |  |\n";
				cout << "\t\t";

				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |";

				SetConsoleTextAttribute(hConsole, 8);
				cout << "                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(height == "3")
			{
				//if user chose tall height class
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|  |                            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|  |         ||||||||||         ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|  |                            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|000     000    8888            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|000     000                    ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|000     000    8888            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|000     000                    ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|  |            8888            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|  |                            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t|  |                            ";
			    SetConsoleTextAttribute(hConsole, 79);
				cout << "|  |\n";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}
		}

		if(choice == "2")
		{
			//if user chose to look for shirts

			do
			{
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "SMALL: neck size 14.5 to 16             (1)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "REGULAR: neck size 16 to 18             (2)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "LARGE: neck size 18 and up              (3)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 63);
				cout << "Enter shirt size class:";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << " ";
			
				cin >> neck;
			
				if(neck != "1" && neck != "2" && neck != "3")
				{
					error();
				}
			}
			while(neck != "1" && neck != "2" && neck != "3");
			
			SetConsoleTextAttribute(hConsole, 15);

			if(neck == "1")
			{
				//SMALL
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "    8888            |  |\n";
				cout << "\t\t|000     ";
				SetConsoleTextAttribute(hConsole, 79);
			    cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "                    |  |\n";
				cout << "\t\t|000     ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "    8888            |  |\n";
				cout << "\t\t|000     ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(neck == "2")
			{
				//MEDIUM
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "     000    8888            |  |\n";
				cout << "\t\t|";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();

			}

			if(neck == "3")
			{
				//LARGE
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "     000    8888            |  |\n";
				cout << "\t\t|";
                SetConsoleTextAttribute(hConsole, 79);
				cout << "000";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

		}

		if(choice == "3")
		{
			//if user chose to look for ties
			do
			{
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "WARM: reds, oranges and yellows      (1)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "COOL: blues, greens and purples      (2)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "MISC: blacks, whites and greys       (3)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 63);
				cout << "Enter color choice:";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << " ";
			
				cin >> color;
			
				if(color != "1" && color != "2" && color != "3")
				{
					error();
				}
			}
			while(color != "1" && color != "2" && color != "3");

			SetConsoleTextAttribute(hConsole, 15);

			if(color == "1")
			{
				//WARMS
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "8888";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(color == "2")
			{
				//COOLS
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "8888";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(color == "3")
			{
				//MISC
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "8888";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}
		}

		if(choice == "4")
		{
			//if user chose to look for accessories
			do
			{
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "SHOES: dress and casual              (1)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "CASUAL: casual clothing              (2)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 8);
				cout << "MISC: tie bars, socks and more       (3)";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n\n\t\t";
			
				SetConsoleTextAttribute(hConsole, 63);
				cout << "Enter accessory choice:";
			
				SetConsoleTextAttribute(hConsole, 15);
				cout << " ";
			
				cin >> accessory;
			
				if(accessory != "1" && accessory != "2" && accessory != "3")
				{
					error();
				}
			}
			while(accessory != "1" && accessory != "2" && accessory != "3");

			if(accessory == "1")
			{
				//SHOES
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "SSSSSSSS";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(accessory == "2")
			{
				//CASUAL CLOTHING
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ||||||||||         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "AAAAA";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "        ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "AAAAA";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "AAAAA";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "        ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "AAAAA";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}

			if(accessory == "3")
			{
				//MISC
				system("cls");
				SetConsoleTextAttribute(hConsole, 8);
				cout << "\n\n";
				cout << "\t\t------------------------------------\n";
				cout << "\t\t|  |SSSSSSSS                    |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |         ";
				SetConsoleTextAttribute(hConsole, 79);
				cout << "||||||||||";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "         |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|000     000    8888            |  |\n";
				cout << "\t\t|000     000                    |  |\n";
				cout << "\t\t|  |            8888            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t|  |                            |  |\n";
				cout << "\t\t| -     AAAAA        AAAAA       - |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|       AAAAA        AAAAA         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t------------------------------------\n\n";

				cout << "\t\tRed: Items you are looking for\n";
				cout << "\t\tPress enter to continue ...";
				_getch();
			}
		}
		
		if(choice == "5")
		{
			return 0;
		}
	}
	while(choice != "5");

	SetConsoleTextAttribute(hConsole, 15);
	return 0;
}
int removeinventory()
{
	int choice,
		num=0;
	do
	{
		loading();
		choice=removeinvmenu();//Gets the option the user picked
		switch (choice)
		{
		case 1:
			loading();
			delshirts();
			break;
		case 2:
			loading();
			delsuits();
			break;
		case 3:
			loading();
			delother();
			break;
		case 4:
			num=1;
			break;
		}
	}
	while (num==0);
	system("cls");
	return 0;
}
int removeinvmenu()
{
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice=0;
	do 
	{
		cout << "\n\n\t\t\t_______________\n\t\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout << "***Item To Remove***";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\t\t\t_______________\n\n\t\t\t";
		cout << "--- ";//Inventory menu
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Shirts ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(1)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Shirts
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Suits ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(2)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Suites
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Other          ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(3)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Other
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Back To Menu        ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(4)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\n\t\t\tEnter choice: ";
		SetConsoleTextAttribute(hConsole, 79);
		cin >> choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while (choice>4||choice<1);//Displays the error screen if a vaild option was not entered
	{
		error();
	}
	system("cls");
	return choice;
}
int editinventory()
{
	int choice,
		num=0;
	do
	{
		loading();
		choice=editmenu();//Gets the value the user picked
		switch (choice)
		{
		case 1:
			loading();
			editshirts();
			break;
		case 2:
			loading();
			editsuits();
			break;
		case 3:
			loading();
			editother();
			break;
		case 4:
			num=1;
			break;
		}
	}
	while(choice==0);
	system("cls");
	return 0;
}
int editmenu()
{
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice = 0;
	do 
	{
		cout << "\n\n\t\t\t_______________\n\t\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout << "***Item To Edit***";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\t\t\t_______________\n\n\t\t\t";
		cout << "--- ";//Inventory menu
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Shirts ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(1)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Shirts
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Suits ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(2)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Suites
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Other          ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(3)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Other
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Back To Menu        ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(4)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\n\t\t\tEnter choice: ";
		SetConsoleTextAttribute(hConsole, 79);
		cin >> choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while(choice>4 || choice<1);//Displays the error screen if a vaild option was not entered
	{
		if(choice > 4 || choice < 1)
		{
		    error();
		}
	}
	system("cls");
	return choice;
}
int viewaccounts()
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
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Number\tFirstName   LastName  AccountType";
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\n\n";
	counter=0;
	while (fread( &info,sizeof(info),1,file1))//Displays all the accounts that are saved
	{
		cout<<counter+1<<"\t    "<<info[0].firstname<<"    "<<info[0].lastname<<"    "<<info[0].accounttype<<"\n";
		counter++;
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Press Any Key To Go Back To The Last Menu"<<endl;
	_getch();
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	fclose(file1);
	return 0;
}
int shirts()//To view shirts
{
	fstream file1;
	string name[MAX],
		temp2;
	int ammount[MAX],
		counter=0,
		jj=0,
		temp=0,
		ii=0,		
		pos=0;
	float price[MAX],
		min=100,
		temp1=0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	loading();
	file1.open("shirts.txt",ios::in);
	if (file1.is_open())
	{		
		cout<<"Name   Ammount    Price"<<endl;
		while (!file1.eof())//Reads from the file till it gets to the end of the file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
		system("cls");
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Name   Ammount    Price"<<endl;
	for (counter=0;counter<MAX-1;counter++)
	{
		min=price[counter];
		pos=counter;
		for (jj=counter+1;jj<MAX;jj++)//Sorts the inventory by price
		{
			if (price[jj]<min)
			{
				min=price[jj];
				pos=jj;
			}
		}
		temp2=name[counter];
		temp1=price[counter];
		temp=ammount[counter];
		name[counter]=name[counter-1];
		price[counter]=price[counter-1];
		ammount[counter]=ammount[counter-1];
		name[counter-1]=temp2;
		price[counter-1]=temp1;
		ammount[counter-1]=temp;		
	}
	counter=0;
	while (ammount[counter]!=NULL)//Displays the sorted inventory while there's a value
	{
		SetConsoleTextAttribute(hConsole, 55);
		cout<<name[counter]<<"   "<<ammount[counter]<<"   "<<price[counter]<<endl;
		counter++;
	}
	file1.close();//Closes the file
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Press any key to go back to the last menu"<<endl;
	_getch();
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	return 0;
}
int suits()
{
	fstream file1;
	string name[MAX],
		temp2;
	int ammount[MAX],
		counter=0,
		jj=0,
		temp=0;
	float price[MAX],
		temp1=0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	loading();
	file1.open("suits.txt",ios::in);
	if (file1.is_open())
	{		
		cout<<"Name   Ammount    Price"<<endl;
		while (!file1.eof())//Reads from the file till it gets to the end of the file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
		system("cls");
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Name   Ammount    Price"<<endl;
	for (counter=1;counter<MAX;counter++)
	{
		jj=counter;
		while (jj>=0&&price[jj]<price[jj-1])//Sorts the inventory by price
		{
			temp2=name[jj];
			temp1=price[jj];
			temp=ammount[jj];
			name[jj]=name[jj-1];
			price[jj]=price[jj-1];
			ammount[jj]=ammount[jj-1];
			name[jj-1]=temp2;
			price[jj-1]=temp1;
			ammount[jj-1]=temp;
			jj--;
		}
	}
	counter=0;
	while (ammount[counter]!=NULL)//Displays the sorted inventory while there's a value
	{
		SetConsoleTextAttribute(hConsole, 55);
		cout<<name[counter]<<"   "<<ammount[counter]<<"   "<<price[counter]<<endl;
		counter++;
	}
	file1.close();
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Press any key to go back to the last menu"<<endl;
	_getch();
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	return 0;
}
int other()
{
	fstream file1;
	string name[MAX],
		temp2;
	int ammount[MAX],
		counter=0,
		jj=0,
		temp=0;
	float price[MAX],
		temp1=0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	loading();
	file1.open("other.txt",ios::in);
	if (file1.is_open())
	{		
		cout<<"Name   Ammount    Price"<<endl;
		while (!file1.eof())//Reads from the file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
		system("cls");
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Name   Ammount    Price"<<endl;
	for (counter=1;counter<MAX;counter++)
	{
		jj=counter;
		while (jj>=0&&price[jj]<price[jj-1])//Sorts by price
		{
			temp2=name[jj];
			temp1=price[jj];
			temp=ammount[jj];
			name[jj]=name[jj-1];
			price[jj]=price[jj-1];
			ammount[jj]=ammount[jj-1];
			name[jj-1]=temp2;
			price[jj-1]=temp1;
			ammount[jj-1]=temp;
			jj--;
		}
	}
	counter=0;
	while (ammount[counter]!=NULL)//Displays the sorted inventory
	{
		SetConsoleTextAttribute(hConsole, 55);
		cout<<name[counter]<<"   "<<ammount[counter]<<"   "<<price[counter]<<endl;
		counter++;
	}
	file1.close();
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Press any key to go back to the last menu"<<endl;
	_getch();
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	return 0;
}
int addinvmenu()
{
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice=0;
	do 
	{
		cout << "\n\n\t\t\t_______________\n\t\t\t";
		SetConsoleTextAttribute(hConsole, 63);
		cout << "***Item To Add***";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\t\t\t_______________\n\n\t\t\t";
		cout << "--- ";//Inventory menu
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Shirts ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(1)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Shirts
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Suites ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(2)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Suites
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Other          ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(3)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\t\t\t--- ";//Other
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Back To Menu        ";	
		SetConsoleTextAttribute(hConsole, 8);
		cout << "(4)";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\n\t\t\tEnter choice: ";
		SetConsoleTextAttribute(hConsole, 79);
		cin >> choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	while (choice>4||choice<14);//Displays the error screen if a vaild option was not entered
	{
		error();
	}
	system("cls");
	return choice;
}
int addshirts()
{
	fstream file1;
	string name;
	int ammount,
		num=0,
		choice=1;
	float price;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("shirts.txt",ios::app);
	do 
	{	
		while (num==0)
		{
			SetConsoleTextAttribute(hConsole, 63);
			//Makes sure they want to add an item
			cout<<"Enter Any Number To Keep On This Menu Or 0 To Go Back To The Last Menu"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>num;
			SetConsoleTextAttribute(hConsole, 15);
			if (num==0)
			{
				file1.close();
				system("cls");
				return 0;
			}
		}		
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Add Item Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>name;			
		do 
		{
			SetConsoleTextAttribute(hConsole, 63);
			cout<<"Add ammount of the item"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>ammount;
			if (ammount==0||ammount<0)//If the ammount is entered as 0 or less then 0
			{
				SetConsoleTextAttribute(hConsole, 15);
				error();
				system("cls");
			}
		}
		while (ammount==0||ammount<0);
		do 
		{
			SetConsoleTextAttribute(hConsole, 63);
			cout<<"Add The Price Of The Item"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>price;
			if (price==0||price<0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				error();
				system("cls");
			}
		}
		while(price==0||price<0);
		file1<<name<<" "<<ammount<<"  "<<price<<endl;//Saves it all to the text file
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Enter a 1 if you want to add another item"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>num;//checks to see if they want to add another item
		SetConsoleTextAttribute(hConsole, 15);
		system("cls");
	}
	while(num==1);
	system("cls");
	file1.close();
	return 0;
}
int addsuits()
{
	fstream file1;
	string name;
	int ammount,
		num=0,
		choice=1;
	float price;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("suits.txt",ios::app);
	do 
	{	
		while (num==0)
		{
			SetConsoleTextAttribute(hConsole, 63);
			//Makes sure they want to add an item
			cout<<"Enter Any Number To Keep On This Menu Or 0 To Go Back To The Last Menu"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>num;
			SetConsoleTextAttribute(hConsole, 15);
			if (num==0)
			{
				file1.close();
				system("cls");
				return 0;
			}
		}		
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Add Item Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>name;			
		do 
		{
			SetConsoleTextAttribute(hConsole, 63);
			cout<<"Add ammount of the item"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>ammount;
			if (ammount==0||ammount<0)//Checks to see if ammount is a vaild ammount
			{
				SetConsoleTextAttribute(hConsole, 15);
				error();
				system("cls");
			}
		}
		while (ammount==0||ammount<0);
		do 
		{
			SetConsoleTextAttribute(hConsole, 63);
			cout<<"Add The Price Of The Item"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>price;
			if (price==0||price<0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				error();
				system("cls");
			}
		}
		while(price==0||price<0);
		file1<<name<<" "<<ammount<<"  "<<price<<endl;//Saves to the text file
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Enter a 1 if you want to add another item"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>num;//Checks to see if they want to add another item
		SetConsoleTextAttribute(hConsole, 15);
		system("cls");
	}
	while(num==1);
	system("cls");
	file1.close();
	return 0;
}
int addother()
{
	fstream file1;
	string name;
	int ammount,
		num=0,
		choice=1;
	float price;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("other.txt",ios::app);
	do 
	{	
		while(num==0)
		{
			SetConsoleTextAttribute(hConsole, 63);
			//Checks to make sure the user wants to add an item
			cout<<"Enter Any Number To Keep On This Menu Or 0 To Go Back To The Last Menu"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>num;
			SetConsoleTextAttribute(hConsole, 15);
			if (num==0)
			{
				file1.close();
				system("cls");
				return 0;
			}
		}		
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Add Item Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>name;			
		do 
		{
			SetConsoleTextAttribute(hConsole, 63);
			cout<<"Add ammount of the item"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>ammount;
			if (ammount==0||ammount<0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				error();
				system("cls");
			}
		}
		while (ammount==0||ammount<0);
		do 
		{
			SetConsoleTextAttribute(hConsole, 63);
			cout<<"Add The Price Of The Item"<<endl;
			SetConsoleTextAttribute(hConsole, 55);
			cin>>price;
			if (price==0||price<0)
			{
				SetConsoleTextAttribute(hConsole, 15);
				error();
				system("cls");
			}
		}
		while(price==0||price<0);
		file1<<name<<" "<<ammount<<"  "<<price<<endl;//Saves to the text file
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Enter a 1 if you want to add another item"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>num;//Checks if the user wants to add another item
		SetConsoleTextAttribute(hConsole, 15);
		system("cls");
	}
	while(num==1);
	system("cls");
	file1.close();
	return 0;
}
int delshirts()
{
	fstream file1,
		temp;
	int ammount[MAX],
		num=1,
		choice=1,
		counter=0;
	string name[MAX];
	float price[MAX];
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("shirts.txt",ios::in);
	if (file1.is_open())
	{
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Number   Name   Ammount    Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		while (!file1.eof())//Reads from the file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<counter+1<<"   "<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Enter The Number Of The Item You Want To Delete Or 0 To Go Back To The Last Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;
	SetConsoleTextAttribute(hConsole, 15);
	file1.close();
	if (choice==0)
	{
		SetConsoleTextAttribute(hConsole, 1);
		system("cls");
		return 0;
	}
	file1.open("shirts.txt",ios::in);
	counter=0;
	temp.open("temp.txt",ios::out);
	while (!file1.eof())
	{
		if (counter+1==choice)//does nothing if it's the item being deleted
		{
		}
		else//adds to a temp file all the items not getting deleted 
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			temp<<name[counter];
			temp<<ammount[counter];
			temp<<price[counter];
		}
		counter++;
	}
	temp.close();
	file1.close();
	file1.open("shirts.txt",ios::out);
	temp.open("temp.txt",ios::in);
	counter=0;
	while (ammount[counter]!=NULL)
	{
			temp>>name[counter];
			temp>>ammount[counter];
			temp>>price[counter];
			file1<<name[counter];
			file1<<ammount[counter];
			file1<<price[counter];
			counter++;
	}
	temp.close();
	file1.close();
	system("cls");
	return 0;
}
int delsuits()
{
	fstream file1,
		temp;
	int ammount[MAX],
		num=1,
		choice=1,
		counter=0;
	string name[MAX];
	float price[MAX];
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("suits.txt",ios::in);
	if (file1.is_open())
	{
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Number   Name   Ammount    Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		while (!file1.eof())//Reads from the file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<counter+1<<"   "<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Enter The Number Of The Item You Want To Delete Or 0 To Go Back To The Last Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;
	SetConsoleTextAttribute(hConsole, 15);
	file1.close();
	if (choice==0)
	{
		SetConsoleTextAttribute(hConsole, 1);
		system("cls");
		return 0;
	}
	file1.open("suits.txt",ios::in);
	counter=0;
	temp.open("temp.txt",ios::out);
	while (!file1.eof())
	{
		if (counter+1==choice)//does nothing if it's the item being deleted
		{
		}
		else//adds to a temp file all the items not getting deleted 
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			temp<<name[counter];
			temp<<ammount[counter];
			temp<<price[counter];
		}
		counter++;
	}
	temp.close();
	file1.close();
	file1.open("suits.txt",ios::out);
	temp.open("temp.txt",ios::in);
	counter=0;
	while (ammount[counter]!=NULL)
	{
			temp>>name[counter];
			temp>>ammount[counter];
			temp>>price[counter];
			file1<<name[counter];
			file1<<ammount[counter];
			file1<<price[counter];
			counter++;
	}
	temp.close();
	file1.close();
	system("cls");
	return 0;
}
int delother()
{
	fstream file1,
		temp;
	int ammount[MAX],
		num=1,
		choice=1,
		counter=0;
	string name[MAX];
	float price[MAX];
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("other.txt",ios::in);
	if (file1.is_open())
	{
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Number   Name   Ammount    Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		while (!file1.eof())//Reads from the file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<counter+1<<"   "<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Enter The Number Of The Item You Want To Delete Or 0 To Go Back To The Last Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;
	SetConsoleTextAttribute(hConsole, 15);
	file1.close();
	if (choice==0)
	{
		SetConsoleTextAttribute(hConsole, 1);
		system("cls");
		return 0;
	}
	file1.open("other.txt",ios::in);
	counter=0;
	temp.open("temp.txt",ios::out);
	while (!file1.eof())
	{
		if (counter+1==choice)//does nothing if it's the item being deleted
		{
		}
		else//adds to a temp file all the items not getting deleted 
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			temp<<name[counter];
			temp<<ammount[counter];
			temp<<price[counter];
		}
		counter++;
	}
	temp.close();
	file1.close();
	file1.open("other.txt",ios::out);
	temp.open("temp.txt",ios::in);
	counter=0;
	while (ammount[counter]!=NULL)
	{
			temp>>name[counter];
			temp>>ammount[counter];
			temp>>price[counter];
			file1<<name[counter];
			file1<<ammount[counter];
			file1<<price[counter];
			counter++;
	}
	temp.close();
	file1.close();
	system("cls");
	return 0;
}
int editshirts()
{
	fstream file1,
		temp;
	int ammount[MAX],
		num=0,
		choice=1,
		counter=0;
	string name[MAX];
	float price[MAX];
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("shirts.txt",ios::in);
	if (file1.is_open())
	{
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Number   Name   Ammount    Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		while (!file1.eof())//Reads all the items from the file
		{

			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<counter+1<<"   "<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter The Number Of The Item You Want To Edit"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;//Checks the item the user wants to edit
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	file1.close();
	file1.open("shirts.txt",ios::in);
	counter=0;
	temp.open("temp.txt",ios::out);
	SetConsoleTextAttribute(hConsole, 55);
	while (!file1.eof())
	{
		if (counter+1==choice)//If it's the item the user wants to edit it's outputed
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<name[counter]<<"   "<<ammount[counter]<<"   "<<price[counter]<<endl;
			num=counter;
		}
		else//It's saved to a temp file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			temp<<name[counter];
			temp<<ammount[counter];
			temp<<price[counter];
		}
		counter++;
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter A 1 To Edit The Name, A 2 To Edit The Ammount Or 3 To Edit The Price"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;//Checks the part they want to edit
	temp.close();
	file1.close();
	SetConsoleTextAttribute(hConsole, 15);
	while(choice>3||choice<1)//If they enter an invaild choice
	{
		error();		
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter A 1 To Edit The Name, A 2 To Edit The Ammount Or 3 To Edit The Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	system("cls");
	file1.open("shirts.txt",ios::out);
	if (choice==1)
	{
		cout<<name[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>name[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	else if (choice==2)
	{
		cout<<ammount[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>ammount[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	else if (choice==3)
	{
		cout<<price[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>price[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	temp.open("temp.txt",ios::in);
	while (!temp.eof())
	{
		if (counter!=num)
		{
			temp>>name[counter];
			temp>>ammount[counter];
			temp>>price[counter];
			file1<<name[counter];
			file1<<ammount[counter];
			file1<<price[counter];
		}
		counter++;
	}
	temp.close();
	file1.close();
	system("cls");
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Item Was Saved"<<endl;
	system("pause");
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	return 0;
}
int editsuits()
{
	fstream file1,
		temp;
	int ammount[MAX],
		num=0,
		choice=1,
		counter=0;
	string name[MAX];
	float price[MAX];
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("suits.txt",ios::in);
	if (file1.is_open())
	{
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Number   Name   Ammount    Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		while (!file1.eof())//Reads all the items from the file
		{

			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<counter+1<<"   "<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter The Number Of The Item You Want To Edit"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;//Checks the item the user wants to edit
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	file1.close();
	file1.open("suits.txt",ios::in);
	counter=0;
	temp.open("temp.txt",ios::out);
	SetConsoleTextAttribute(hConsole, 55);
	while (!file1.eof())
	{
		if (counter+1==choice)//If it's the item the user wants to edit it's outputed
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<name[counter]<<"   "<<ammount[counter]<<"   "<<price[counter]<<endl;
			num=counter;
		}
		else//It's saved to a temp file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			temp<<name[counter];
			temp<<ammount[counter];
			temp<<price[counter];
		}
		counter++;
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter A 1 To Edit The Name, A 2 To Edit The Ammount Or 3 To Edit The Price"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;//Checks the part they want to edit
	temp.close();
	file1.close();
	SetConsoleTextAttribute(hConsole, 15);
	while(choice>3||choice<1)//If they enter an invaild choice
	{
		error();		
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter A 1 To Edit The Name, A 2 To Edit The Ammount Or 3 To Edit The Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	system("cls");
	file1.open("suits.txt",ios::out);
	if (choice==1)
	{
		cout<<name[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>name[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	else if (choice==2)
	{
		cout<<ammount[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>ammount[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	else if (choice==3)
	{
		cout<<price[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>price[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	temp.open("temp.txt",ios::in);
	while (!temp.eof())
	{
		if (counter!=num)
		{
			temp>>name[counter];
			temp>>ammount[counter];
			temp>>price[counter];
			file1<<name[counter];
			file1<<ammount[counter];
			file1<<price[counter];
		}
		counter++;
	}
	temp.close();
	file1.close();
	system("cls");
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Item Was Saved"<<endl;
	system("pause");
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	return 0;
}
int editother()
{
	fstream file1,
		temp;
	int ammount[MAX],
		num=0,
		choice=1,
		counter=0;
	string name[MAX];
	float price[MAX];
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	file1.open("other.txt",ios::in);
	if (file1.is_open())
	{
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Number   Name   Ammount    Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		while (!file1.eof())//Reads all the items from the file
		{

			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<counter+1<<"   "<<name[counter]<<"  "<<ammount[counter]<<"   "<<price[counter]<<endl;
			counter++;
		}
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter The Number Of The Item You Want To Edit"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;//Checks the item the user wants to edit
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	file1.close();
	file1.open("other.txt",ios::in);
	counter=0;
	temp.open("temp.txt",ios::out);
	SetConsoleTextAttribute(hConsole, 55);
	while (!file1.eof())
	{
		if (counter+1==choice)//If it's the item the user wants to edit it's outputed
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			cout<<name[counter]<<"   "<<ammount[counter]<<"   "<<price[counter]<<endl;
			num=counter;
		}
		else//It's saved to a temp file
		{
			file1>>name[counter];
			file1>>ammount[counter];
			file1>>price[counter];
			temp<<name[counter];
			temp<<ammount[counter];
			temp<<price[counter];
		}
		counter++;
	}
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Please Enter A 1 To Edit The Name, A 2 To Edit The Ammount Or 3 To Edit The Price"<<endl;
	SetConsoleTextAttribute(hConsole, 55);
	cin>>choice;//Checks the part they want to edit
	temp.close();
	file1.close();
	SetConsoleTextAttribute(hConsole, 15);
	while(choice>3||choice<1)//If they enter an invaild choice
	{
		error();		
		system("cls");
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter A 1 To Edit The Name, A 2 To Edit The Ammount Or 3 To Edit The Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>choice;
		SetConsoleTextAttribute(hConsole, 15);
	}
	system("cls");
	file1.open("other.txt",ios::out);
	if (choice==1)
	{
		cout<<name[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>name[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	else if (choice==2)
	{
		cout<<ammount[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Name"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>ammount[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	else if (choice==3)
	{
		cout<<price[num]<<endl;
		SetConsoleTextAttribute(hConsole, 63);
		cout<<"Please Enter The New Price"<<endl;
		SetConsoleTextAttribute(hConsole, 55);
		cin>>price[num];
		SetConsoleTextAttribute(hConsole, 15);
		file1<<name[num]<<" "<<ammount[num]<<"  "<<price[num]<<endl;//Saves the edited item to the text file
	}
	temp.open("temp.txt",ios::in);
	while (!temp.eof())
	{
		if (counter!=num)
		{
			temp>>name[counter];
			temp>>ammount[counter];
			temp>>price[counter];
			file1<<name[counter];
			file1<<ammount[counter];
			file1<<price[counter];
		}
		counter++;
	}
	temp.close();
	file1.close();
	system("cls");
	SetConsoleTextAttribute(hConsole, 63);
	cout<<"Item Was Saved"<<endl;
	system("pause");
	SetConsoleTextAttribute(hConsole, 15);
	system("cls");
	return 0;
}
void help()
{
	system("notepad 'Read_me'");//Displays the read me file
}
int webscher()
{
	system("cls");
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n\n\n\n";

	SetConsoleTextAttribute(hConsole, 11);
	cout << "\t\t\t***   ***   ***\n";
	Sleep(500);
	cout << "\t\t\t ***  ***  ***\n";
	Sleep(500);
	cout << "\t\t\t  *** *** ***\n";
	Sleep(500);
	cout << "\t\t\t   *********\n\n";
	Sleep(500);
	cout << "\t\t\t WEBSCHER INC.\n\n";
	Sleep(1000);

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\t\t     Press Enter to Begin";
	_getch();
	return 0;
}