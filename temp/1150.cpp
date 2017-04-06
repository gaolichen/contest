#include<stdio.h>
char x[10][3],node[200],num[200][10];
int ord[10],m,n,f[200];
void run()
{
	int i,j,temp[10],t;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			temp[j]=num[i][ord[j]-1]-'0';
		for(j=0,t=0;j<n;j++)
			t=t*2+temp[j];
		printf("%d",f[t]);
	}
	putchar('\n');
}
void init()
{
	int i;
	for(i=0;node[i]!='\0';i++)
		f[i]=node[i]-'0';
	for(i=0;i<n;i++)
		ord[i]=x[i][1]-'0';
}
void main()
{
	int i,count=0;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%s",x[i]);
		scanf("%s",node);
		init();
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%s",num[i]);
		printf("S-Tree #%d:\n",++count);
		run();
		putchar('\n');
		scanf("%d",&n);
	}
}