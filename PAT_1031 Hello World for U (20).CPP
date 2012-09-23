#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  char dd[128];
  while(cin>>dd)
  {
    int len = strlen(dd);
    int mod = (len+2)%3;
    int tt = (len+2)/3;
    int n1,n2;
    n1 = tt;
    n2 = tt+mod;
    for(int i=0;i<n1-1;i++)
    {
      cout<<dd[i];
      for(int j=0;j<n2-2;j++)
        cout<<' ';
      cout<<dd[len-i-1]<<endl;
    }
    for(int i=0;i<n2;i++)
    {
      cout<<dd[n1-1+i];
    }
    cout<<endl;
  }
}