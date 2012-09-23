#include<iostream>
#include<queue>
#include<string.h>
#include<iomanip>
using namespace std;
#define maxn 10000+1

int main()
{
	int cas;
	while(cin>>cas)
	{
		char team[1000][11],pwd[1000][11];		
		for(int i=0;i<cas;i++)
			cin>>team[i]>>pwd[i];
		int list[1000]={0};
		int count = 0;
		for(int i=0;i<cas;i++)
		{	
			bool changed = false ;
			for(int j=0;j<strlen(pwd[i]);j++)
			{
				char c = pwd[i][j];
				if(c=='l') c='L';
				else if(c=='1') c='@';
				else if(c=='0') c='%';
				else if(c=='O') c='o';
				if(c!=pwd[i][j]) changed = true;
				pwd[i][j]=c;
			}
			if(changed) list[count++] = i;
		}
		if(count==0)
		{
			if(cas==1)
				cout<<"There is 1 account and no account is modified"<<endl;
			else 
				cout<<"There are "<<cas<<" accounts and no account is modified"<<endl;
		}
		else {
			cout<<count<<endl;
			for(int i=0;i<count;i++)
			{
				cout<<team[list[i]]<<" "<<pwd[list[i]]<<endl;
			}
		}
	}
}