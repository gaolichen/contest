#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=0;
char fat[100011][24];
void init(char *str)
{
	int i=0,j;
	char ch;
	while(str[i]!=' ')i++;
	ch=str[i];
	str[i]='\0';
	strcpy(fat[count]+12,str);
	str[i]=' ';
	j=i;while(str[j]==' ')j++;
	strcpy(fat[count++],str+j);
}
void run(char *str)
{
	int top=count-1,low=0,mid;
	if(strcmp(fat[top],str)<0)
	{
		puts("eh");
		return;
	}
	if(strcmp(fat[low],str)>0)
	{
		puts("eh");
		return;
	}
	mid=(top+low)/2;
	while(mid>low)
	{
		if(strcmp(fat[mid],str)==0)
		{
			puts(fat[mid]+12);return;
		}
		else if(strcmp(fat[mid],str)>0)
			top=mid;
		else low=mid;
		mid=(top+low)/2;
	}
	if(strcmp(fat[mid],str)==0)
		puts(fat[mid]+12);
	else if(strcmp(fat[top],str)==0)
		puts(fat[top]+12);
	else puts("eh");
}

int f(const void *str1,const void *str2)
{
	return strcmp((char*)str1,(char*)str2);
}
void main()
{
	char str[80];
	gets(str);
	while(str[0]!='\0')
	{
		init(str);
		gets(str);
	}
	qsort(fat,count,sizeof(char)*24,f);
	while(gets(str))
		run(str);
}