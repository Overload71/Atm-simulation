#include <iostream>
#include <string> // for using the strings
#include <ctime> // to seed random function.
#include <Windows.h> // for the sleep function.  
#include <fstream> // for the reading and writing in the files
#include <iomanip>// for setprecision function (round the decimal points)
#pragma comment( lib, "winmm" )  // for paying sounds
using namespace std;

//________________________________________________________________________________________________________________
struct client//for use in the file saving
{

	int random;
	long long Balance;
	string name,address,email,password,telephone,mobilephone,accountnumber;
	client(): Balance(10000) {}

};

//function declaration____________________________________________________________________________________________
void gotoxy(int column, int line);
int  load(client clients[]);
void start(int r,client clients[]);
void newclient(int r,client clients[]);
void login(int r,client clients[]);
void menu(int jj,client clients [],int r);
void balance(int jj,client clients[],int r);
void withdraw (int jj,client clients[],int r);
void deposite (int jj,client clients[],int r);
void edit(int jj,client clients[],int r);
void save(int r,client clients[]);
//________________________________________________________________________________________________________________
int main()//main function
{
	client clients[1000];
	int r;	
	r=load(clients);
	start(r, clients);

	int x;
	cin>>x;
	cin.ignore();
	if(x==1)
	{
		newclient(r,clients);
		cout << "Would you like to view your account (y/n) " <<endl;
		PlaySound(TEXT("View acc.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);
		char e;
		cin>>e;
		cin.ignore();
		if(e=='y')
		{	
			int r;
			r=load(clients);
			login(r,clients);
		}
		else if (e=='n')
		{}
	}
	else if (x==2)
		login(r,clients);


}

//________________________________________________________________________________________________________________



void start(int r,client clients[])//start function
{
	string enter="Please enter your choice :";
	HANDLE  hConsole;//for colouring
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 5f");
	gotoxy(0,7);
	cout<<"  @@@  @@@  @@@  @@@@@@@@  @@@        @@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@"<<endl;
	Sleep(100);
	cout<<"  @@@  @@@  @@@  @@@@@@@@  @@@       @@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@"<<endl;
	Sleep(100);
	cout<<"  @@!  @@!  @@!  @@!       @@!       !@@       @@!  @@@  @@! @@! @@!  @@! "<<endl;
	Sleep(100);
	cout<<"  !@!  !@!  !@!  !@!       !@!       !@!       !@!  @!@  !@! !@! !@!  !@!  "<<endl;
	Sleep(100);
	cout<<"  @!!  !!@  @!@  @!!!:!    @!!       !@!       @!@  !@!  @!! !!@ @!@  @!!!:! "<<endl;
	Sleep(100);
	cout<<"  !@!  !!!  !@!  !!!!!:    !!!       !!!       !@!  !!!  !@!  !  !@!  !!!!!: "<<endl;
	Sleep(100);
	cout<<"  !!:  !!:  !!:  !!:       !!:       :!!       !!:  !!!  !!:     !!:  !!: "<<endl;
	Sleep(100);
	cout<<"  :!:  :!:  :!:  :!:       ::!:      :!:       :!:  !:!  :!:     :!:  :!:   "<<endl;
	Sleep(100);
	cout<<"   :::: :: :::   ::: ::::  ::::::::  ::::::::  :::   ::  :::     :::  ::: ::::"<<endl;
	Sleep(100);
	cout<<"   :: :  :..:    :::::::   ::::::::  ::::::::   ::::::   ::      :::  : :: :: "<<endl;
	Sleep(100);
	system("color 5f");
	for (int i=14,j=14;i<69,j<69;i++,j++)//loading bar
	{

		gotoxy(i,22);

		cout<<"%";
		gotoxy(j,24);

		cout<<"%";
	}

	gotoxy(14,23);

	cout<<"%";
	gotoxy(68,23);

	cout<<"%";
	gotoxy(16,23);
	srand(time(0));

	for (float k=0,w=15;k<=50,w<68;k++,w++) // loading bar
	{
		gotoxy(w,23);
		SetConsoleTextAttribute(hConsole, 14);
		cout<<" ";
		gotoxy(40,27);
		SetConsoleTextAttribute(hConsole, 15);
		cout<<fixed<<setprecision(0)<<(k/52)*100<<"%";
		Sleep(rand()%200);
	}
	gotoxy(4,4);
	Sleep(2000);
	system("cls");
	system("color 5f");
	cout<<"\n";
	cout<<"\n";

	cout<<"                                                             "<<endl<<


		"               " <<"  /$$$$$$      /$$$$$$$$     /$$      /$$"<<endl<<


		"               " <<" /$$__  $$    |__  $$__/    | $$$    /$$$"<<endl<<


		"               " <<"| $$   \ $$       | $$       | $$$$  /$$$$"<<endl<<


		"               " <<"| $$$$$$$$       | $$       | $$ $$/$$ $$"<<endl<<


		"               " <<"| $$__  $$       | $$       | $$  $$$| $$"<<endl<<


		"               " <<"| $$  | $$       | $$       | $$\     | $$"<<endl<<


		"               " <<"| $$  | $$ /$$   | $$    /$$| $$ \    | $$"<<endl<<


		"               " <<"|__/  |__/|__/   |__/   |__/|__/     |__/"<<"  Bank Machine. "<<endl<<endl<<endl;



	cout << "      " << " -------------------------------- "  << "   " << " ------------------------------ "<<endl;


	cout << "      " << "|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|" << "   " << "|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|" <<endl;


	cout << "      " << "|$ ---------------------------- $|" << "   " << "|$ -------------------------- $|" <<endl;


	cout << "      " << "|$|                            |$|" << "   " << "|$|                          |$|"<<endl;


	cout << "      " << "|$|  If you are a New Client   |$|" << "   " << "|$|  If you are an Existing  |$|"<< endl;


	cout << "      " << "|$|     Please  press (1)      |$|" << "   " << "|$|      Please  press (2)   |$|"<<endl; 


	cout << "      " << "|$|                            |$|" << "   " << "|$|                          |$|"<<endl;


	cout << "      " << "|$ ---------------------------- $|" << "   " << "|$ -------------------------- $|"<<endl;


	cout << "      " << "|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|" << "   " << "|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|"<<endl;


	cout << "      " << " -------------------------------- "  << "   " <<" ------------------------------ "<<endl;
	PlaySound(TEXT("Welcome.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(5000);
	gotoxy(29,24);
	for (int k=0;k<enter.size();k++)
	{
		cout<<enter[k];
		Sleep(50);
	}
	gotoxy(41,27);
	PlaySound(TEXT("Enter choice.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(3500);
}

//________________________________________________________________________________________________________________



void gotoxy( int column, int line )//coord.function
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

//________________________________________________________________________________________________________________
int load(client clients[])//function for loading all inforrmation in files when the program starts
{
	string name,address,email,password,telephone,mobilephone,accountnumber;
	int r=0;
	ifstream file;
	file.open("database.txt",ios::in);   // to read from the file
	while (!file.eof())
	{
		getline(file,name);
		clients[r].name=name.substr(name.find(":")+2,name.size()-name.find(":")+2);
		getline(file,address);
		clients[r].address=address.substr(address.find(":")+2,address.size()-address.find(":")+2);
		getline(file,telephone);
		clients[r].telephone=telephone.substr(telephone.find(":")+2,telephone.size()-telephone.find(":")+2);
		getline(file,mobilephone);
		clients[r].mobilephone=mobilephone.substr(mobilephone.find(":")+2,mobilephone.size()-mobilephone.find(":")+2);
		getline(file,email);
		clients[r].email=email.substr(email.find(":")+2,email.size()-email.find(":")+2);
		getline(file,accountnumber);
		clients[r].accountnumber=accountnumber.substr(accountnumber.find(":")+2,accountnumber.size()-accountnumber.find(":")+2);
		getline(file,password);
		clients[r].password=password.substr(password.find(":")+2,password.size()-password.find(":")+2);
		r++;
	}

	return r;

}

//________________________________________________________________________________________________________________
void newclient(int r,client clients[])//function for registering
{
	system("CLS");
	system("color f3");//f for black,3 for aqua

	ofstream file;

	file.open("database.txt",ios::out | ios::app );


	cout << endl << "Please enter your Name " << endl << endl;
	PlaySound(TEXT("Enter name.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2500);

	getline(cin,clients[r].name);

	file << endl << "Name : " << clients[r].name << endl;

	cout << endl << "Please enter your Address " << endl << endl;
	PlaySound(TEXT("Enter address.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2500);

	getline(cin, clients[r].address);

	file << "Address : " << clients[r].address << endl;

	cout << endl << "Please enter your Telephone " << endl << endl;
	PlaySound(TEXT("Enter telephone.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2500);

	getline(cin, clients[r].telephone);


	file << "Telephone : " << clients[r].telephone << endl;

	cout << endl << "Please enter your MobilePhone " << endl << endl;
	PlaySound(TEXT("Enter mobile.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2500);

	getline(cin, clients[r].mobilephone);


	file << "MobilePhone : " << clients[r].mobilephone << endl;


	cout << endl << "Please enter your Email " << endl << endl;
	PlaySound(TEXT("Enter email.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2500);

	getline(cin, clients[r].email);

	file << "Email : " << clients[r].email << endl;

	system("cls");

	cout << endl<<"             "<< "Please wait for your account number to be generated "<< endl << endl;

	Sleep(3000); // wait for 3 seconds.

	cout << "Your account number is " << endl << endl;

	srand(time(0)); //random number seeder that generates a new random set every time

	file << "AccountNumber : ";

	string accountnumber=""; //empty string

	for(int h=0; h<5 ; h++)
	{
		long random=rand()%10; // % 10  to set range of used numbers from 1 to 9

		cout << random;  

		accountnumber+=random+'0';

		Sleep(500);
	} 

	PlaySound(TEXT("Account no.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(3100);
	file << accountnumber << endl;

	cout<<endl;

	cout << endl << "Please enter a Password to be saved to your account " << endl << endl;
	PlaySound(TEXT("Password.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2000);

	getline ( cin ,clients[r].password);

	file << "Password : " << clients[r].password;

	file.close();

	cout << endl << endl << "                              " << "In progress" << endl << endl;

	Sleep(2); // wait for 2 seconds

	cout << "                         "<< "Your password has been saved " << endl;
	PlaySound(TEXT("Pass saved.wav"),NULL, SND_FILENAME|SND_ASYNC);
	system("cls");

	cout<<"                  =========================================="<<"\n";
	cout<<"                  Congratulations sir you have a new account"<<"\n";
	cout<<"                  =========================================="<<"\n";


	cout<<"                                                *****   "<<"\n";
	Sleep(200);
	cout<<"                                              *****     "<<"\n";
	Sleep(200); 
	cout<<"                                            *****       "<<"\n";
	Sleep(200);
	cout<<"                           *              *****         "<<"\n";
	Sleep(200);
	cout<<"                           **           *****           "<<"\n";
	Sleep(200);
	cout<<"                           ***         ****             "<<"\n";
	Sleep(200);
	cout<<"                           ****      ****               "<<"\n";
	Sleep(200);
	cout<<"                           *****   ****                 "<<"\n";
	Sleep(200);
	cout<<"                            *********                   "<<"\n";
	Sleep(200);
	cout<<"                             *******                    "<<"\n";
	Sleep(200);
	cout<<"                              *****                     "<<"\n";
	Sleep(200);
	cout<<"                               ***                      "<<"\n";
	cout<<"                                                        "<<"\n";
	cout<<"                                                        "<<"\n";
	PlaySound(TEXT("Congratulations.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(3000);



	system("cls");


}

//________________________________________________________________________________________________________________



void login (int r,client clients[])
{
	string password2,accountnumber2;
	bool flag=true,flag2=true,flag3=true;
	system("cls");

	system("color f8");


	cout << "Please enter your Account Number "<< endl << endl;
	PlaySound(TEXT("Enter acc.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2500);
	int t,jj;

	for(t=0;t<3;t++)
	{

		getline(cin,accountnumber2);

		for(jj=0;jj<r;jj++)

		{

			if(accountnumber2==clients[jj].accountnumber)
			{
				flag3=false;
				cout<<"Please enter your password "<<endl;
				PlaySound(TEXT("Enter password.wav"),NULL, SND_FILENAME|SND_ASYNC);

				Sleep(2500);
				break;
			}

		}

		if(flag3==false)
		{
			break;
		}
		else if (t==2)
		{
			system("cls");
			system("color CE");
			cout<<"                     ****ERROR***             ***ERROR***         "<<"\n";
			Sleep(200);

			cout<<"                      ***ERROR****           ***ERROR***          "<<"\n";
			Sleep(200);

			cout<<"                       ***ERROR****         ***ERROR***           "<<"\n";
			Sleep(200);

			cout<<"                        ***ERROR****       ***ERROR***            "<<"\n";
			Sleep(200);

			cout<<"                         ***ERROR****     ***ERROR***             "<<"\n";
			Sleep(200);

			cout<<"                          ***ERROR****   ***ERROR***              "<<"\n";
			Sleep(200);

			cout<<"                           ***ERROR**** ***ERROR***               "<<"\n";
			Sleep(200);

			cout<<"                            *********ERROR********                "<<"\n";
			Sleep(200);

			cout<<"                             ********ERROR*******                 "<<"\n";
			Sleep(200);

			cout<<"                            *********ERROR********                "<<"\n";
			Sleep(200);

			cout<<"                           ***ERROR**** ***ERROR**               "<<"\n";
			Sleep(200);

			cout<<"                          ****ERROR***   ***ERROR***              "<<"\n";
			Sleep(200);

			cout<<"                         ****ERROR***     ***ERROR***             "<<"\n";
			Sleep(200);

			cout<<"                        ****ERROR***       ***ERROR***            "<<"\n";
			Sleep(200);

			cout<<"                       ****ERROR***         ***ERROR***           "<<"\n";
			Sleep(200);

			cout<<"                      ****ERROR***           ***ERROR***          "<<"\n";
			Sleep(200);

			cout<<"                     *****ERROR**             ***ERROR***         "<<"\n";
			cout<<"\n";
			cout<<"\n";
			cout<<"\n";
			cout<<"You have enter your AccountNumber 3 times wrong please try again later "<<endl;
			PlaySound(TEXT("Acc wrong.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(7500);
			flag=false;
			break;
		}

		else 
			cout<<"Please check your accoutnnumber "<<endl;
		PlaySound(TEXT("Check acc.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(2500);

	}	





	for (int m=0;m<=2 && flag;m++)

	{
		getline (cin,password2);

		if(password2==clients[jj].password)
		{
			flag=true;
			flag2=true;
			break;
		}


		else if(m==2 && password2!=clients[jj].password)
		{
			system("cls");
			system("color CE");
			cout<<"                     ****ERROR***             ***ERROR***         "<<"\n";
			Sleep(200);

			cout<<"                      ***ERROR****           ***ERROR***          "<<"\n";
			Sleep(200);

			cout<<"                       ***ERROR****         ***ERROR***           "<<"\n";
			Sleep(200);

			cout<<"                        ***ERROR****       ***ERROR***            "<<"\n";
			Sleep(200);

			cout<<"                         ***ERROR****     ***ERROR***             "<<"\n";
			Sleep(200);

			cout<<"                          ***ERROR****   ***ERROR***              "<<"\n";
			Sleep(200);

			cout<<"                           ***ERROR**** ***ERROR***               "<<"\n";
			Sleep(200);

			cout<<"                            *********ERROR********                "<<"\n";
			Sleep(200);

			cout<<"                             ********ERROR*******                 "<<"\n";
			Sleep(200);

			cout<<"                            *********ERROR********                "<<"\n";
			Sleep(200);

			cout<<"                           ***ERROR**** ***ERROR**               "<<"\n";
			Sleep(200);

			cout<<"                          ****ERROR***   ***ERROR***              "<<"\n";
			Sleep(200);

			cout<<"                         ****ERROR***     ***ERROR***             "<<"\n";
			Sleep(200);

			cout<<"                        ****ERROR***       ***ERROR***            "<<"\n";
			Sleep(200);

			cout<<"                       ****ERROR***         ***ERROR***           "<<"\n";
			Sleep(200);

			cout<<"                      ****ERROR***           ***ERROR***          "<<"\n";
			Sleep(200);

			cout<<"                     *****ERROR**             ***ERROR***         "<<"\n";
			cout<<"\n";
			cout<<"\n";
			cout<<"\n";
			cout<<"You have entered your password 3 times wrong please try again later"<<endl;
			PlaySound(TEXT("Pass wrong.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(6500);
			flag2=false;
		}


		else if (password2!=clients[jj].password)
			cout<<"Please check your password "<<endl;
		PlaySound(TEXT("Check pass.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(2500);

	}

	if(flag==true && flag2==true)
		menu(jj,clients,r);


}

void menu(int jj,client clients [],int r)
{
	system("cls");
	PlaySound(TEXT("What can i do for you.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(2000);
	int w;
	char r1[]="To Check your balance press (1) " ;
	char r2[]="To Deposite press (2) ";
	char r3[]="To Withdraw press (3) " ;
	char r4[]="To Change your Info press (4) "; 
	char r5[]="To logout press (5) " ;

	for(int q=0;q<strlen(r1);q++)
	{
		cout<<r1[q];
		Sleep(20);
	}
	cout<<endl<<endl;

	for(int w=0;w<strlen(r2);w++)
	{
		cout<<r2[w];
		Sleep(20);
	}
	cout<<endl<<endl;

	for(int e=0;e<strlen(r3);e++)
	{
		cout<<r3[e];
		Sleep(20);
	}
	cout<<endl<<endl;
	for(int r=0;r<strlen(r4);r++)
	{
		cout<<r4[r];
		Sleep(20);
	}

	cout<<endl<<endl;

	for(int t=0;t<strlen(r5);t++)
	{
		cout<<r5[t];
		Sleep(20);
	}
	cout<<endl<<endl;

	cin>>w;

	switch(w)
	{
	case 1:balance(jj,clients,r);   break;
	case 2:deposite(jj,clients,r);break;
	case 3:withdraw(jj,clients,r);  break;
	case 4:edit(jj,clients,r);  break;
	case 5:save(r,clients); break;
	}

}

void balance(int jj,client clients[],int r)
{
	char q;
	system("cls");
	cout << endl << "Your Current balance is $" <<clients[jj].Balance<< endl;
	PlaySound(TEXT("Your balance is.wav"),NULL, SND_FILENAME|SND_ASYNC);
	Sleep(2000);

	cout << endl << "Would like to return to the menu? (y/n) " << endl;
	cin >> q;
	if (q=='y')
		menu(jj,clients,r);
}

void withdraw (int jj,client clients[],int r)
{
	char g;
	long long withdraw1;
	system("cls");
	cout << "Please Enter the amount of money you want Withdraw from your balance " << endl <<endl;

	PlaySound(TEXT("Withdraw money.wav"),NULL, SND_FILENAME|SND_ASYNC);
	Sleep(5000);

	cin >>withdraw1;

	if (withdraw1 > clients[jj].Balance)
	{
		cout << "You dont have Sufficient balance " << endl << endl;
		PlaySound(TEXT("Sufficient balance.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);

		cout << "Current balance is "<< clients[jj].Balance << endl;
		PlaySound(TEXT("Your balance is.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(2000);
	}
	else
	{
		clients[jj].Balance-=withdraw1;
		cout << endl << "Current balance is $" << clients[jj].Balance << endl << endl;
		PlaySound(TEXT("Your balance is.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(2000);

	}

	cout << endl << "Would like to return to the menu? (y/n) " << endl;
	cin >> g;
	if (g=='y')
		menu(jj,clients,r);

}

void deposite (int jj,client clients[],int r)
{
	long long Deposite;
	char l;
	system("cls");
	cout << "Please Enter the amount you want to Deposite " << endl;
	PlaySound(TEXT("Deposite.wav"),NULL, SND_FILENAME|SND_ASYNC);

	Sleep(4500);
	cin>>Deposite;
	clients[jj].Balance+=Deposite;
	cout << endl << "Current balance is $" << clients[jj].Balance << endl << endl;

	PlaySound(TEXT("Your balance is.wav"),NULL, SND_FILENAME|SND_ASYNC);
	Sleep(2000);

	cout << endl << "Would like to return to the menu? (y/n) " << endl;
	cin >> l;
	if (l=='y')
		menu(jj,clients,r);

}

void edit(int jj,client clients[],int r)
{
	system("cls");
	int w;
	bool fal=true;
	string temp;

	while(fal)
	{
		cout<<"To change your name press 1 "<<endl;
		PlaySound(TEXT("Change name.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);
		cout<<"To change your address press 2 "<<endl;
		PlaySound(TEXT("Change address.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(2500);
		cout<<"To change your telephone press 3 "<<endl;
		PlaySound(TEXT("Change telephone.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);
		cout<<"To change your mobilephone press 4 "<<endl;
		PlaySound(TEXT("Change mobile.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);
		cout<<"To change your email press 5 "<<endl;
		PlaySound(TEXT("Change email.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);
		cout<<"To change your password press 6 "<<endl;
		PlaySound(TEXT("Change password.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(3500);
		cout<<"To exit press 0 "<<endl;
		PlaySound(TEXT("To exit.wav"),NULL, SND_FILENAME|SND_ASYNC);

		Sleep(2500);
		cin>>w;
		cin.ignore();
		switch(w)
		{

		case 1: 
			system("cls");
			cout<<"Please enter your new name "<<endl;
			PlaySound(TEXT("N name.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(2500);
			getline(cin,temp);
			clients[jj].name=temp;
			break;
		case 2: 
			system("cls");
			cout<<"Please enter your new address "<<endl;
			PlaySound(TEXT("N address.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(2500);
			getline(cin,temp);
			clients[jj].address=temp;
			break;
		case 3: 
			system("cls");
			cout<<"Please enter your new telephone "<<endl;
			PlaySound(TEXT("N telephone.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(3500);
			getline(cin,temp);
			clients[jj].telephone=temp;
			break;
		case 4: 
			system("cls");
			cout<<"Please enter your new mobilephone "<<endl;
			PlaySound(TEXT("N mobile.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(2500);
			getline(cin,temp);
			clients[jj].mobilephone=temp;
			break;
		case 5: 
			system("cls");
			cout<<"Please enter your new email "<<endl;
			PlaySound(TEXT("N email.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(2500);
			getline(cin,temp);
			clients[jj].email=temp;
			break;
		case 6: 
			system("cls");
			cout<<"Please enter your new password "<<endl;
			PlaySound(TEXT("N password.wav"),NULL, SND_FILENAME|SND_ASYNC);

			Sleep(2500);
			getline(cin,temp);
			clients[jj].password=temp;
			break;
		case 0:
			system("cls");
			menu( jj, clients ,r);
			fal=false;
			break;

		}

	}

}

void save(int r,client clients[])
{
	ofstream file;
	file.open("database.txt",ios::out);
	for (int k=0;k<r;k++)
	{
		if (k==0)
		{

			file <<"Name : "<< clients[k].name << endl;
			file << "Address : " << clients[k].address << endl;
			file << "Telephone : " << clients[k].telephone << endl;
			file << "MobilePhone : " << clients[k].mobilephone << endl;
			file << "Email : " << clients[k].email << endl;
			file << "AccountNumber : "<<clients[k].accountnumber<<endl;
			file << "Password : " << clients[k].password;
		}
		else
		{

			file <<endl<<"Name : "<< clients[k].name << endl;
			file << "Address : " << clients[k].address << endl;
			file << "Telephone : " << clients[k].telephone << endl;
			file << "MobilePhone : " << clients[k].mobilephone << endl;
			file << "Email : " << clients[k].email << endl;
			file << "AccountNumber : "<<clients[k].accountnumber<<endl;
			file << "Password : " << clients[k].password;
		}
	}
	file.close();
}







