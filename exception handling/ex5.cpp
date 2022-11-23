#include<iostream>
using namespace std;
void sam(int e) //throw()
{
if(e==5)
{
throw e;
}
if(e==7)
{
throw "great";
}
cout<<"some processing"<<endl;
}
void dosomething()
{
cout<<"OPPS, something happened which was not expected"<<endl;
}
int main()
{
set_unexpected(dosomething);
try
{
sam(100);
sam(7);
sam(5);
}catch(int e)
{
cout<<"code within catch with int got executed"<<endl;
}catch(char const *)
{
cout<<"code within catch with char cosnt * got executed";
}
return 0;
}