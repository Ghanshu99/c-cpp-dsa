#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
forward_list<int> list={10,20,30,40,50};
cout<<list.front()<<endl;
cout<<"****************"<<endl;
list.front()=300;
list.front()=5000;
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}