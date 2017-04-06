#include<stdio.h>
#include<string.h>
char sen[100000],word[6000][100];
int wl[6000];
void run()
{
	int i=0,j=0,k=0,len;
	len=strlen(sen);
	do
	{
		while(sen[i]!=' '&&i<len)
			i++;
		sen[i]='\0';
		strcpy(word[j],sen+k);
		wl[j]=strlen(word[j]);
		j++;
		sen[i]=' ';
		k=i;
		while(sen[k]==' ')k++;
		i=k;
	}while(i<len);
	for(i=0;i<j;i++)
	{
		if(i)putchar(' ');
		for(k=wl[i]-1;k>=0;k--)
			putchar(word[i][k]);
	}
	putchar('\n');
}
void main()
{
	int now,t,n,i,len;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		if(now)putchar('\n');
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			gets(sen);
			len=strlen(sen);
			if(len)run();
			else i--;
		}
	}
}