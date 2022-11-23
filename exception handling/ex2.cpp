#include<iostream>
using namespace std;
int calculate(int dividend,int divisor,int *quotient,int *remainder)
{
if(divisor==0) throw divisor;
*quotient=dividend/divisor;
*remainder=dividend%divisor;
}
int main()
{
int x,y,q,r;
cout<<"enter dividend :";
cin>>x;
cout<<"enter divisor:";
cin>>y;
try
{
if(y==0) throw y;
calculate(x,y,&q,&r);
cout<<"quotient :"<<q<<endl;
cout<<"remainder :"<<r<<endl;
}catch(int i)
{
cout<<"cannot divide by :"<<i<<endl;
}
return 0;
}