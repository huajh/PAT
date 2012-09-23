#include<iostream>
#include<string.h>
#include<cmath>
#include <algorithm>
#include<iomanip>
#include<queue>
using namespace std;

int main()
{
		double dd[3][3];
		char c[3];
		double profit =1.0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>dd[i][j];
			}
		}
		for(int i=0;i<3;i++)
		{
			double maxx = 0;
			for(int j=0;j<3;j++)
			{
				if(maxx<dd[i][j])
				{
					maxx = dd[i][j];
					if(j==0) c[i]='W';
					else if(j==1) c[i]='T';
					else
						c[i]='L';
				}
			}
			profit*=maxx;
		}
		profit = (profit*0.65-1)*2;
		cout<<c[0]<<' '<<c[1]<<' '<<c[2]<<' '<<fixed<<setprecision(2)<<profit<<endl;  //
}