
#include<iostream>
#include<map>
#include<string.h>
#include<utility>
#include<cstdlib>
#include<exception>


std::string line="\n========================================================================\n";

using std::cout;
using std::cin;

void menu();

class PhoneBook
{
	private:
		std::map<std::string,long long> myMap;

	public:
		PhoneBook();
		void enterEntries();
		void seeEntries() const;
		void findNumber();
		void deleteEntries();
		void deleteAllEntries();

};

class MapException
{	
	public:
		MapException(const std::string& err)
			: errMsg(err) { }
		std::string getError() { return errMsg; }
	private:
		std::string errMsg;

};

class EmptyMap : public MapException
{
	public:
		EmptyMap(const std::string& err)
			:MapException(err) { }
};
class WrongName : public MapException
{
	public:
		WrongName(const std::string& err)
			:MapException(err) { }
};

PhoneBook::PhoneBook()
{
/*	myMap.insert(std::pair<std::string,long long>("Ravi Prasad",8969878208));	      //1st way(member function insert() and STL pair
	myMap["Rajan Prasad"]=8092183561;					         	//2nd way(Array Index Notation)
	myMap.insert(std::map<std::string,long long>::value_type("Rohit Prasad",9641405399)); //3rd way(member function insert() and value_type()
	myMap.insert(std::make_pair("Shankar Prasad",7677943362));	//4th way(member function insert() and make_pair()
*/
}

void PhoneBook::enterEntries() 
{
	cout<<line;
	std::string name;
	long long number;

	cout<<"Enter name :> ";
	cin>>name;
	cout<<std::endl<<"Enter number :> ";
	cin>>number;

	//myMap.insert(std::pair<std::string,long long>(name,number));	  
	myMap.insert(std::make_pair(name,number));
	
	cout<<"----------------------You entered one entry successfully !!------------------------"<<std::endl;
	cout<<line;
}
void PhoneBook::seeEntries() const
{
	cout<<line;
	if(myMap.empty())	throw EmptyMap("Sorry , There is no Entries !!");
		
	for(std::map<std::string,long long>::const_iterator it=myMap.begin(); it!=myMap.end(); it++)
	{
		//cout<<it->first<<" 	"<<it->second<<std::endl;
		//cout<<(*it).first<<" 	"<<(*it).second<<std::endl;
		cout<<(*it).first<<std::endl;
	}
	cout<<line;
}
void PhoneBook::findNumber()  
{
	cout<<line;
	if(myMap.empty())	throw EmptyMap("Sorry , There is no Entries !!");
	
	std::string name;
		
	cout<<"Enter name :> ";
	cin>>name;
		
	long long num=myMap[name];
	if(num==0) 	throw WrongName("You have entered a wrong name !! ");

	cout<<name<<"------->"<<num<<std::endl;
	cout<<line;
}
void PhoneBook::deleteEntries()
{
	cout<<line;
	if(myMap.empty())	throw EmptyMap("Sorry , There is no Entries !!");
		
	std::string name;
	cout<<"Enter name :> ";
	cin>>name;
	
	int i=myMap.erase(name);
	cout<<std::endl<<"You have removed one entry successfully !!"<<i<<std::endl;
	cout<<line;
}
void PhoneBook::deleteAllEntries()
{
	cout<<line;
	if(myMap.empty())	throw EmptyMap("Sorry , There is no Entries !!");
	char ch;
	cout<<"Are you sure you want to remove all entries (y/n)...";
	cin>>ch;
	if(ch=='y')	
	{
		myMap.clear();
		cout<<"---------------You have been removed all entries successfully !!------------------"<<std::endl;
	}
	cout<<line;
}
int main()
{
	menu();
	cout<<std::endl<<std::endl<<"---------------------Thank You !!------------------------"<<std::endl;
	return EXIT_SUCCESS;
}
void menu()
{
	PhoneBook ph;	
	do
	{
		char ch;
		cout<<std::endl<<"Do you want to start transaction (y/n) ....  ";
		cin>>ch;
		if(ch=='y')
		{
			cout<<line;
			cout<<"press 1 : To enter some entry !"<<std::endl;
			cout<<"press 2 : To see the entries !"<<std::endl;
			cout<<"press 3 : To find the number of someone !"<<std::endl;
			cout<<"press 4 : To delete entry !"<<std::endl;
			cout<<"press 5 : To delete all entries !"<<std::endl;
			cout<<"press 6 : To exit this session !"<<std::endl;
			cout<<line;
			short n;
			cin>>n;
			try
			{
				switch(n)
				{
					case 1:	ph.enterEntries();
						break;
					case 2:	ph.seeEntries();
						break;
					case 3:	ph.findNumber();
						break;
					case 4: ph.deleteEntries();
						break;
					case 5: ph.deleteAllEntries();
						break;
					case 6:	exit(0);			//<cstdlib.h>
					default :  cout<<"Sorry , You Entered a wrong input !!";
				}
				/*if(n==1)	ph.enterEntries();
				else if(n==2)	ph.seeEntries();
				else if(n==3)	ph.findNumber();
				else if(n==4)  	ph.deleteEntries();
				else if(n==5)  	ph.deleteAllEntries();
				else if(n==6)	break;
				else 		cout<<"Sorry , You Entered a wrong input !!";*/
			}
			catch(WrongName & wn)
			{
				cout<<wn.getError()<<std::endl;
			}
			catch(EmptyMap & em)
			{
				cout<<em.getError()<<std::endl;
			}
			
		}
		else if(ch=='n') 	break;
		else 		cout<<"Sorry , You Entered a wrong input !!";
	}while(true);
}
