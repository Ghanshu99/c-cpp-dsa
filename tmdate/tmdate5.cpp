#include<iostream>
#include<string.h>
using namespace std;
class TMDate
{
private:
int dayOfMonth;
int month;
int year;
int dayNumber;
int isLeapYear(int);
void toDayNumber();
void fromDayNumber();
void isValidDate(const char *dateString,int *isValid,int *d,int *m,int *y);
public:
/*int getDayNumber() //remove after testing
{
return this->dayNumber;
}
*/
// constructor methods
TMDate();
TMDate(const char *dateString);
TMDate(const TMDate &other);
TMDate & operator=(const TMDate &other);
virtual ~TMDate();
// non constructor methods
int getDayOfMonth();
int getMonth();
int getYear();
int getDayOfWeek();
void getMonthString(char *monthString);
void getMonthShortString(char *monthShortString);
void getDayOfWeekString(char *dayOfWeekString);
void getDayOfWeekShortString(char *dayOfWeekShortString);
int isLeapYear();
//operator functions
TMDate & operator=(const char *dateString);
void operator+=(int);
void operator-=(int);
int operator<(const TMDate &other);
int operator>(const TMDate &other);
int operator<=(const TMDate &other);
int operator>=(const TMDate &other);
int operator==(const TMDate &other);
int operator!=(const TMDate &other);
TMDate operator+(int days);
TMDate operator-(int days);
};
TMDate::~TMDate()
{
//do nothing
}
TMDate::TMDate()
{
time_t x;
time(&x);
struct tm *now;
now=localtime(&x);
dayOfMonth=now->tm_mday;
month=now->tm_mon+1;
year=now->tm_year+1900;
this->toDayNumber();
}
TMDate::TMDate(const char *dateString)
{
int d,m,y,isValid;
isValidDate(dateString,&isValid,&d,&m,&y);
if(isValid)
{
this->dayOfMonth=d;  
this->month=m;
this->year=y;
this->toDayNumber();
}
else
{
this->dayNumber=0;
this->dayOfMonth=0;
this->month=0;
this->year=0;
}
}
TMDate & TMDate::operator=(const char *dateString) //done done
{
int d,m,y,isValid;
isValidDate(dateString,&isValid,&d,&m,&y);
if(isValid)
{
this->dayOfMonth=d;  
this->month=m;
this->year=y;
this->toDayNumber();
}
else
{
this->dayNumber=0;
this->dayOfMonth=0;
this->month=0;
this->year=0;
}
return *this;	
}
TMDate::TMDate(const TMDate &other)
{
this->dayNumber=other.dayNumber;
this->dayOfMonth=other.dayOfMonth;
this->year=other.year;
this->month=other.month;
}
TMDate & TMDate::operator=(const TMDate &other)
{
this->dayNumber=other.dayNumber;
this->dayOfMonth=other.dayOfMonth;
this->year=other.year;
this->month=other.month;
return *this;
}
void TMDate::isValidDate(const char *dateString,int *isValid,int *d,int *m,int *y)
{
int dd,mm,yy;
int sepIndex1,sepIndex2,i,r;
char mth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char sep;
*isValid=0;
if(dateString==NULL) return;
int x=strlen(dateString);
if(x<8 || x>10) return;
if(!(dateString[1]=='/' || dateString[2]=='/' || dateString[1]=='-' || dateString[2]=='-')) return;
if(dateString[1]=='/' || dateString[1]=='-') sepIndex1=1;
else sepIndex1=2;
sep=dateString[sepIndex1];
if(dateString[0]<48 || dateString[0]>57) return;
if(sepIndex1==2 && (dateString[1]<48 || dateString[1]>57))
return;
if(sepIndex1==1)
{
dd=dateString[0]-48;
if(dd==0) return;
}
else
{
dd=(((dateString[0]-48)*10)+(dateString[1]-48));
if(dd==0) return;
}
i=sepIndex1+1;
if(!(dateString[i+1]==sep || dateString[i+2]==sep)) return;
if(dateString[i+1]==sep) sepIndex2=i+1;
else sepIndex2=i+2;
if(dateString[i]<48 || dateString[i]>57) return; 
if(sepIndex2==i+2 && (dateString[i+1]<48 || dateString[i+1]>57))
return;
if(sepIndex2==i+1)
{
mm=dateString[i]-48;
}
else
{
mm=((dateString[i]-48)*10)+(dateString[i+1]-48);
}
if(mm<1 || mm>12) return;
i=sepIndex2+1;
yy=0;
r=0;
while(r<=3)
{
if(dateString[i+r]<48 || dateString[i+r]>57) return;
yy=(yy*10)+(dateString[i+r]-48);
r++;
}
if(yy<1901) return;
if(yy%400==0) mth[1]=29;
if(yy%100==0) mth[1]=28;
if(yy%4==0) mth[1]=29;
else mth[1]=28;
if(dd<1 || dd>mth[mm-1]) return;
*d=dd;
*m=mm;
*y=yy;
*isValid=1;
}
int TMDate::isLeapYear(int y)
{
if(y%400==0) return 1;
else if(y%100==0) return 0;
else if(y%4==0) return 1;
else return 0; 
}
void TMDate::fromDayNumber()
{
if(this->dayNumber<=0)
{
this->dayOfMonth==0;
this->month=0;
this->year=0;
return ;
}
int x=this->dayNumber;
int d,m,y;
int daysInYear;
int daysInMonth;
y=1901;
while(1)
{
if(isLeapYear(y)) daysInYear=366;
else daysInYear=365;
if(x<daysInYear) break;
x=x-daysInYear;
y=y+1;
}
int mth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if(isLeapYear(y)) mth[1]=29;
m=0;
while(1)
{
daysInMonth=mth[m];
if(x<=daysInMonth) break;
x=x-daysInMonth;
m++;
}
m++;
d=x;
this->dayOfMonth=d;
this->month=m;
this->year=y;
}
void TMDate::toDayNumber()
{
int x=0;
int y=1901;
int m;
while(y<this->year)
{
if(isLeapYear(y)) x=x+366;
else x=x+365;
y++;
}
int mth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if(isLeapYear(y)) mth[1]=29;
int ep=this->month-2;
m=0;
while(m<=ep)
{
x=x+mth[m];
m++;
}
x=x+this->dayOfMonth;
this->dayNumber=x;
}
int TMDate::getDayOfMonth()
{
return this->dayOfMonth;
}
int TMDate::getMonth()
{
return this->month;
}
int TMDate::getYear()
{
return this->year;
}
ostream & operator<<(ostream &oo,TMDate &tmDate)
{
oo<<tmDate.getDayOfMonth()<<"/"<<tmDate.getMonth()<<"/"<<tmDate.getYear();
return oo;
}
void TMDate::operator+=(int days)
{
if(this->dayNumber==0) return;
this->dayNumber+=days;
this->fromDayNumber();
}
void TMDate::operator-=(int days)
{
if(this->dayNumber==0) return;
this->dayNumber-=days;
this->fromDayNumber();
}
TMDate TMDate::operator+(int days)
{
if(this->dayNumber==0) return TMDate("00/00/0000");
TMDate date;
date.dayNumber=this->dayNumber+days;
date.fromDayNumber();
return date;
}
TMDate TMDate::operator-(int days)
{
if(this->dayNumber==0) return TMDate("00/00/0000");
TMDate date;
date.dayNumber=this->dayNumber-days;
date.fromDayNumber();
return date;
}
int TMDate::operator<(const TMDate &other)
{
return this->dayNumber<other.dayNumber;
}
int TMDate::operator>(const TMDate &other)
{
return this->dayNumber>other.dayNumber;
}
int TMDate::operator<=(const TMDate &other)
{
return this->dayNumber<=other.dayNumber;
}
int TMDate::operator>=(const TMDate &other)
{
return this->dayNumber>=other.dayNumber;
}
int TMDate::operator==(const TMDate &other)
{
return this->dayNumber==other.dayNumber;
}
int TMDate::operator!=(const TMDate &other)
{
return this->dayNumber!=other.dayNumber;
}
void TMDate::getMonthString(char *monthString)
{
if(this->dayNumber==0)
{
*monthString='\0';
return;
}
if(this->month==1) strcpy(monthString,"January");
if(this->month==2) strcpy(monthString,"February");
if(this->month==3) strcpy(monthString,"March");
if(this->month==4) strcpy(monthString,"April");
if(this->month==5) strcpy(monthString,"May");
if(this->month==6) strcpy(monthString,"June");
if(this->month==7) strcpy(monthString,"July");
if(this->month==8) strcpy(monthString,"August");
if(this->month==9) strcpy(monthString,"September");
if(this->month==10) strcpy(monthString,"October");
if(this->month==11) strcpy(monthString,"November");
if(this->month==12) strcpy(monthString,"December");
}
void TMDate::getMonthShortString(char *monthShortString)
{
if(this->dayNumber==0)
{
*monthShortString='\0';
return;
}
if(this->month==1) strcpy(monthShortString,"Jan");
if(this->month==2) strcpy(monthShortString,"Feb");
if(this->month==3) strcpy(monthShortString,"Mar");
if(this->month==4) strcpy(monthShortString,"Apr");
if(this->month==5) strcpy(monthShortString,"May");
if(this->month==6) strcpy(monthShortString,"Jun");
if(this->month==7) strcpy(monthShortString,"Jul");
if(this->month==8) strcpy(monthShortString,"Aug");
if(this->month==9) strcpy(monthShortString,"Sep");
if(this->month==10) strcpy(monthShortString,"Oct");
if(this->month==11) strcpy(monthShortString,"Nov");
if(this->month==12) strcpy(monthShortString,"Dec");
}
int TMDate::getDayOfWeek()
{
if(this->dayNumber==0) return 0;
int leftDays=this->dayNumber%7;
int dow=2+leftDays; //2 (Monday) as 1/1/1901 is Tue(3)
if(dow>7) dow=dow%7;
return dow;
}
void TMDate::getDayOfWeekString(char *dayOfWeekString)
{
if(this->dayNumber==0)
{
*dayOfWeekString='\0';
return;
}
int dow=getDayOfWeek();
if(dow==1) strcpy(dayOfWeekString,"Sunday");
else if(dow==2) strcpy(dayOfWeekString,"Monday");
else if(dow==3) strcpy(dayOfWeekString,"Tuesday");
else if(dow==4) strcpy(dayOfWeekString,"Wednesday");
else if(dow==5) strcpy(dayOfWeekString,"Thursday");
else if(dow==6) strcpy(dayOfWeekString,"Friday");
else strcpy(dayOfWeekString,"Saturday");
}
void TMDate::getDayOfWeekShortString(char *dayOfWeekShortString)
{
if(this->dayNumber==0)
{
*dayOfWeekShortString='\0';
return;
}
int dow=getDayOfWeek();
if(dow==1) strcpy(dayOfWeekShortString,"Sun");
else if(dow==2) strcpy(dayOfWeekShortString,"Mon");
else if(dow==3) strcpy(dayOfWeekShortString,"Tue");
else if(dow==4) strcpy(dayOfWeekShortString,"Wed");
else if(dow==5) strcpy(dayOfWeekShortString,"Thu");
else if(dow==6) strcpy(dayOfWeekShortString,"Fri");
else strcpy(dayOfWeekShortString,"Sat");
}

int main()
{
TMDate date1="29/05/2020";
cout<<date1.getDayOfWeek()<<endl;
char a[21];
date1.getDayOfWeekString(a);
cout<<a<<endl;
date1.getDayOfWeekShortString(a);
cout<<a<<endl;
//TMDate 
date1="30/05/2020";
cout<<date1<<endl;
TMDate date2;
date2=date1+10;
cout<<date2<<endl;
TMDate date3;
date3=date1-10;
cout<<date3<<endl;
return 0;
}