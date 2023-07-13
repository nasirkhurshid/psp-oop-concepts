#include <iostream>
using namespace std;
/////////////////////////////////////////////////
class Date {
	private:
		int day, month, year;		
	public:
		Date()											//default constructor
		{
			day=1;
			month=1;
			year=1970;
		}
		
/////////////////////////////////////////////////		
		
		Date (int a, int b, int c)						//overloaded constructor		
		{
			if (a>0&&a<32)								//date validation
			{
				day=a;
				if (b==2)
				{
					
					if ((c%400==0&&c%100==0)||(c%400==0)||(c%4==0&&c%100!=0))				//checking leap year for february
					{
						if (a<=29)
						{
							day=a;
						}
						else
						{
							day=1;
						}
					}
					else if (a<29)
					{
						day=a;
					}
					else 
					{
						day=1;
					}
				}
			}
			else
			{
				day=1;
			}
			if (b>0&&b<13)								//month validation
			{
				month=b;
			}
			else
			{
				month=1;
			}
			year=c;
		}
		
/////////////////////////////////////////////////		
		
		int setday (int d)								//setter for day
		{
			if (d>0&&d<32)								//validation
			{
				day=d;
			}
			else
			{
				day=1;
			}
		}
		
		int setmonth (int m)							//setter for month
		{
			if (m>0&&m<13)								//validation
			{
				month=m;
			}
			else
			{
				month=1;
			}
		}		
		
		int setyear (int y)								//setter for year
		{
			year=y;
		}
		
/////////////////////////////////////////////////		
		
		void getday ()									//getter for day
		{
			cout<<"Day: "<<day<<endl;
		}
		
		void getmonth ()								//getter for month
		{
			cout<<"Month: "<<month<<endl;		
		}
		
		void getyear ()									//getter for year
		{
			cout<<"Year: "<<year<<endl;
		}
		
/////////////////////////////////////////////////		
		
		void display ()									//display function for displaying date
		{
			cout<<"In Display Function\n";
			cout<<"Day: "<<day<<endl<<"Month: "<<month<<endl<<"Year: "<<year<<endl;
			cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
		}
		
/////////////////////////////////////////////////		
		
		void add_day (int d)									//function for adding or subtracting days
		{	
			int m1=0,y1=0, r,r2,m=0,y=0, d1,d2;					//variables for saving different results

			if (d>0)											//condition if the day is added
			{
				d1=d;
				if (d<=30&&d>=0)								//condition if less than 31 days are added
				{
					if ((d+day)<=30)
					{
						day=day+d;
					}
					else if ((d+day)>30)
					{
						r=(d+day)-30;
						day=r;
						if (month==12)
						{
							month=1;
							year++;
						}
						else
						{ 
							month++; 
						}
					}	
				}

				if (d>30)										//condition if more than 30 days are added
				{
					while (d>30)								//loop for reducing days to less than 30
					{
						d=d-30;
						m++;									//variable for storing months
					}
					if (m>=12)						
					{
						while (m>=12)							//loop for reducing months to less than or equal to 12
						{
							m=m-12;
							y++;								//variable for storing years
						}
					}
					if ((m+month)<=12)							//condition for checking month
					{
						month=month+m;							//result of month
					}
					else
					{
						r2=(month+m)-12;
						month=r2;								//result of month
					}
					if (d<31&&d>=0)								//condition for checking day
					{
					
						if ((d+day)<=30)
						{
							day=d+day;							//result of day
						}
						else 
						{
							r=(d+day)-30;
							day=r;								//result of day
						}
					}
					year=year+y;						//result of year
				}
				cout<<"After adding "<<d1<<" day: \n";
				cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
			}				

			/////////////////////////////////////////////////

			if (d<0)													//condition if the day is subtracted
			{
				d2=-d;
				d=-d;
				if (d<30)												//condition if less than 31 days are subtracted
				{
					if (d<day)
					{
						day=day-d;
					}
					else if (d>day)
					{
						day=30-(d-day);
						if (month==1)
						{
							month=12;
							year--;
						}
						else
						{
							month--;
						}
					}
					else if (d==day)
					{
						day=30;
					}
				}
				if (d>30)												//condition if more than 30 days are subtracted
				{
					while (d>30)										//loop for reducing days to less than 30
					{
						d=d-30;
						m1++;											//variable for storing months
					}
					if (m1>=12)											
					{
						while (m1>=12)									//loop for reducing months to less than or equal to 12
						{
							m1=m1-12;
							y1++;										//variable for storing years
						}
					} 
					if (m1<month)
					{
						month=month-m1;					//result of month
					}
					else if (m1>month)
					{
						month=12-(m1-month);			//result of month
					}
					else if (m1==0)
					{
						month=month;					//result of month
					}		
					if (d<day)
					{
						day=day-d;						//result of day
					}
					else if (d>day)
					{
						day=30-(d-day);					//result of day
						month--;
					}
					else if (d==day)
					{
						day=30;							//result of day
					}			
					year=year-y1;						//result of year
				}
				cout<<"After subtracting "<<d2<<" days: \n";
				cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
			}	 			
		}
		

/////////////////////////////////////////////////


	void add_month (int m)											//function for adding and subtracting months
		{
			int r, mon1=m,yr=0;										//variables for storing different results
			if (m==0||m==-0)										//condition if 0 months are added or subtracted
			{
				cout<<"Please Enter a number except 0 !\n";
			}
			
			if (m>0)												//condition if months are added
			{
				if (month==12&&m<=12)								//condition for last month
				{
					month=m;
					year=year+1;
				}
				else if (m<=12&&m>0)								//condition if less than or equal to 12 months are added
				{
					 if ((m+month)<=12)
					{
						month=month+m;
					}
					else if ((m+month)>12)
					{
						r=(m+month)-12;
						month=r;
						if (r<=month&&r>0)
						{
							year++;
						}
					}
				}
			
				
				if (m>12)									//condition if more than 12 months are added
				{
					while (m>=12)							//loop for reducing months to less than or equal to 12
					{
						m=m-12;
						yr++;
					}
					if ((m+month)<=12)
					{
						month=month+m;
					}
					else if ((m+month)>12)
					{
						month=(m+month)-12;
					}
					year=year+yr;
				}
				cout<<"After adding "<<mon1<<" months: "<<endl;
				cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
			}
			
			/////////////////////////////////////////////////
			
			if (m<0)														//condition if months are added or subtracted
			{
				int mon=-m;
				m=-m;
				if (month==1&&m<=12)										//condition for first month
				{
					month=13-m;
					year--;
				}
				else if (m>0&&m<12)										//condition if less than or equal to 12 months are subtracted
				{
					if ((month-m)>0)
					{
						month=month-m;
					}
					else if ((month-m)<0)
					{
						month=12-(m-month);
						year--;
					}
					else if ((month-m)==0)
					{
						month=12;
						year--;
					}
				}
				
				if (m>12)								//condition if more than 12 months are subtracted
				{
					while (m>=12)							//loop for reducing months to less than or equal to 12
					{
						m=m-12;
						yr++;
					}
					if ((month-m)>0)
					{
						month=month-m;
					}
					else if ((month-m)<0)
					{
						month=12-(m-month);
						year--;
					}
					else if ((month-m)==0)
					{
						month=12;
						year--;
					}
					year=year-yr;	
				}		
			cout<<"After subtracting "<<mon<<" months: "<<endl;
			cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
		}
	}


/////////////////////////////////////////////////
			
			
		void add_year(int y)									//function for adding or subtracting years
		{
			if (y>0)											//condition if years are added
			{
				year=year+y;
				cout<<"After adding "<<y<<" years: "<<endl;
				cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
			}
			else if (y<0)											//condition if years are subtracted
			{
				year=year+y;
				cout<<"After subtracting "<<-y<<" years: "<<endl;
				cout<<"Current Date: "<<day<<"/"<<month<<"/"<<year<<endl;
			}
		}	
			
/////////////////////////////////////////////////			
			
		void leapyear ()										//function for checking leap year
		{
			if (year%4==0&&year%100!=0)
			{
				cout<<"The given year ("<<year<<") is a leap year\n";
			}
			else if (year%400==0)
			{
				cout<<"The given year ("<<year<<") is a leap year\n";
			}
			else if (year%400==0&&year%100==0)
			{
				cout<<"The given year ("<<year<<") is a leap year\n";
			}
			else
			{
				cout<<"The given year ("<<year<<") is not a leap year\n";
			}
		}
		
/////////////////////////////////////////////////		
		
		int diff (const Date &o)						//function for calculating difference between dates
		{
			int r,r1,r2,r3;
			if (this->year<o.year)						//condition if the current object's year is less than given year
			{
				r1=(o.year-1) - this->year;				//formula for
				r1=r1*365;								//calculating days in years
				
				r2=(12 - this->month);						//formula for
				r2=(r2*30)+(30 - this->day);				//calculating days in months
			 
				r3=o.month-1;								//formula for
				r3=(r3*30)+o.day;							//calculating days in current month
			}
			else if (this->year>o.year)				//condition if the current object's year is greater than given year
			{
				r1=this->year-(o.year+1);
				r1=r1*365;
			
				r2=(12 - o.month);
				r2=(r2*30)+(30 - o.day);
				
				r3=this->month - 1;
				r3=(r3*30) + this->day;
			}
			r=r1+r2+r3;							//final result of difference
			cout<<"Difference between given dates: "<<r<<" Days"<<endl;
		}
		
//////////////////////////////////////////////////

		Date& operator ++()											//prefix ++ operator overloading
		{
			this->day+=1;
			if(this->day==32||this->day>31)							//validity check
			{
				this->day=1;
				this->month++;
				if (this->month>12)
				{
					this->month=1;
					this->year++;
				}
			}
			return *this;			
		}		

//////////////////////////////////////////////////

		Date& operator --()									// prefix -- operator overloading
		{
			this->day-=1;
			if(this->day<1)									//condition for validity
			{
				this->day=31;
				this->month--;
				if (this->month<1)
				{
					this->month=12;
					this->year--;
				}
			}
			return *this;
		}

//////////////////////////////////////////////////	

		Date operator ++(int i)									//postfix ++ operator overloading
		{
			Date h=*this;										//creation of returning object
			this->day+=1;
			if(this->day==32||this->day>31)
			{
				this->day=1;
				this->month++;
				if (this->month>12)
				{
					this->month=1;
					this->year++;
				}
			}
			return h;
		}

///////////////////////////////////////////////////	

		Date operator --(int i)											//postfix -- operator overloading
		{
			Date h=*this;
			this->day-=1;
			if(this->day<1)
			{
				this->day=31;
				this->month--;
				if (this->month<1)
				{
					this->month=12;
					this->year--;
				}
			}
			return h;
		}	

/////////////////////////////////////////////////

		bool operator == (Date& o)								// == operator overloading
		{
			if (this->day==o.day && this->month==o.month && this->year==o.year)			// condition for checking
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	
/////////////////////////////////////////////////			

		bool operator != (Date& o)						// != operator overloading
		{
			if (this->day!=o.day || this->month!=o.month || this->year!=o.year)			//condition for checking
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
/////////////////////////////////////////////////			

		bool operator < (Date& o)						// < operator overloading
		{
			if (this->year<o.year)						// condtion for true value
			{
				return true;
			}
			if (this->month<o.month&&(this->year<o.year||this->year==o.year))			// condtion for true value
			{
				return true;
			}
			if (this->day<o.day && this->month<o.month && this->year<o.year)			// condtion for true value
			{
				return true;
			}
			if (this->day<o.day && (this->month==o.month && this->year==o.year))			// condtion for true value
			{
				return true;
			}
			if (this->day>o.day && (this->month<o.month && (this->year==o.year||this->year<o.year)))			// condtion for true value
			{
				return true;
			}
			else
			{
				return false;
			}
		}		
		
/////////////////////////////////////////////////			

		bool operator > (Date& o)										// > operator overloading
		{
			if (this->year>o.year)										// condtion for true value
			{
				return true;
			}
			if (this->month>o.month&&(this->year>o.year||this->year==o.year))					// condtion for true value
			{
				return true;
			}
			if (this->day>o.day && (this->month==o.month && this->year==o.year))					// condtion for true value
			{
				return true;
			}
			if (this->day<o.day && (this->month>o.month && (this->year==o.year||this->year>o.year)))				// condtion for true value
			{
				return true;
			}
			else
			{
				return false;
			}		
		}

/////////////////////////////////////////////////

		bool operator >= (Date& o)									// >= operator overloading
		{
			if ((*this>o)||(*this==o))								//condition for checking
			{
				return true;
			}
			else
			{
				return false;
			}
		}		

/////////////////////////////////////////////////

		bool operator <= (Date& o)											// <= operator overloading
		{
			if ((*this<o)||(*this==o))										//condition for checking
			{
				return true;
			}
			else
			{
				return false;
			}
		}		
			
/////////////////////////////////////////////////			
				
		friend ostream& operator << (ostream& out, Date& o)					// << operator overloading
		{
			cout<<"Current Date: ";
			out<<o.day<<"/"<<o.month<<"/"<<o.year<<endl;
			return out;
		}
		
/////////////////////////////////////////////////

		friend istream& operator >> (istream& in, Date& o)												// >> operator overloading
		{
			cout<<"Enter Day: ";
			in>>o.day;
			if (o.day<0||o.day>31)																// validity check
			{
				cout<<"You entered invalid day!\n";
				o.day=1;
			}
			cout<<"Enter Month: ";
			in>>o.month;
			if (o.month<0||o.month>12)													// validity check
			{
				cout<<"You entered invalid month!\n";
				o.month=1;
			}
			cout<<"Enter Year: ";
			in>>o.year;
			return in;
		}

/////////////////////////////////////////////////		
			
		~Date ()																
		{
			cout<<"Don't count the days, make the days count ("<<year<<"/"<<month<<"/"<<day<<")"<<endl;
		}	
		
		
			
};
////////////////
////////////////
int main()
{
	Date obj1;
	obj1.display();
	
	Date obj2(14,8,1947);
	cout<<obj2;
	
	obj2.add_day(122);
	obj2.add_day(-222);
	
	obj2.add_month(14);
	obj2.add_month(-214);
	
	obj2.add_year(64);
	obj2.add_year(-221);
	
	obj2.leapyear();
	
	++obj2;
	cout<<obj2;
	
	obj1++;
	cout<<obj1;
	
	--obj2;
	cout<<obj2;
	
	obj1--;
	cout<<obj1;
	
	cin>>obj1;
	cin>>obj2;
	
	bool x = (obj1>obj2);
	cout<<boolalpha<<x<<endl;
	
	bool y = (obj1<obj2);
	cout<<boolalpha<<y<<endl;
	
	bool z = (obj1==obj2);
	cout<<boolalpha<<z<<endl;
	
	bool a = (obj1!=obj2);
	cout<<boolalpha<<a<<endl;

	bool b = (obj1>=obj2);
	cout<<boolalpha<<b<<endl;

	bool c = (obj1<=obj2);
	cout<<boolalpha<<c<<endl;

	system ("PAUSE");	
	return 0;
}
