#include<iostream>
#include<forward_list>
using namespace std;
int whatever(int e) //predicate(here boolean predicate)
{
return e%2==0;
}
int main()
{
forward_list<int> list={10,13,17,22,53,44,20,30,51,40,50};
list.remove_if(whatever);
forward_list<int>::iterator i=list.begin();
while(i!=list.end())
{
cout<<*i<<endl;
++i;
}
return 0;
}