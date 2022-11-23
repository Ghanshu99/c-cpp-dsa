#include<iostream>
using namespace std;
class aaa
{
public:
virtual void sam(int) throw(int)=0;
};
class bbb:public aaa
{
public:
void sam(int e) throw()
{
if(e==5) throw e;
cout<<"some processing "<<endl;
}
};
int main()
{
bbb b;
b.sam(50);
b.sam(5);
return 0;
}