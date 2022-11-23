#include<iostream>
using namespace std;
int main()
{
int req,*x,y;
cout<<"enter requirement :";
cin>>req;
try
{
x=new int[req];
}catch(bad_alloc &ba)
{
cout<<"invalid requirement"<<endl;
cout<<ba.what()<<endl;
return 0;
}
for(y=0;y<req;y++)
{
cout<<"enter a number :";
cin>>x[y];
}
int total=0;
for(y=0;y<req;y++)
{
total=total+x[y];
}
cout<<"total is :"<<total<<endl;
return 0;
}
