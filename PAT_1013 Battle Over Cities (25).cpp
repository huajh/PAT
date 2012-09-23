#include<iostream>
#include<string.h>
#include<cmath>
#include<iomanip>
#include<queue>
using namespace std;
#define maxn 1000+1
// »®·Ö
int map[maxn][maxn];
int n,m,k;
int bfs(int test)
{
	int count=0,area = 0;
	bool visited[maxn];
	memset(visited,false,sizeof(visited));
	visited[test] = true;
	count=1;
	for(int  i=0;count!=n;i++)
	{		
		queue<int> q;
		int root;
		for(int j=0;j<n;j++)
			if(!visited[j]) 
			{
				root=j ;break;
			}
		q.push(root);
		visited[root] = true;
		count++;
		while(!q.empty())
		{
			int tt = q.front();
			q.pop();
			for(int j=0;j<n;j++)
			{
				if(map[tt][j]==1 && !visited[j])
				{
					visited[j]=true;
					q.push(j);
					count++;
				}
			}
		}
		area++;
	}
	return area;
}
int main()
{
	
	while(cin>>n>>m>>k)
	{
		int a,b;
		memset(map,0,sizeof(map));
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			map[a-1][b-1]=1;
			map[b-1][a-1]=1;
		}
		int test[maxn];
		for(int i=0;i<k;i++)
		{
			cin>>test[i];
		}
		for(int i=0;i<k;i++)
		{
			cout<<bfs(test[i]-1)-1<<endl;
		}
	}
}