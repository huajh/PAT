#include<iostream>
#include<queue>
#include<string.h>
#include<iomanip>
using namespace std;
#define maxn 10000+1

// what ?
int main()
{
	int cas;
	while(cin>>cas)
	{
		char male[2][11],female[2][11];
		int s1=101,s2=-1,score;
		char a[20],b[20],c[20];		
		for(int i=0;i<cas;i++)
		{
			cin>>a>>b>>c>>score;
			if(strcmp(b,"M")==0 && s1>score) 
			{
				s1 = score;
				strcpy(male[0],a);
				strcpy(male[1],c);
			}
			else if(strcmp(b,"F")==0 && s2 < score)
			{
				s2 = score;
				strcpy(female[0],a);
				strcpy(female[1],c);
			}
		}
		if(s2==-1)
			cout<<"Absent"<<endl;
		else
			cout<<female[0]<<' '<<female[1]<<endl;
		if(s1==101)
			cout<<"Absent"<<endl;
		else
			cout<<male[0]<<' '<<male[1]<<endl;
		if(s1==101 || s2 == -1)
			cout<<"NA"<<endl;
		else 
			cout<<s2-s1<<endl;
	}
}