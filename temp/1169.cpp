#include<stdio.h>
#include<string.h>
#define N 10000
char mes[N],key[N],cod[N],map[5][5];
int x[26],y[26],tot;
void init()
{
	int i,j,len,k=0,h;
	char str[1000],ch;
	len=strlen(key);
	for(i=0;i<len;i++)
	{
		for(j=0;j<i;j++)
		{
			if(key[j]==key[i])break;
if(key[j]=='I'&&key[i]=='J'||key[i]=='I'&&key[j]=='J')
break;
		}
		if(j==i)
		{
			if(key[i]=='J')
				str[k++]='I';
			else str[k++]=key[i];
		}
	}
	len=k;k=0;ch='A';
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			if(ch=='J')
			{
				ch++;j--;
				continue;
			}
			else if(i*5+j<len)
				map[i][j]=str[k++];
			else 
			do{
			for(h=0;h<len;h++)
				if(str[h]==ch)
					break;
				if(h==len)
					map[i][j]=ch;
				ch++;
				if(ch=='J')ch++;
			}while(h!=len);
		}
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			ch=map[i][j];
			if(ch=='I')
			{
				x['J'-'A']=i;
				y['J'-'A']=j;
			}
				x[ch-'A']=i;
				y[ch-'A']=j;
		}
}
void change()
{
	int i,j=0,len;
	char str[10000];
	len=strlen(mes);
	for(i=0;i<len;i++)
	{
		if(mes[i]==' ')
			continue;
		else str[j++]=mes[i];
	}
	str[j]='\0';
	len=j;j=0;
	for(i=0;i<len;i++)
	{
		cod[j++]=str[i];
		if(str[i]==str[i+1])
		{
			if(str[i]!='Q')
				cod[j++]='Q';
			else cod[j++]='Z';
		}
else if(str[i]=='I'&&str[i+1]=='J'||str[i+1]=='I'&&str[i]=='J')
cod[j++]='Q';
	}
	if(j%2)
	{
		if(cod[j-1]!='Q')
			cod[j++]='Q';
		else cod[j++]='Z';
	}
	tot=j;
}
void run()
{
	int i,tx1,ty1,tx2,ty2;
	init();
	change();
	for(i=0;i<tot;i+=2)
	{
		tx1=x[cod[i]-'A'];
		ty1=y[cod[i]-'A'];
		tx2=x[cod[i+1]-'A'];
		ty2=y[cod[i+1]-'A'];
		if(i)putchar(' ');
		if(tx1==tx2)
		{
			ty1++;
			ty2++;
			if(ty1>=5)ty1=0;
			if(ty2>=5)ty2=0;
printf("%c%c",map[tx1][ty1],map[tx2][ty2]);
		}
		else if(ty1==ty2)
		{
			tx1++;
			tx2++;
			if(tx1>=5)tx1=0;
			if(tx2>=5)tx2=0;
printf("%c%c",map[tx1][ty1],map[tx2][ty2]);
		}
else printf("%c%c",map[tx1][ty2],map[tx2][ty1]);
	}
	putchar('\n');
}
void main()
{
	gets(key);
	while(key[0]!='9')
	{
		gets(mes);
		run();
		gets(key);
	}
}