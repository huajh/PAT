#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10000+1
#define MAX_LEN 20
int seg[MAXN];

// <
bool cmp(int data1,int data2)
{
	if(data1 == data2) return false;
	char a[MAX_LEN],b[MAX_LEN];	
	sprintf(a,"%d%d",data1,data2);
	sprintf(b,"%d%d",data2,data1);
	int len = strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i] < b[i])
		{
			return true;
		}else if(a[i] > b[i])
		{
			return false;
		}
	}
	return false;
}
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&seg[i]);			
	}
	sort(seg,seg+n,cmp);
	int p = false;
	for(int i=0;i<n;i++)
	{
		if(seg[i]!=0)
		{
			p = true;
			printf("%d",seg[i]);
		}
	}
	if(!p)
		puts("0");
	else
		puts("");
	
	return 0;
}