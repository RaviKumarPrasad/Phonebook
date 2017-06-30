
#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

void not_leap_year(int);				
void print_calender(long int &,long int &, int);		

int n_leap;					//n_leap = no of leaps
long int t_days,l_days;				//t_days = total days , l_days = left days

int count = 0;		
int mon = 1; 		//mon -> month
int amy = 1;			
int tot = 0;		//tot -> total days



void print_calander_background(int mon)
{
	std::string month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	std::string week[7] = {"sun","mon","tue","wed","thu","fri","sat"};
	
	for(int j=0; j<12; j++)
	{
		j = mon-1;
		cout<<"---------------------"<<month[j]<<"-----------------------\n";
		for(int i=0; i<7; i++)
		{
			cout<<"   "<<week[i];
		}
		std::cout<<endl;
		break;
	}

}
void count_increament()
{
	count++;
}
void leap_year(int yy)
{
	n_leap = yy/4 - yy/100 + yy/400;
	t_days = yy * 365l + n_leap;
	l_days = t_days - 366;
	print_calender(t_days, l_days, yy);
		
}
void check_leap(int yy)	 
{
	if(( yy%4 == 0 && yy%100 != 0) || yy%400 == 0)	leap_year(yy);
	
	else 	not_leap_year(yy);
}
int main()
{
	int yy;					//n_leap = no of leaps 		yy = year
	do
	{
		cout<<"Enter Year :> ";
		cin>>yy;
	}
	while(yy < 0);
	check_leap(yy);
	std::cout<<endl;
	std::cout<<endl;
}


void not_leap_year(int yy)
{
	n_leap = (yy-1)/4 - (yy-1)/100 + (yy-1)/400;
	t_days = yy * 365l + n_leap;
	l_days = t_days - 365;
	print_calender(t_days, l_days, yy);
}
void feb_leap()
{
	if(amy == 30)
	{
		
		std::cout<<endl;
		std::cout<<endl;
		mon++;
		amy = 1;
	}	
}
void feb_not_leap()
{
	if(amy == 29)
	{
		
		std::cout<<endl;
		std::cout<<endl;
		mon++;
		amy = 1;
	}	
}
void calculation(int & i)
{
	if(count == 7)
	{
		count_increament();
		std::cout<<endl;
	       	count = 1;
	}
	else	count_increament();
	cout<<"   "<<setw(3)<<amy;
	amy++;
}

void print_calender(long int & t_days,long int & l_days, int yy)
{
	for(int i=1; i<=t_days; i++)
	{
		if(i<1 || i<=l_days) continue;
		else
		{
			if(mon <= 7)
			{
				if(mon == 2)
				{
					if((yy%4 == 0 && yy%100 != 0) || yy%400 == 0)  feb_leap();
					else feb_not_leap();
				}

				if(mon % 2 != 0)
				{
					if(amy == 32)
					{
					
						std::cout<<endl;
						std::cout<<endl;
						mon++;
						amy = 1;
					}
				}
				else
				{
					if(amy == 31)
					{
						std::cout<<endl;
						std::cout<<endl;
						mon++;	
						amy = 1;
					}
				}
			}	
			else
			{
				if(mon % 2 == 0)
				{
					if(amy == 32)
					{
						std::cout<<endl;
						std::cout<<endl;
						mon++;
						amy = 1;
					}
				}
				else
				{
					if(amy == 31)
					{
						std::cout<<endl;
						std::cout<<endl;
						mon++;
						amy = 1;
					}
				}
			}
			if(amy == 1)
			{
				print_calander_background(mon);
				int var;
			       	var = i%7;
				count = 0;
				for(int k=1; k<=var; k++)
				{
					if(count == 7)
					{
						count_increament();
						std::cout<<endl;
					       	count = 1;
					}
					else  count_increament();
					char a = ' ';
					cout<<"   "<<setw(3)<<a;
				}
			}

			switch(i%7)
			{
				case 1:{
					       	calculation(i);
					       	break;
				       }
				case 2:{
					       	calculation(i);
					       	break;
				       }
				case 3:{
					       	calculation(i);
					       	break;
				       }
				case 4:{
					       	calculation(i);
					       	break;
				       }
				case 5:{
					       	calculation(i);
					       	break;
				       }
				 case 6:{
					       	calculation(i);
					       	break;
				       }
				case 0:{
					       	calculation(i);
						break;
				       }	
			}
			tot++;
		}
	}

	std::cout<<endl;
	cout<<"Total = "<<tot;
}
