#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

int prime[10000];
int tail;
void init_prime()
{
	prime[0] = 2;
	prime[1] = 3;
	tail = 2;
	for(int i=4;i<100000;i++)
	{
		int j=0;
		for(;j<tail;j++)
			if(i % prime[j]==0) break;
		if(j==tail)
			prime[tail++] = i;
	}
}
bool is_prime(int tt)
{
	for(int i=0;i<tail; i++)
	{
		if(prime[i] == tt ) return true;
		if(prime[i] > tt) break;
	}
	return false;
}
int main()
{
	int a,b;
	init_prime();
	while(cin>>a && (a>0) )
	{
		cin>>b;
		int res = 0;
		int fir = a,sec;
		while(fir!=0)
		{
			sec = fir%b;
			fir = fir/b;  			
			res = res*b+sec;
		}
		if(is_prime(res))
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
}