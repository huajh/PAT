#include<iostream>
#include<string.h>
#include<cmath>
#include<iomanip>
using namespace std;

struct poly
{
	double exp;
	int coef;
} a[10],b[10] ;

int main()
{
	int k1,k2,k3;
	while(cin>>k1)
	{
		for(int i=0;i<k1;i++)
			cin>>a[i].coef>>a[i].exp;
		cin>>k2;
		for(int i=0;i<k2;i++)
			cin>>b[i].coef>>b[i].exp;
		double  c[2001];
		for(int i=0;i<=2000;i++)
			c[i]=0;
		for(int i=0;i<k1;i++)
		{
			for(int j=0;j<k2;j++)
			{
				int coef = a[i].coef+b[j].coef;
				double exp =a[i].exp*b[j].exp;
				c[coef] +=exp;
			}
		}
		int count=0;
		for(int i=2000;i>=0;i--)
			if(abs(c[i])>0e-8) count++;
		cout<<count;
		for(int i=2000;i>=0;i--)
		{
			if(abs(c[i])>0e-8){
				cout<<" "<<i<<" "<<fixed <<setprecision(1)<<c[i];
			}
		}
		cout<<endl;
	}
}