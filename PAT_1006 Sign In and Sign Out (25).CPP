#include<iostream>
#include<queue>
#include<string.h>
#include<iomanip>
using namespace std;
#define maxn 100+2

// a>b return true
bool cmp(int a1,int a2,int a3,int b1,int b2,int b3)
{
	if(a1>b1|| (a1==b1 && a2>b2) || (a1==b1 && a2==b2 && a3 > b3))
		return true;
	else
		return false;
}
int main()
{
	int cas;
	char hh[3][20];
	while(cin>>cas)
	{
		int a[3]={23,59,59};
		int b[3]={0,0,0};
		char minn[20],maxx[20];
		for(int i=0;i<cas;i++)
		{
			cin>>hh[0]>>hh[1]>>hh[2];		
			int c[3]={0};
			sscanf(hh[1],"%d:%d:%d",&c[0],&c[1],&c[2]);
			if(cmp(a[0],a[1],a[2],c[0],c[1],c[2])) //a > c
			{
				strcpy(minn,hh[0]);
				a[0] = c[0];
				a[1] = c[1];
				a[2] = c[2];
			}
			sscanf(hh[2],"%d:%d:%d",&c[0],&c[1],&c[2]);
			if(!cmp(b[0],b[1],b[2],c[0],c[1],c[2]))  // b<c
			{
				strcpy(maxx,hh[0]);
				b[0] = c[0];
				b[1] = c[1];
				b[2] = c[2];
			}			
		}
		cout<<minn<<' '<<maxx<<endl;
	}

}