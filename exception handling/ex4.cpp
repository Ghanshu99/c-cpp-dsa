#include<iostream>
using namespace std;
void sam(int e) throw()
{
if(e==5) 
{
throw e;
}
if(e==7)
{
throw "Great";
}
cout<<"some processing"<<endl;
}
void doSomething()
{
cout<<"OOPS ,something happened which was not expected"<<endl;
}
int main()
{
set_unexpected(doSomething);
sam(100);
sam(7);
sam(20);
sam(5);
return 0;
}