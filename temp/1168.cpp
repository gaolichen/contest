#include<stdio.h>
#include<string.h>
int nod[300],count,len,tot[300];
char path[300][30];
void init(char *str)
{
	int i,j=0;
	nod[count]=0;
	for(i=0;i<len;i++)
	{
		if(str[i]==')')
		{
			path[count][j]='\0';
			tot[count]=strlen(path[count]);
			count++;
			nod[count]=0;
			j=0;
		}
		else if(str[i]>='0'&&str[i]<='9')
	nod[count]=10*nod[count]+str[i]-'0';
		else if(str[i]=='L'||str[i]=='R')
			path[count][j++]=str[i];
	}
}
int check()
{
	int i,j;
	char str[50];
	if(tot[count-1])return 0;
	for(i=count-2;i>=0;i--)
		for(j=i+1;j<count;j++)
		if(strcmp(path[i],path[j])==0)
			return 0;
	for(i=count-2;i>=0;i--)
	{
		strcpy(str,path[i]);
		str[tot[i]-1]='\0';
		for(j=i+1;j<count;j++)
			if(strcmp(str,path[j])==0)
				break;
		if(j==count)return 0;
	}
	return 1;
}
void mysort()
{
	int i,j=-1,t;
	char buf[30];
	for(i=1;i<count;i++)
		for(j=0;j<count-i;j++)
		{
			if(tot[j]<tot[j+1])
			{
			t=tot[j];tot[j]=tot[j+1];
			tot[j+1]=t;t=nod[j];
			nod[j]=nod[j+1];nod[j+1]=t;
			strcpy(buf,path[j]);
			strcpy(path[j],path[j+1]);
			strcpy(path[j+1],buf);
			}
			else 
if(tot[j]==tot[j+1]&&strcmp(path[j],path[j+1])<0)
			{
			t=nod[j];nod[j]=nod[j+1];
				nod[j+1]=t;
				strcpy(buf,path[j]);
			strcpy(path[j],path[j+1]);
			strcpy(path[j+1],buf);
			}
		}
}
void run()
{
	int i;
	mysort();
	if(check())
	{
	for(i=count-1;i>=0;i--)
	{
		if(i!=count-1)
			putchar(' ');
		printf("%d",nod[i]);
	}
	putchar('\n');
	}
	else printf("not complete\n");
}
void main()
{
	char buf[500];
	while(gets(buf))
	{
		len=strlen(buf);
		init(buf);
		if(buf[len-2]=='(')
		{
			count--;
			run();
			count=0;
		}
	}
}