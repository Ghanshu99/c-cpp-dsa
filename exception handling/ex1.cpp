#include<iostream>
using namespace std;
int main()
{
int x,y,q,r;
cout<<"enter dividend:";
cin>>x;
cout<<"enter divisor:";
cin>>y;
try
{
if(y==0) throw y;
q=x/y;
r=x%y;
cout<<"Quotient :"<<q<<endl;
cout<<"Remainder :"<<r<<endl;
}catch(int i)
{
cout<<"cannot devide by :"<<i<<endl;
}
return 0;
}