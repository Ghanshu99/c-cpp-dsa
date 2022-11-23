#include<utility>
#include<map>
#include<iostream>
using namespace std;
int main()
{
map<int,int> m;
m[1]=10;
m[2]=20;
m[3]=30;
m[4]=40;
map<int,int>:: iterator i;
i=m.find(3);
if(i==m.end()) cout<<"Item code: 3 not found"<<endl;
else cout<<"price of item with code :"<<(*i).first<<"is "<<i->second<<endl;
return 0;
}