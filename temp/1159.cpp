#include<stdio.h>
#include<stdlib.h>
char num[120000][10];
int map[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,
8,8,8,9,9,9,9};
int tel[120000],n;
int cmp(const void *t1,const void *t2)
{
	int *a,*b;
	a=(int*)t1;b=(int*)t2;
	if(*a>=*b)return 1;
	return -1;
}
void run()
{
	int i,j,t,p[7],find=0;
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;num[i][j]!='\0';j++)
		{
			if(num[i][j]>='0'&&num[i][j]<='9')
				t=t*10+num[i][j]-'0';
	else if(num[i][j]>='A'&&num[i][j]<'Z'&&num[i][j]!='Q')
				t=10*t+map[num[i][j]-'A'];
		}
		tel[i]=t;
	}
	qsort(tel,n,sizeof(int),cmp);
	t=1;
	for(i=1;i<n;i++)
	{
		if(tel[i]==tel[i-1])
			t++;
		else if(t>1)
		{
			for(j=0;j<7;j++)
			{
				p[j]=tel[i-1]%10;
				tel[i-1]/=10;
			}
			for(j=6;j>=0;j--)
			{
				if(j==3)putchar('-');
				printf("%d",p[j]);
			}
			printf(" %d\n",t);
			if(!find)find=1;
			t=1;
		}
	}
	if(t>1)
	{
		for(j=0;j<7;j++)
		{
			p[j]=tel[n-1]%10;
			tel[n-1]/=10;
		}
		for(j=6;j>=0;j--)
		{
			if(j==3)putchar('-');
			printf("%d",p[j]);
		}
		printf(" %d\n",t);
		find=1;
	}
	if(!find)
		printf("No duplicates.\n");
}
void main()
{
	int i,j,now,t;
	char ch;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		if(now)putchar('\n');
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			j=0;
			ch=getchar();
			while(ch!='\n'||!j)
			{
				if(ch>='0'&&ch<='9')
					num[i][j++]=ch;
				else if(ch>='A'&&ch<'Z')
					num[i][j++]=ch;
				ch=getchar();
			}
			num[i][j]='\0';
		}
		run();
	}
}