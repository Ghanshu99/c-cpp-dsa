#include<utility>
#include<map>
#include<iostream>
using namespace std;
int main()
{
map<int,int> m;
m.insert(pair<int,int>(101,4030));
m.insert(pair<int,int>(102,3013));
m.insert(pair<int,int>(103,3030));
map<int,int>::iterator i;
i=m.find(102);
if(i==m.end()) cout<<"Item code :103 not found"<<endl;
else cout<<"price of item with code :103 is"<<i->second<<endl;
return 0;
}