#include <iostream>
#include <string>
using namespace std;

class matrixType{
	
	int row, col;
	int mat[3][3];
	 
public:
	matrixType()												//default constructor
	{
		row=2;
		col=3;
		mat[row][col];
	}
	
	matrixType(int r,int c)										//overloaded constructor
	{
		row=r;
		col=c;
		mat[row][col];
	}
	
	void setdata()											//setter function
	{
		cout<<"\nYou have created a matrix of order "<<row<<"x"<<col<<endl;
		cout<<"You have to input "<<(row*col)<<" elements"<<endl;
		for(int i=0;i<row;i++)								//loop for inputting elements of matrix
		{
			for(int j=0;j<col;j++)
			{
				cout<<"Enter value of element Matrix"<<i+1<<j+1<<": ";
				cin>>mat[i][j];
			}
		}
	}
	
	void display()											//display function
	{
		if (this->col>0&&this->row>0)						//condition for empty matrix
		{
			cout<<"\nDisplaying elements of matrix: \n";
			for(int i=0;i<row;i++)							//loop for displaying elements
			{
				for(int j=0;j<col;j++)
				{
					cout<<"\t"<<this->mat[i][j]<<"\t";
				}
				cout<<endl;
			}	
		}
		else
		{
			cout<<"\nYour matrix is empty!\n";
		}
		
	}
	
	matrixType operator + (matrixType& o)						// + operator overloading
	{
		if ((this->row==o.row)&&(this->col==o.col))				//condition for checking order of matrices	
		{
			matrixType m(o.row,o.col);						
			for(int i=0;i<row;i++)								//loops for addition
			{
				for(int j=0;j<col;j++)
				{
					m.mat[i][j]=mat[i][j]+o.mat[i][j];
				}
			}
			cout<<"\nYou added two matrices!";
			return m;	
		}
		else
		{
			cout<<"\nYou can not add two matrices of different order!";
			matrixType n(0,0);
			return n;
		}
	}

	matrixType operator - (matrixType& o)						// - operotor overloading
	{
		if ((this->row==o.row)&&(this->col==o.col))				//condition for checking order of matrices
		{
			matrixType m(o.row,o.col);
			for(int i=0;i<row;i++)								//loops for subtraction
			{
				for(int j=0;j<col;j++)
				{
					m.mat[i][j]=this->mat[i][j]-o.mat[i][j];
				}
			}
			cout<<"\nYou subtracted two matrices!";
			return m;	
		}
		else
		{
			cout<<"\nYou can not subtract two matrices of different order!";
			matrixType n(0,0);
			return n;	
		}
	}
		
	matrixType operator * (const matrixType& o)					// * operator overloading
	{		
//		if (this->col==o.row)									//condition for checking order of matrices
//		{
			matrixType m(this->row,o.col);
	  		for(int i=0; i<this->row; i++)						//loops for multiplication
	  		{
	  			for(int j=0; j<o.col; j++)
				{
					m.mat[i][j]=0;     
					for(int k=0; k<this->col; k++) 
					{
        				m.mat[i][j]+=this->mat[i][k]*o.mat[k][j]; 			//multiplication
            		}
				}
			}
			cout<<"\nYou multiplied two matrices!";
        	return m;	
//		}
//		else
//		{
//			cout<<"\nYou can only multiply two matrices if columns of first matrix are equal to rows of second matrix!";
//			matrixType n(0,0);
//			return n;	
//		}
	}
	
	friend ostream& operator << (ostream& out, matrixType& o)					// << operator overloading
	{
		if (o.col>0&&o.row>0)													//condition for checking empty matrix
		{
			cout<<"\nDisplaying elements of matrix: \n";
			for(int i=0;i<o.row;i++)											//loops for displaying
			{
				for(int j=0;j<o.col;j++)
				{
					out<<"\t"<<o.mat[i][j]<<"\t";
				}
				out<<endl;
			}	
		}
		else
		{
			out<<"\nYour matrix is empty!\n";
		}
		return out;
	}

	~matrixType()							
	{
				//destructor is left empty
	}



};





int main()
{
	matrixType m1(4,2);
	m1.setdata();
	m1.display();

	matrixType m2(2,4);
	m2.setdata();
	cout<<m2;
	
	matrixType m3;
	m3=m1+m2;
	cout<<m3;
	
	m3=m3-m1;
	cout<<m3;
	
	m3=m1*m2;
	cout<<m3;

	system ("PAUSE");
	return 0;
}

