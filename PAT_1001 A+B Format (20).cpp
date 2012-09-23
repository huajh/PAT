#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int res = a+b;
		int fir,sec ,third;
		if(res<0)
		{
			cout<<'-';
			res = -res;
		}		
		fir = res%1000;
		sec = (res/1000)%1000;
		third = (res/(1000*1000))%1000;	
		if(third!=0)
		{
			cout<<third<<',';
			if(sec<100)
				cout<<0;
			if(sec<10)
				cout<<0;	
		}		
		if(third!=0||sec!=0)
		{		
			cout<<sec<<',';
			if(fir<100)
				cout<<0;
			if(fir<10)
				cout<<0;	
		}		
		cout<<fir<<endl;		
	}
}