#include<iostream>
using namespace std;
class aaa
{
public:
void sam()
{
	cout<<"he is super coool"<<endl;
}
virtual void tom()
{
}
};
class bbb:public aaa
{
public:
	void tom()
	{
		cout<<"he is idiot"<<endl;
	}
};
int main()
{
aaa *p;
p=new bbb;
p->sam();
p->tom();
	return 0;
}

