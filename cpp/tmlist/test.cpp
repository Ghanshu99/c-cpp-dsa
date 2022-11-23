#include<iostream>
using namespace std;
int lastCode=0;
class aaa
{
private:
int code;
public:
aaa()
{
this->code=lastCode+1;
lastCode++;
cout<<"Default constructor ,code alloted :"<<this->code<<endl;
}
aaa(const aaa &other)
{
this->code=lastCode+1;
lastCode++;
cout<<"copy constructor ,code alloted :"<<this->code<<endl;
cout<<"Other's code :"<<other.code<<endl;
}
virtual ~aaa()
{
cout<<"Destructor got invoked for object with code :"<<this->code<<endl;
}
aaa & operator=(const aaa &other)
{
cout<<"operator = got called for object with code :"<<this->code<<endl;
cout<<"Other's code :"<<other.code<<endl;
cout<<"operator = for object with code "<<this->code<<"ends"<<endl;
return *this;
}
aaa operator+(const aaa &other)
{
cout<<"operator + got called for object with code :"<<this->code<<endl;
cout<<"other's code :"<<other.code<<endl;
aaa k;
return k; 
}
};
int main()
{
	aaa a1,a2,a3;
	cout<<"Objects created"<<endl;
	a1=a2+a3;
	cout<<"The end"<<endl;
	return 0; 
}