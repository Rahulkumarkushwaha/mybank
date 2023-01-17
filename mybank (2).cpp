#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
class BankAccount
{
		int ac_no;
		char name[50];
		int deposit;
		char ac_type;
	public:
		void login();
		void create_account();
		int return_ac_no() const;
		int return_deposit() const;
		void deposit_amt(int);
		void withdraw(int);
		void report() const;
		char return_type() const;
		void show_account() const;
		void update();
	
};
void BankAccount::create_account()
{
	system("CLS");
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>ac_no;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account [Current(C/c)/Saving(S/s)] : ";
	cin>>ac_type;
	ac_type=toupper(ac_type);
	p:  cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	if(deposit<=1000){
		cout<<"\t\t\t Intial amount should be more than 1000"<<endl;
		goto p;
	}
	cout<<"\n\n\t\t\tAccount Created Successfully...!!";
}
void BankAccount::update()
{
	cout<<"\n\t\t\tEnter Account No. to be update : "<<ac_no;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>ac_type;
	ac_type=toupper(ac_type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}
int BankAccount::return_ac_no() const
{
	return ac_no;
}
void BankAccount::deposit_amt(int x)
{
	deposit+=x;
}
void BankAccount::report() const
{
	cout<<ac_no<<setw(6)<<" "<<name<<setw(8)<<" "<<ac_type<<setw(18)<<deposit<<endl;
}
void BankAccount::withdraw(int x)
{
	deposit-=x;
}
void BankAccount::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<ac_no;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<ac_type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}
char BankAccount::return_type() const
{
	return ac_type;
}
int BankAccount::return_deposit() const
{
	return deposit;
}
void write_account();
void deposit_withdraw(int, int);
void delete_account(int);
void display_all_list();
void update_account(int);
void login();


int main()
{
	char poll;
	int num;
	login();
	do
	{
		system("CLS");

		cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		cout<<"\t\t\t@@ ____________________________________________________ @@\n";
		cout<<"\t\t\t@@|                                                    |@@\n";
		cout<<"\t\t\t@@|                                           	       |@@\n";
		cout<<"\t\t\t@@|                   WELCOME TO                       |@@\n";
		cout<<"\t\t\t@@|                                                    |@@\n";
		cout<<"\t\t\t@@|              BANK MANAGEMENT SYSTEM                |@@\n";
		cout<<"\t\t\t@@|                    (APR3 BANK)                     |@@\n";   
		cout<<"\t\t\t@@|                                                    |@@\n";
		cout<<"\t\t\t@@|                                                    |@@\n";
		cout<<"\t\t\t@@|******************< Developers >********************|@@\n";
		cout<<"\t\t\t@@|________Aditya__Prashant__Ritik__Riya__Rahul________|@@\n";
		cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\t\t\t\t\t";
		
		cout<<"\n\t\t\t   ** Tension lene ka nhi, sirf APR3 BANK ko dene ka **\n";
		
		cout<<"\n\t\t\t\t\t    # MAIN MENU #\n";
		cout<<"\n\t\t\t\t\t1. CREATE NEW ACCOUNT";
		cout<<"\n\t\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t\t4. UPDATE ACCOUNT";
		cout<<"\n\t\t\t\t\t5. ALL ACCOUNTS HOLDER LIST";
		cout<<"\n\t\t\t\t\t6. CLOSE ACCOUNT";
		cout<<"\n\t\t\t\t\t7. EXIT";
		
		cout<<"\n\n\t\t\t\t\tSelect Your Choice (1-7): ";
		cin>>poll;
		
		switch(poll)
		{
			case '1':  //creating new account
				write_account();
				cout<<endl<<"Press 'ENTER' to go to main menu...";
				break;
				
			case '2':   //deposit amount
				system("CLS");
				cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
				deposit_withdraw(num, 1);
				cout<<endl<<endl<<"Press 'ENTER' to go to main menu...";
				break;
				
			case '3':   //Withdraw amount
				system("CLS");
				cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
				deposit_withdraw(num, 2);
				cout<<endl<<"Press 'ENTER' to go to main menu...";
				break;
			
			case '4':   //update account
			 	system("CLS");
				cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
				update_account(num);
				cout<<endl<<"Press 'ENTER' to go to main menu...";
				break;
				
			case '5':      // Tabulate all accounts list
				display_all_list();  
				cout<<endl<<"Press 'ENTER' to go to main menu...";
				break;
				
			case '6':      // delete account
				system("CLS");
				cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
				delete_account(num);
				cout<<endl<<"Press 'ENTER' to go to main menu...";
				break;		
						
			case '7':   // exit from the compiler
				system("CLS");
				cout<<"\n\n\t\t\t\tTHANK YOU !! Please stay in touch."<<endl;
				cout<<"\t\t\t\t\t- APR3 Digital BANK";
				break;
							
			default :cout<<"\n\t\t\tSORRY !! Please enter valid option...";
		}
		cin.ignore();
		cin.get();
	}
	while(poll!='7');
	
	return 0;
}
void write_account()
{
	BankAccount ac;
	ofstream outFile;
	outFile.open("account.doc",ios::binary|ios::app);  // opening data of account holder(if any)
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));  // storing data of accounts holder
	outFile.close();
}
void update_account(int n)
{
	bool found=false;
	BankAccount ac;
	fstream File;
    File.open("account.doc",ios::binary|ios::in|ios::out);   // opening data of account holder(if any)
	if(!File)
	{
		cout<<"SORRY !! File with entered account doesn't exist...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount));   // reading data of account holder(if any)
		if(ac.return_ac_no()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.update();
			int pos=(-1)*static_cast<int>(sizeof(BankAccount));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		    cout<<"\n\n\t\t\tRecord Updated Successfully...!!";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void delete_account(int n)
{
	BankAccount ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.doc",ios::binary);
	if(!inFile)
	{
		cout<<"SORRY !! File with entered account doesn't exist...";
		return;
	}
	outFile.open("Temp.doc",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		if(ac.return_ac_no()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.doc");
	rename("Temp.doc","account.doc");
	cout<<"\n\nRecord Deleted Successfully...!!";
}
void display_all_list()
{
	system("CLS");
	BankAccount ac;
	ifstream inFile;
	inFile.open("account.doc",ios::binary);
	if(!inFile)
	{
		cout<<"SORRY !! Record Not Found...";
		return;
	}
	cout<<"\n\n\t\t\tACCOUNT HOLDER LIST\n\n";            // Tabulating all accounts
	cout<<"******************************************************\n";
	cout<<"A/c no.       NAME            Type[C/S]     Balance\n";
	cout<<"******************************************************\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount)))
	{
		ac.report();
	}
	inFile.close();
}
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	BankAccount ac;
	fstream File;
    File.open("account.doc", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"SORRY !! File with entered account doesn't exist...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
		if(ac.return_ac_no()==n)
		{
			ac.show_account();
			if(option==1)     // deposit 
			{
				cout<<"\n\n\t\t\tTO DEPOSIT AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.deposit_amt(amt);
			}
		    if(option==2)    // withdraw
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.return_deposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.withdraw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);   
			File.write(reinterpret_cast<char *> (&ac), sizeof(BankAccount));
			cout<<"\n\n\t\t\tRecord Updated Successfully...!!";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void login(){
   string pass ="";
   char ch;
   cout << "\n\n\n\n\n\n\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "APR3"){
      cout << "\n\n\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system("CLS");
   }else{
      cout << "\n\n\t\t\t\t\tSORRY !! Access Aborted...\n\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
