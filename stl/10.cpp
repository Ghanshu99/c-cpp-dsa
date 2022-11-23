#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
forward_list<int> list={10,13,13,13,17,22,53,13,53,20};
list.unique();
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}