#include<stdio.h>
#include<string.h>
char tex[2000];
int res[2000];
int count,len;
void muti()
{
	int i,t;
	for(i=0;i<count;i++)
		res[i]*=256;
	i=0;
	do
	{
		if(res[i]>=34943)
		{
			t=res[i];
			res[i]%=34943;
			res[++i]+=t/34943;
		}
		else i++;
	}while(i<=count+2);
	while(i&&!res[i])i--;
	count=i+1;
}
void change()
{
	int i;
	len=strlen(tex);
	count=1;
	memset(res,0,sizeof(res));
	for(i=0;i<len;i++)
	{
		muti();
		res[0]+=tex[i];
	}
	for(i=0;i<2;i++)
		muti();
}
void run()
{
	int m,x[4],i;
	change();
	m=res[0];
	if(m)m=34943-m;
	for(i=0;i<4;i++)
	{
		x[i]=m%16;
		m=(m-x[i])/16;
	}
	printf("%X%X %X%X\n",x[3],x[2],x[1],x[0]);

}
void main()
{
	gets(tex);
	while(tex[0]!='#')
	{
		run();
		gets(tex);
	}
}