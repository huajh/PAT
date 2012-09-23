#include<iostream>
#include<queue>
#include<string.h>
#include<iomanip>
using namespace std;
#define maxn 100+2

char digits[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	char hh[maxn];
	while(cin>>hh)
	{
		unsigned int sum = 0;
		for(int i=0;i<strlen(hh);i++)
		{
			sum +=hh[i]-'0';
		}
		if(sum==0) cout<<"zero"<<endl;
		else{
			int dd[10];
			memset(dd,0,sizeof(dd));
			int i=0;
			for(;sum!=0;i++)
			{
				dd[i] = sum%10;
				sum/=10;
			}		
			bool first = true;

			for(i--;i>=0;i--)
			{
				if(first)
				cout<<digits[dd[i]];
				else 
					cout<<' '<<digits[dd[i]];
				first = false;
			}
			cout<<endl;
		}
	}

}