#include<stdio.h>
int main()
{
	int a,count9=0,before9=-1,i;
	char ch1,ch2;
	while(1)
	{
		if((ch1=getchar())==-1)break;
		ch2=getchar();
		getchar();
		a=ch1-'0'+ch2-'0';
		if(a<9)
		{
			if(before9!=-1)
				putchar(before9+'0');
			for(i=0;i<count9;i++)
				putchar('9');
			before9=a;
			count9=0;
		}
		else if(a>=10)
		{
			a%=10;
			if(before9==-1)
				putchar('1');
			else putchar(before9+'1');
			for(i=0;i<count9;i++)
				putchar('0');
			before9=a;
			count9=0;
		}
		else count9++;
	}
	putchar(a+'0');
	putchar('\n');
	return 0;
}