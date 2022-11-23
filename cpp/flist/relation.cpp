#include<iostream>
using namespace std;
class aaa
{
public:
aaa()
{
cout<<"Default constructor of aaa"<<endl;
}
aaa(const aaa &other)
{
cout<<"Copy constructor of aaa"<<endl;
}
};
class bbb:public aaa
{
public:
bbb()
{
cout<<"Default constructor of bbb"<<endl;
}
bbb(const bbb &other)
{
cout<<"Copy constructor of bbb"<<endl;
}
bbb(const aaa &other)
{
cout<<"Parameterized constructor of bbb with parameter as aaa&"<<endl;
}
bbb & operator=(const bbb &other)
{
cout<<"operator = of class bbb with parameter bbb &"<<endl;
return *this;
}
};
class ccc:public aaa
{
public:
ccc()
{
cout<<"Default constructor of ccc"<<endl;
}
ccc(const ccc &other)
{
cout<<"Copy constructor of ccc"<<endl;
}
ccc(const aaa &other)
{
cout<<"Parameterized constructor of ccc with parameter aaa&"<<endl;
}
ccc & operator=(const ccc &other)
{
cout<<"operator = of class with parameter type ccc&"<<endl;
return *this;
}
};
int main()
{
bbb b;
ccc c(b);
cout<<"***************"<<endl;
ccc d;
bbb e(d);
cout<<"***************"<<endl;
ccc f;
f=e;           //f=ccc(e);
cout<<"*****************************"<<endl;
bbb g;
g=f;          //g=bbb(f);
return 0;
}