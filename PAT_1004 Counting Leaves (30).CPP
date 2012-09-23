#include<iostream>
#include<queue>
#include<string.h>
#include<iomanip>
using namespace std;
#define maxn 100

int hh[maxn][maxn];
int num[maxn];

int main()
{
	int N ,M;
	while(cin>>N>>M)
	{
		memset(num,0,sizeof(num));
		memset(hh,0,sizeof(hh));
		for(int i=0;i<M;i++)
		{
			int a,b;
			cin>>a>>b;
			num[a] = b;
			for(int j=0;j<b;j++)
				cin>>hh[a][j];
		}
		queue<int> q;
		q.push(1);
		bool first = true;
		while(!q.empty())
		{
			int sum = 0;
			queue<int> q2;
			while(!q.empty())
			{
				int tt = q.front();
				q.pop();	
				if(num[tt]==0) sum++;				
				for(int i=0;i<num[tt];i++)
					q2.push(hh[tt][i]);
			}
			if(first) cout<<sum;
			else cout<<' '<<sum;
			first =false;
			q = q2;
		}
		cout<<endl;
	}

}