int main()
{
TMForwardList list1;
bool k;
for(int x=101;x<=110;x++)
{
list1.add(x,&k);
}
//cout<<"size is"<<list1.getSize()<<endl;
TMForwardList list2;
list2.add(2020,&k);
list2.add(3030,&k);
list2.add(4040,&k);
/*to test += operator
list1+=list2;
for(int e=0;e<list1.getSize();e++)
{
cout<<list1.get(e,&k)<<endl;
}
*/
TMForwardList list3;
list3=list2+list1;
for(int e=0;e<list3.getSize();e++)
{
cout<<list3.get(e,&k)<<endl;
}
re