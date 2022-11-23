typedef struct _request
{
	char *method;
	char *resource;
	char isClientSideTechnologyResource;
	char *mimeType;
}REQUEST;
int extentionEquals(const char *left,const char *right)
{
char a,b;
while(*left && *right)
{
a=*left;
b=*right;
if(a>=65 && a<=90) a+=32;
if(b>=65 && b<=90) b+=32;
left++;
right++;
}
}