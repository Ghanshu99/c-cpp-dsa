#include<iostream>
using namespace std;
class aaa
{
private:
int x;
public:
	void sam() const
	{
		x=10;
		cout<<x<<endl;
	}
	void tom() 
	{
		x=20;
	}
};
int main()    
{
aaa a;
a.sam();
a.tom();
return 0;
}