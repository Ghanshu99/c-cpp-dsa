int main()
{
TMForwardList list1;
bool k;
for(int x=101;x<=110;x++)
{
list1.add(x,&k);
}
cout<<"size is"<<list1.getSize()<<endl;
cout<<"contents of list1"<<endl;
for(int x=0;x<list1.getSize();x++) cout<<list1.get(x,&k)<<endl;
cout<<"******************************"<<endl;
TMForwardList list2(list1);
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<endl;
cout<<"******************************"<<endl;
list2.add(2020,&k);
list2.removeAt(2,&k);
list1=list2;
for(int x=0;x<list1.getSize();x++) cout<<list1.get(x,&k)<<endl;
cout<<"*******************************"<<endl;
return 0;
}
