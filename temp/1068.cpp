#include<iostream.h>
#include<stdio.h>
int main()
{
	int i,n;
	while(scanf("%d\n",&n)==1)
	{
//		putchar(char(218));
		printf("%c  %c  %c  %c\n",179,180,191,218);
		for(i=0;i<n;i++)
			putchar(char(196));
		putchar(char(217));
		putchar('\n');putchar(char(192));putchar(char(218));
		for(i=0;i<n-1;i++)
			putchar(char(196));
		putchar(char(191));putchar(char(217));putchar('\n');
	}
	return 0;
}