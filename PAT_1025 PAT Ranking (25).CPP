#include<iostream>
#include<string.h>
#include<cmath>
#include <algorithm>
#include<iomanip>
#include<queue>
using namespace std;

struct merge
{
	char id[14];
	int score;
	int final_rank;
	int loc_num;
	int loc_rank;
} hh[100*300+1];

//a<b
bool cmp(const struct merge  &a, const struct merge &b)
{
	if(a.score > b.score || (a.score == b.score && strcmp(a.id,b.id)<0))
		return true;
	return false;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int cas[100];
		int front=0;
		for(int i=0;i<n;i++)
		{
			cin>>cas[i];
			for(int j=0;j<cas[i];j++)
			{
				cin>>hh[front+j].id>>hh[front+j].score;
				hh[front+j].loc_num =i+1;
			}
			sort(hh+front,hh+front+cas[i],cmp);
			hh[front].loc_rank=1;
			for(int j=1;j<cas[i];j++)
			{
				if(hh[front+j].score==hh[front+j-1].score)
				{
					hh[front+j].loc_rank = hh[front+j-1].loc_rank;
				}else{
					hh[front+j].loc_rank = j+1;
				}
			}
			front +=cas[i];
		}

		sort(hh,hh+front,cmp);
		hh[0].final_rank=1;
		for(int j=1;j<front;j++)
		{
			if(hh[j].score==hh[j-1].score)
			{
				hh[j].final_rank = hh[j-1].final_rank;
			}else{
				hh[j].final_rank = j+1;
			}
		}
		cout<<front<<endl;
		for(int j=0;j<front;j++)
			cout<<hh[j].id<<' '<<hh[j].final_rank<<' '<<hh[j].loc_num<<' '<<hh[j].loc_rank<<endl;
	}
}