#include<iostream>
#include<queue>
#include<string.h>
#include<iomanip>
using namespace std;
#define maxn 10000+1

int maxx[maxn];
int hh[maxn];
int main()
{
	int n;
	while(cin>>n)
	{
		int a,b,m = -1;
		for(int i =0;i<n;i++)
		{
			cin>>hh[i];
			maxx[i] = hh[i];
			if(m<hh[i]) 
			{
				m = hh[i];
				a=i;
				b=i;
			}
		}
		if(m==-1)
		{
			cout<<0<<' '<<hh[0]<<' '<<hh[n-1]<<endl;;
		}
		else{
			for(int d=1;d<n;d++)
			{				
				for(int j=n-d-1;j>=0;j--)
				{
					maxx[j+d] = maxx[j+d-1] + hh[j+d] ; //j-i 
					if(m < maxx[j+d])
					{						
						m = maxx[j+d];
						a=j;
						b=j+d;
					}else if(m==maxx[j+d])
					{
						if(a>j || (a==j && b>j+d))
						{
							a=j;
							b=j+d;
						}
					}
				}
			}
			cout<<m<<' '<<hh[a]<<' '<<hh[b]<<endl;
		}
		
	}

}