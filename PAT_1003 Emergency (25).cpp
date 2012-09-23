
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define		MAXN 500
#define INF 0xfffffff
int main()
{	
	int N ,M,C1,C2;
	while(cin>>N>>M>>C1>>C2)
	{
		int rescue[MAXN];
		for(int i=0;i<N;i++)
			cin>>rescue[i];

		int roads[MAXN][MAXN];
		int numofpath[MAXN]; //
		memset(roads,0,sizeof(roads));
		int a,b,c;
		for(int i=0;i<M;i++)
		{
			cin>>a>>b>>c;
			roads[a][b] = c;
			roads[b][a] = c;
		}
		
		memset(numofpath,0,sizeof(numofpath));
		numofpath[C1] = 1;

		int maxRescue[MAXN];
		memset(maxRescue,0,sizeof(maxRescue));
		maxRescue[C1] = rescue[C1];

		bool visited[MAXN];
		memset(visited,false,sizeof(visited));
		int tt = C1;

		for(int j=0;j<N;j++)
		{
			visited[tt]= true;
			for(int i=0;i<N;i++)
			{
				if(roads[tt][i] != 0 && !visited[i])
				{
					if(roads[C1][i] > roads[C1][tt]+roads[tt][i] || roads[C1][i]==0 )
					{
						roads[C1][i] = roads[C1][tt]+roads[tt][i]; // len
						maxRescue[i] = maxRescue[tt]+rescue[i];
						numofpath[i] = numofpath[tt];
					}
					else if(roads[C1][i] == roads[C1][tt]+roads[tt][i])
					{
						if(maxRescue[i] < maxRescue[tt]+rescue[i])
							maxRescue[i] = maxRescue[tt]+rescue[i];
						numofpath[i]+=numofpath[tt];
					}
				}
			}
			int min = INF;
			for(int k=0;k<N;k++)
			{
				if(min > roads[C1][k] && !visited[k] && roads[C1][k]!=0)
				{
					min = roads[C1][k];
					tt = k;   // minimum
				}
			}
		}
		cout<<numofpath[C2]<<" "<<maxRescue[C2]<<endl;
	}
}