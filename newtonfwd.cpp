//Newton Forward Difference
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int fact(int);
float multiply(float,int);

int main()
{
	cout<<setw(10)<<"///// Newton Forward Interpolation/////\n";
	int n,i,j,k,row,col,r,d;
	float z,u,h;
	double result,sum=0;
	
	cout<<"Enter the point ";
	cin>>z;
	
	cout<<"Enter the number of points ";
	cin>>n;
	
	row=n+n;			///number of rows and columns
	col=n+1;
	
	double **y=new double*[row];
	double *f=new double[col];
	
	cout<<"Enter the points.\n";
	
	for (i=0; i < row; i++)
    	y[i] = new double[col];
		
	for(i=0;i<2;i++)											////
	{	
		if(i==0)
			for(j=0,k=0;j<row;j++,k++)
			{
				cout<<"x["<<k<<"] ";
				cin>>y[j][i];
				y[++j][i]=32768;
			}													////input values
			
		if(i==1)
			for(j=0,k=0;j<row;j++,k++)
			{
				cout<<"y["<<k<<"] ";
				cin>>y[j][i];
				y[++j][i]=32768;
			}				
	}															////
	
	
	/* Step Length */     h=y[2][0]-y[0][0]; cout<<"h is "<<h<<endl;
	
	
	////////////////////////////// Difference Table ///////////////////////////////////////
	
	for(i=0;i<row;i++)
	{
		for(j=2;j<col;j++)
		{
			y[i][j]=32768;
		}
	}
	k=n;
	for(j=2;j<col;j++)
	{
		i=j-1;
		r=k-1;
		d=1;
		while(r)
		{			
			y[i][j]=y[i+1][j-1]-y[i-1][j-1];
			if(d==1)
			{	
				f[j]=y[i][j];
				cout<<"Valuef is "<<f[j]<<endl;
				d--;
			}
			i=i+2;
			r--;
		}k--;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////	
	for(i=0;i<row-1;i++)
	{
		for(j=0;j<col;j++)								///// Printing the table	
		{
			if(y[i][j]==32768)
				printf("           ");
			else
				printf("%11lf",y[i][j]);
		}cout<<endl;
	}
	
	
	u=(z-y[0][0])/h;
	cout<<"u is "<<u<<endl;
	
	for(j=2;j<col;j++)
	{
		sum=sum+(multiply(u,j-1)*f[j])/fact(j-1);
		
	}
	
	result=y[0][1]+sum;
	cout<<"Value is "<<result<<endl;								///// Printing the result
	delete(f);
	delete(y);
}

///////////////////////////////////////////////// Factorial Function ////////////////////////////////////////////////////////////////
int fact(int f)
{
	int fact=f;
	while(f!=1)
	{
		fact=fact*(--f);
	}
	return fact;
}

//////////////////////////////////////////////// Multiplication Function //////////////////////////////////////////////////////////
float multiply(float u,int degree)
{
	float product=1;
	int i;
	for(i=0;i<degree;i++)
		product=product*(u-i);
		
	return product;
}
