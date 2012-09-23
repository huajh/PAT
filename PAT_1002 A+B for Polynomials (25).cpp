#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct poly
{
	double exp;
	int coef;
} a[10],b[10],c[20];

int main()
{
	int k1=0,k2=0;
	while(cin>>k1)
	{
		for(int i=0;i<k1;i++)
		{		
			cin>>a[i].coef>>a[i].exp;
		}
		cin>>k2;
		for(int i=0;i<k2;i++)
		{
			cin>>b[i].coef>>b[i].exp;
		}
		int it1=0,it2=0,it3=0;
		while(it1!=k1 && it2!=k2)
		{
			if(a[it1].coef == b[it2].coef)
			{
				c[it3].coef = a[it1].coef;
				c[it3].exp = a[it1].exp + b[it2].exp;
				it1++;
				it2++;
				if(c[it3].exp!=0)
					it3++;
			}
			else if(a[it1].coef > b[it2].coef)
			{
				c[it3].coef = a[it1].coef;
				c[it3].exp = a[it1].exp;
				it1++;
				if(c[it3].exp!=0)
					it3++;				
			}else 
			{
				c[it3].coef = b[it2].coef;
				c[it3].exp = b[it2].exp;
				it2++;
				if(c[it3].exp!=0)
					it3++;			
			}
		}
		while(it1!=k1)
		{
			c[it3].coef = a[it1].coef;
			c[it3].exp = a[it1].exp;
			it1++;
			if(c[it3].exp!=0)
				it3++;		
		}
		while(it2!=k2)
		{
			c[it3].coef = b[it2].coef;
			c[it3].exp = b[it2].exp;
			it2++;
			if(c[it3].exp!=0)
				it3++;				
		}
		cout<<it3;	
		for(int i=0;i<it3;i++)
		{
			cout<<' '<<c[i].coef<<' '<<fixed <<setprecision(1)<<c[i].exp;
		}
		cout<<endl;
	}
}