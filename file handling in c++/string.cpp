#include<iostream>
using namespace std;
int main()
{
string a;
cout<<a.capacity()<<endl;
a="Ujjain";
cout<<a<<endl;
cout<<a.size()<<endl;
cout<<a.length()<<endl;
cout<<a.capacity()<<endl;
cout<<a.max_size()<<endl;
a=a+"-Indore";
cout<<a<<endl;
cout<<a.capacity()<<endl;
a.reserve(1000);
cout<<a.capacity()<<endl;
return 0;
}