#include<iostream>
using namespace std;
class maruti800
{
public:
	void manual()
	{
		cout<<"maruti800 is selected"<<endl;
	}
};
class hondacity
{
public:
	void manual()
	{
		cout<<"honadacity is selected"<<endl;
	}
};
int main()
{
int ch;
maruti800 m;
hondacity h;
cout<<"1.maruti800"<<endl;
cout<<"2.hondacity"<<endl;
cout<<"enter your choice"<<endl;
cin>>ch;
if(ch==1)
{
	m.manual();
}else
if(ch==2)
{
	h.manual();
}
else cout<<"invalid choice"<<endl;
return 0;
}