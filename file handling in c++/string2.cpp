#include<iostream>
using namespace std;
int main()
{
	string a="Ujjain";
	cout<<a<<endl;
	cout<<a.capacity()<<endl;
	a.resize(4);
	cout<<"("<<a<<")"<<endl;
	cout<<a.capacity()<<endl;
	a.resize(7);
	cout<<"("<<a<<")"<<endl;
	cout<<a.capacity()<<endl;
	return 0;
}