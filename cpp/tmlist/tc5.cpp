int main()
{
TMArrayList list1;
bool k;
for(int x=100;x<=123;x++)
{
list1.add(x,&k);
}
cout<<"size is"<<list1.getSize()<<endl;
TMArrayList list2;
for(int u=908;u<=1034;u++) list2.add(u,&k);
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<" ";
cout<<endl<<"size is"<<list2.getSize()<<endl;
list2+=list1;
cout<<"after += list1 to list2"<<endl;
for(int x=0;x<list2.getSize();x++) cout<<list2.get(x,&k)<<" ";
cout<<endl<<"size is"<<list2.getSize()<<endl;
return 0;
}