#include<iostream>
using namespace std;
class DAOException:public exception
{
private:
string message;
public:
	DAOException(string message)
	{
	this->message=message;
	}
	DAOException(const DAOException &other)
	{
	this->message=other.message;
	}
	DAOException & operator=(const DAOException &other)
	{
	this->message=other.message;
	return *this;
	}
	virtual ~DAOException() throw()
	{
	}
	const char *what() const throw()
	{
	return this->message.c_str();
	}
};
int main()
{
	DAOException d(string("some problem"));
	int x;
	cout<<"enter data:";
	cin>>x;
	try
	{
	if(x==5) throw d;
	}catch(DAOException &k)
	{
	cout<<"DAOException got raised"<<endl;
	cout<<"k.what()"<<endl;
	}
	return 0;
}