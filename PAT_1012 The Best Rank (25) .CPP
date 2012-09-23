#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

#ifndef LOCAL
	#define LOCAL
#endif

#define MANX 2000+5

struct BestOrder
{
	int rank;
	char best;
};

struct Student
{
	string studentID; 
	int C;
	int M;
	int E;
	int A;
	BestOrder Order;
};

// what

map<string,BestOrder> Answer;

Student Students[MANX];

bool cmpByA(Student a, Student b)
{
	if(a.A > b.A) return true;
	return false;
}

bool cmpByC(Student a, Student b)
{
	if(a.C > b.C) return true;
	return false;
}

bool cmpByM(Student a, Student b)
{
	if(a.M > b.M) return true;
	return false;
}
bool cmpByE(Student a, Student b)
{
	if(a.E > b.E) return true;
	return false;
}


int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>Students[i].studentID>>Students[i].C>>Students[i].M>>Students[i].E; 
		Students[i].A =Students[i].C+Students[i].M+Students[i].E;
	}
	int newScore = 0;
	sort(Students,Students+n,cmpByA);
	for(int i=0;i<n;i++)
	{
		if(i==0 || Students[i].A < Students[i-1].A )
			newScore = i+1;
		Students[i].Order.rank = newScore;
		Students[i].Order.best = 'A';
		
	}

	sort(Students,Students+n,cmpByC);
	newScore = 0;
	for(int i=0;i<n;i++)
	{
		if(i==0 || Students[i].C < Students[i-1].C)
			newScore = i+1;
		if(Students[i].Order.rank > newScore)
		{
			Students[i].Order.rank = newScore;
			Students[i].Order.best = 'C';
			
		}
	}

	sort(Students,Students+n,cmpByM);		
	for(int i=0;i<n;i++)
	{
		if(i==0 || Students[i].M < Students[i-1].M )
			newScore = i+1;

		if(Students[i].Order.rank >newScore)
		{
			Students[i].Order.rank =newScore;
			Students[i].Order.best = 'M';
		}
	}

	sort(Students,Students+n,cmpByE);
	for(int i=0;i<n;i++)
	{
		if(i==0 || Students[i].E < Students[i-1].E )
			newScore = i+1;

		if(Students[i].Order.rank >newScore)
		{
			Students[i].Order.rank =newScore;
			Students[i].Order.best = 'E';
		}
	}

	for(int i=0;i<n;i++)
	{
		Answer[Students[i].studentID] = Students[i].Order;
	}
	string str;
	for(int i=0;i<m;i++)
	{
		cin>>str;
		if(Answer.find(str)!=Answer.end())
			cout<<Answer[str].rank<<" "<<Answer[str].best<<endl;
		else
			cout<<"N/A"<<endl;
	}		
#ifdef  LOCAL
	system("parse");
#endif
	
	return 0;
}

