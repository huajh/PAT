#include<iostream>
using namespace std;
int main()
{
  int a[3];
  while(cin>>a[0]>>a[1]>>a[2])
  {
    
    cout<<"#";
    for(int i=0;i<3;i++)
    {
      int sec=0,fir=0;
      sec = a[i]/13;
      fir= a[i]%13;
      if(sec>=10) printf("%c",'A'+sec-10);
      else cout<<sec;
      if(fir>=10) printf("%c",'A'+fir-10);
      else cout<<fir;     
    }
    cout<<endl;
      
  }
}