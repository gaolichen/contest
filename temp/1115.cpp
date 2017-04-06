#include<stdio.h>
#include<string.h>
int a;
void input()
{
	char ch;
	a=0;
	ch=getchar();
	while(ch!='\n')
	{
		if(ch>='0'&&ch<='9')
			a+=ch-'0';
		ch=getchar();
	}
}
void main()
{
	input();
	while(a)
	{
		if(a%9)
			printf("%d\n",a%9);
		else printf("9\n");
		input();
	}
}