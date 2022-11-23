#include<iostream>
using namespace std;
class aaa
{
public:
virtual aaa & operator=(const aaa &)=0;
};
class bbb:public aaa
{
public:
bbb & operator=(const bbb &other)
{
}
aaa & operator=(const aaa &other)
{
}
};
class ccc:public aaa
{

}