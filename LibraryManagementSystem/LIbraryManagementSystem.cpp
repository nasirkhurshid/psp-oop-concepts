#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
//////////////////////////////////////
//////function prototypes/////////////
//////////////////////////////////////
void gotoxy(short , short );
void display();
void add();
void search();
void sort();
void del();
void modify();
void searchname();
void searchauthor();
void searchcom();
void searchdate();
void searchid();
void sortid();
void sortname();
void delname();
void delid();
//////////////////////////////////////////////////////

///////////declaration of structure///////////////////
struct book
    {
      char name[40],pubcom[100],aname[50],pubdate[15];	//variables for saving records
      int id;											//////////////////////////////
    };
   
    struct book bk[50];
    int n=0;											//variable for counting records
//////////////////////////////////////////////////////

//////////////////////////main////////////////////////
int main()
{
   while (1)								//start of while for main screen
    {
        system("cls");
	  cout<<setw(25)<<"\t\t-------------"<<endl
   	      <<setw(25)<<"\t\t| MAIN MENU |"<<endl
		  <<setw(25)<<"\t\t-------------"<<endl<<endl
          <<setw(52)<<"\tPlease choose one of the options below: "
          <<endl<<setw(61)
          <<"-----------------------------------------------------"
          <<endl<<endl
          <<setw(25)<<"( A ) Add Record"<<endl<<endl
          <<setw(31)<<"( O ) Sort all Records"<<endl<<endl
          <<setw(34)<<"( S ) Search for a Record"<<endl<<endl
          <<setw(31)<<"( D ) Display a Record"<<endl<<endl
          <<setw(41)<<"( T ) Delete / Undelete a Record"<<endl<<endl
          <<setw(30)<<"( M ) Update a Record"<<endl<<endl
		  <<setw(27)<<"( Q ) Quit Program"<<endl<<endl
		  <<setw(30)<<"Enter Option      [ ]"<<endl<<endl;
		  gotoxy(28,21);
	   switch(getche())			//start of switch statement
        {
         case 'a':												//different cases being
		 case 'A':add();break;									//input by the
         														//user and calling
		 case 'd':												//different functions
		 case 'D': display();break;
         
		 case 'S':
		 case 's':search();break;
         
		 case 't':
		 case 'T':del();break;
		 
		 case 'O':
		 case 'o':sort();break;
         
		 case 'm':
		 case 'M':modify();break;
		 
		 case 'q':
		 case 'Q':exit(0);break;
         default:puts("\n\n\t\tPlease select one option only from the given menu...\n\t\tPress enter to go to main menu...");
		 getch();
        } 				//end switch
    }					//end while
}						//end main
///////////////////////////////////////////////////////////

///////////////////////start of Display////////////////////
void display(void)
	{	
		system("cls");
		cout<<"\n In DISPLAY Function\n";
		cout<<setw(30)<<left<<"  Book Name"<<setw(20)<<left<<"Book Id"<<setw(20)<<left<<setw(20)<<left<<"Author's Name"<<"Publication Date"<<setw(20)<<left<<"     Publication Company"<<endl;
		cout<<setw(30)<<left<<"-------------"<<setw(20)<<left<<"-------"<<setw(20)<<left<<"-------------"<<setw(20)<<left<<"----------------"<<setw(20)<<left<<"----------------------"<<endl;
		for(int i=0;i<n;i++)									//FOR loop for displaying data
		{
			cout<<" "<<setw(30)<<left<<bk[i].name<<setw(20)<<bk[i].id<<setw(20)<<left<<bk[i].aname<<setw(20)<<left<<bk[i].pubdate<<setw(20)<<left<<bk[i].pubcom<<endl;
		}
		cout<<"Press enter to go to main menu...";
		getch();
	}
/////////////////////////////end of Display///////////////////////////

//////////////////////////////start of Add///////////////////////////
void add(void)
	{
		char ch, id1[6];
		do												//start of do-while loop
		{
			system("cls");
			cout<<"\n In ADD Function\n";
			cout<<"Enter Name of Book: ";    
			gets(bk[n].name);
			cout<<"Enter Book ID (eg:231): ";
			gets(id1);
			bk[n].id=atoi(id1);							//conversion of string to integer
			cout<<"Enter Author's Name: ";
			gets(bk[n].aname);
			cout<<"Enter date of Publication (eg:12/02/2005): ";
			gets(bk[n].pubdate);
			cout<<"Enter name of Publisher: ";
			gets(bk[n].pubcom);
			n++;
			cout<<"Do you want to add more Records [y/n]";
			ch=getch();
		}
		while(ch!='n'&& ch!='N');						//end of do-while loop
	}
////////////////////////////////end of add/////////////////////////////////

/////////////////////////start of Search//////////////////////////////////
void search(void)
	{
		system("cls");
		cout<< "\n In SEARCH function\n";
		cout<<"\tSearch by:\n";
		cout<<"\t( N ) Book Name\n";
		cout<<"\t( I ) Book ID\n";
		cout<<"\t( A ) Author's Name\n";
		cout<<"\t( C ) Publication Company\n";
		cout<<"\t( D ) Publication Date\n";
		cout<<"\n\tEnter Option: ";
		switch (getche())
		{
			case 'n':													//different functions
			case 'N':searchname();break;								//called depending
																		//depending on user's
			case 'i':													//choice	
			case 'I':searchid();break;
			
			case 'a':
			case 'A':searchauthor();break;
			
			case 'c':
			case 'C':searchcom();break;
			
			case 'd':
			case 'D':searchdate();break;
			
			default:cout<<"\n\tPlease choose only from the given options...\n";
					cout<<"\tPress Enter to go to main menu...\n";
			getch();	
		}
	}
//////////////////////end of search///////////////////////////

////////////////////////Start Sort////////////////////////////
void sort(void)
	{
		system("cls");		
		cout<< "\n In SORT function\n";
		cout<<"\tHow do you want to sort the Records?\n";
		cout<<"\t( N ) Sort by Book Name\n";
		cout<<"\t( I ) Sort by Book ID\n";
		cout<<"\n\tEnter Option: ";
		switch (getch())
		{
			case 'n':
			case 'N':sortname();break;
			
			case 'i':
			case 'I':sortid();break;
			
			default:cout<<"\n\tPlease choose only from given options!\n";
					cout<<"\tPress Enter to go to main menu...\n";
			getche();
		}
	}
//////////////////End Sort/////////////////////////

///////////////Start Delete////////////////////////
void del(void)
	{
		system("cls");
		cout<<"\n In DELETE function\n";
		cout<<"\tDelete Record using:\n";
		cout<<"\t( N ) Book Name\n";
		cout<<"\t( I ) Book ID\n";
		switch (getch())
		{
			case 'n':
			case 'N':delname();break;
			
			case 'i':
			case 'I':delid();break;
			
			default:cout<<"\n\tPlease choose only from given options!\n";
					cout<<"\tPress Enter to go to main menu...\n";
			getche();
		}
	}
//////////////////End Delete///////////////////////

/////////////////Start Modify//////////////////////
void modify(void)
	{
		system("cls");		
		cout<< "\n In MODIFY function\n";
		char name[40],id1[6];							//variables for new inputs and searching record
		int loc,count=0;								//variables for pointing location and counting found records
		cout<<"\nEnter full NAME of the book you want to modify: ";
		gets(name);
		for (int i=0;i<n;i++)
		{
			if (strcmp(bk[i].name,name)==0)				//checking record
			{
				loc=i;
				cout<<"("<<count+1<<")"<<" Record found!";
				cout<<"\nEnter new name of the Book: ";			//modifying record
				gets(bk[loc].name);
				cout<<"Enter new ID of the Book: ";
				gets(id1);
				bk[loc].id=atoi(id1);
				cout<<"Enter new Author's name: ";
				gets(bk[loc].aname);
				cout<<"Enter new Publishing Date: ";
				gets(bk[loc].pubdate);	
				cout<<"Enter new Publisher's name: ";
				gets(bk[loc].pubcom);
				cout<<"\nRecord has been modified!\n";
				count++;
			}	
		}
		if (count==0)									//if no record found then
		{
			cout<<"No Record found!\n";
		}
		system ("PAUSE");
	}
////////////////////////End Modify/////////////////////////

////////////////////start searchbyname////////////////////
void searchname(void)
{
	system("cls");
	char name[40];					//variable for searching record
	int count=0;					//variable for counting searhes
	cout<<"\nEnter full name of the book: ";
	gets(name);
	for (int i=0;i<n;i++)
	{
		if (strcmp(bk[i].name,name)==0)
		{
			cout<<"("<<count+1<<")"<<" Record found!\n\n";
			cout<<" Book Name: "<<bk[i].name<<endl;				//displaying record
			cout<<" Book Id: "<<bk[i].id<<endl;
			cout<<" Author's Name: "<<bk[i].aname<<endl;
			cout<<" Publication Date: "<<bk[i].pubdate<<endl;
			cout<<" Publisher: "<<bk[i].pubcom<<endl;
			count++;
		}
	}
	if (count==0)							//if no record found then
	{
	cout<<"No Record found!\n";
	}
	system("PAUSE");
}
//////////////////////end searchbyname//////////////////////

////////////////////start searchbyauthor////////////////////
void searchauthor(void)
{
	system("cls");
	char name[40];
	int count=0;
	cout<<"\nEnter full name of the Author: ";
	gets(name);
	for (int i=0;i<n;i++)
	{
		if (strcmp(bk[i].aname,name)==0)
		{
			cout<<"("<<count+1<<")"<<" Record found!\n\n";			
			cout<<" Book Name: "<<bk[i].name<<endl;				//displaying record
			cout<<" Book Id: "<<bk[i].id<<endl;
			cout<<" Author's Name: "<<bk[i].aname<<endl;
			cout<<" Publication Date: "<<bk[i].pubdate<<endl;
			cout<<" Publisher: "<<bk[i].pubcom<<endl;
			count++;
		}
	}
	if (count==0)
	{
	cout<<"No Record found!\n";
	}
	system("PAUSE");
}
//////////////////////end searchbyauthor//////////////////////

////////////////////start searchbypublisher////////////////////
void searchcom(void)
{
	system("cls");
	char name[40];
	int count=0;
	cout<<"\nEnter full name of the Publisher/Publishing Company: ";
	gets(name);
	for (int i=0;i<n;i++)
	{
		if (strcmp(bk[i].pubcom,name)==0)
		{
			cout<<"("<<count+1<<")"<<" Record found!\n\n";
			cout<<" Book Name: "<<bk[i].name<<endl;
			cout<<" Book Id: "<<bk[i].id<<endl;
			cout<<" Author's Name: "<<bk[i].aname<<endl;
			cout<<" Publication Date: "<<bk[i].pubdate<<endl;
			cout<<" Publisher: "<<bk[i].pubcom<<endl;
			count++;
		}
	}
	if (count==0)
	{
	cout<<"No Record found!\n";
	}
	system("PAUSE");
}
//////////////////////end searchbypublisher//////////////////////

////////////////////start searchbydate////////////////////
void searchdate(void)
{
	system("cls");
	char date[40];
	int count=0;
	cout<<"\nEnter date in same format as mentioned in record: ";
	gets(date);
	for (int i=0;i<n;i++)
	{
		if (strcmp(bk[i].pubdate,date)==0)
		{
			cout<<"("<<count+1<<")"<<" Record found!\n\n";
			cout<<" Book Name: "<<bk[i].name<<endl;
			cout<<" Book Id: "<<bk[i].id<<endl;
			cout<<" Author's Name: "<<bk[i].aname<<endl;
			cout<<" Publication Date: "<<bk[i].pubdate<<endl;
			cout<<" Publisher: "<<bk[i].pubcom<<endl;
			count++;
		}
	}
	if (count==0)
	{
	cout<<"No Record found!\n";
	}
	system("PAUSE");
}
//////////////////////end searchbydate//////////////////////

////////////////////start searchbyid////////////////////
void searchid(void)
{
	system("cls");
	int id1,count=0;
	cout<<"\nEnter Book ID as mentioned in record: ";
	cin>>id1;
	for (int i=0;i<n;i++)
	{
		if (bk[i].id==id1)
		{
			cout<<"("<<count+1<<")"<<" Record found!\n\n";
			cout<<" Book Name: "<<bk[i].name<<endl;
			cout<<" Book Id: "<<bk[i].id<<endl;
			cout<<" Author's Name: "<<bk[i].aname<<endl;
			cout<<" Publication Date: "<<bk[i].pubdate<<endl;
			cout<<" Publisher: "<<bk[i].pubcom<<endl;
			count++;
		}
	}
	if (count==0)
	{
	cout<<"No Record found!\n";
	}
	system("PAUSE");
}
//////////////////////end searchbyid//////////////////////

//////////////////////start sortbyname//////////////////////
void sortname(void)
{
	book temp[50];
	int count=0;						//search counter
	for (int j=0;j<n;j++)				//nested loops for sorting records
	{
		for(int i=0;i<n-1;i++)
		{
			if (strcmp(bk[i].name,bk[i+1].name)>0)
			{
				temp[i]=bk[i];								//swapping records
				bk[i]=bk[i+1];
				bk[i+1]=temp[i];
				count++;
			}
		}
	}
	if (count>0)
	{
		cout<<"\n\tData has been sorted!\n";
	}
	if (count==0)
	{
		cout<<"\n\tData is already in sorted form!\n";
	}
	system("PAUSE");
}
//////////////////////end sortbyname//////////////////////

//////////////////////start sortbyid////////////////////
void sortid(void)
{
	book temp[50];
	int count=0;				//search counter
	for (int j=0;j<n;j++)		//nested loops for sorting
	{
		for(int i=0;i<n-1;i++)
		{
			if (bk[i].id>bk[i+1].id)
			{
				temp[i]=bk[i];				//swapping
				bk[i]=bk[i+1];
				bk[i+1]=temp[i];
				count++;
			}
		}
	}
	if (count>0)
	{
		cout<<"\n\tData has been sorted!\n";
	}
	if (count==0)
	{
		cout<<"\n\tData is already in sorted form!\n";
	}
	system ("PAUSE");
}
//////////////////////end sortbyid//////////////////////

//////////////////////start delname//////////////////////
void delname(void)
{
	system("cls");
	book temp[50];				//temporary variable for swapping
	char name[50];
	int loc,count=0;			//search counter and location pointer
	cout<<"Enter full name of Book: ";
	gets(name);
	for (int i=0;i<n;i++)		//loop for searching record
	{
		if (strcmp(bk[i].name,name)==0)			//condition checking
		{
			loc=i;
			for (int j=loc;j<n;j++)				//nested loops for deleting by swapping
			{
				for (int k=loc;k<n;k++)
				{
					temp[k]=bk[k];				//swapping
					bk[k]=bk[k+1];
					bk[k+1]=temp[k];
					count++;
					n--;
				}
			}
		}
	}
	if (count==0)
	{
		cout<<"\n\tNo record found!\n";
	}
	else
	{
		cout<<"\n\tRecord has been deleted!\n";
	}
	system("PAUSE");
}
//////////////////////end delname//////////////////////

//////////////////////start delid//////////////////////
void delid(void)
{
	system("cls");
	book temp[50];
	int loc,id1,count=0;					//same documentation as above function delname
	cout<<"Enter ID of Book: ";
	cin>>id1;
	for (int i=0;i<n;i++)
	{
		if (id1==bk[i].id)
		{
			loc=i;
			for (int j=loc;j<n;j++)
			{
				for (int k=loc;k<n;k++)
				{
					temp[k]=bk[k];
					bk[k]=bk[k+1];
					bk[k+1]=temp[k];
					count++;
					n--;
				}
			}
		}
	}
	if (count==0)
	{
		cout<<"\n\tNo record found!\n";
	}
	else
	{
		cout<<"\n\tRecord has been deleted!\n";
	}
	system("PAUSE");
}
//////////////////////end delid//////////////////////


//////////////////////gotoxy////////////////////////////
void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//////////////////////////////////////////
