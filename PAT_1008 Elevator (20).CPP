#include<iostream>
using namespace std;
int main()
{
  int num=0;
  while(cin>>num && num)
  {
    int dd[101];
    dd[0] = 0;
    for(int i=1;i<=num;i++)
    {
      cin>>dd[i];
    }
    int stoptime=num*5;
    for(int i=0;i<num;i++)
    {
      int tmp = dd[i+1]-dd[i];
      if(tmp>0)// up
        stoptime+=tmp*6;
      else  //down
        stoptime -=tmp*4;
    }
    cout<<stoptime<<endl;
  }
}