#include<stdio.h>
#include<string.h>
int count;
char word[110][10],dic[110][10],scr[10];
void run()
{
	int i,j,len,find=0;
	char ch;
	len=strlen(scr);
	for(i=1;i<len;i++)
		for(j=0;j<len-i;j++)
			if(scr[j]>scr[j+1])
			{
				ch=scr[j];
				scr[j]=scr[j+1];
				scr[j+1]=ch;
			}
	for(i=0;i<count;i++)
		if(strcmp(dic[i],scr)==0)
		{
			if(!find)find=1;
			puts(word[i]);
		}
	if(!find)puts("NOT A VALID WORD");
	puts("******");
}
void init()
{
	int i,j,k,len;
	char ch,str[10];
	for(i=1;i<count;i++)
		for(j=0;j<count-i;j++)
			if(strcmp(word[j],word[j+1])>0)
			{
				strcpy(str,word[j]);
				strcpy(word[j],word[j+1]);
				strcpy(word[j+1],str);
			}
	for(i=0;i<count;i++)
		strcpy(dic[i],word[i]);
	for(i=0;i<count;i++)
	{
		len=strlen(dic[i]);
		for(j=1;j<len;j++)
			for(k=0;k<len-j;k++)
				if(dic[i][k]>dic[i][k+1])
				{
					ch=dic[i][k];
					dic[i][k]=dic[i][k+1];
					dic[i][k+1]=ch;
				}
	}
}
void main()
{
	int i=0;
	gets(word[i]);
	while(word[i][0]!='X')
	{
		i++;gets(word[i]);
	}
	count=i;
	init();
	gets(scr);
	while(scr[0]!='X')
	{
		run();
		gets(scr);
	}
}