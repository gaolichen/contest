#include<stdio.h>
#define N 100
int a[N],b[N];
int n;
char str[2];
void run2()
{
	int i,j;
	b[n]=0;
	for(i=n-1;i>0;i--)
	{
		b[i]=a[i-1];
		for(j=i+1;j<=n;j++)
			if(b[j]>=b[i])
			b[j]++;
	}
	for(i=0;i<n;i++)
		for(j=1;j<=n;j++)
			if(b[j]==i)
			{
				if(i)putchar(' ');
				printf("%d",j);
			}
	putchar('\n');
}
void run1()
{
	int i,j,tot;
	for(i=0;i<n;i++)
	{
		tot=0;
		for(j=i-1;j>=0;j--)
			if(a[j]>a[i])
				tot++;
		b[a[i]-1]=tot;
	}
	for(i=0;i<n;i++)
	{
		if(i)putchar(' ');
		printf("%d",b[i]);
	}
	putchar('\n');
}
void run()
{
	if(str[0]=='P')
		run1();
	else run2();
}
void main()
{
	int i;
	scanf("%d",&n);
	while(n)
	{
		scanf("%s",str);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		run();
		scanf("%d",&n);
	}
}