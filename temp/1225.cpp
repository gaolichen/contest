#include<stdio.h>
#include<string.h> 
char word[10000][50],str[100000];
int num[10000],p[10000];
void run()
{
	int i,j=0,count=0,t=0,temp,flag=0,totn,totw,k;
	char a[50],b[50];
	for(i=0;str[i]!='\0';i++)
		if(str[i]!=' ')
		{
			if(str[i]==','||str[i]=='.')
			{
				if(flag)
				{
					num[j++]=t*flag;
					p[count]=1;
				}
				count++;
				t=0;flag=0;
			}
			if(str[i]>='0'&&str[i]<='9')
			{
				t=10*t+str[i]-'0';
				if(!flag)flag=1;
			}
			if(str[i]=='-')
				flag=-1;
		}
	totn=j;
	t=0;count=0;j=0;flag=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]!=' ')
		{
			if(str[i]==','||str[i]=='.')
			{
				if(flag)
				{
				str[i]='\0';
				strcpy(word[j++],str+t);
				str[i]=',';
				p[count]=0;
				}
				count++;
				flag=0;
			}
			if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
			{
				if(!flag)
				{flag=1;t=i;}
			}
		}
		totw=j;
	for(i=1;i<totn;i++)
		for(j=0;j<totn-i;j++)
			if(num[j]>num[j+1])
			{
				temp=num[j];num[j]=num[j+1];
				num[j+1]=temp;
			}
	for(i=1;i<totw;i++)
		for(j=0;j<totw-i;j++)
		{
			strcpy(a,word[j]);
			strcpy(b,word[j+1]);
			for(k=0;a[k]!='\0';k++)
				if(a[k]>='A'&&a[k]<='Z')
					a[k]=a[k]+'a'-'A';
			for(k=0;b[k]!='\0';k++)
				if(b[k]>='A'&&b[k]<='Z')
					b[k]=b[k]+'a'-'A';
			if(strcmp(a,b)>0)
			{
				strcpy(a,word[j]);strcpy(word[j],word[j+1]);
				strcpy(word[j+1],a);
			}
			else if(strcmp(a,b)==0&&strcmp(word[j],word[j+1])>0)
			{
				strcpy(a,word[j]);strcpy(word[j],word[j+1]);
				strcpy(word[j+1],a);
			}
		}
	j=0;t=0;
	if(p[0]==1)
	{
		printf("%d",num[0]);
		j=1;
	}
	else 
	{
		printf("%s",word[0]);
		t=1;
	}
	for(i=1;i<count;i++)
	{
		if(p[i]==1)
			printf(", %d",num[j++]);
		else printf(", %s",word[t++]);
	}
	printf(".\n");
}
void main()
{
	gets(str);
	while(str[0]!='.')
	{
		run();
		gets(str);
	}
}