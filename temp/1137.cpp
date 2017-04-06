#include<stdio.h>
#include<stdlib.h>
int map[1010][1010],tot[1010],ch[1010],ord[1010];
int count,n;
/*
void run()
{
	int i,j,min;
	for(i=0;i<n;i++)
		mark[i]=0;
	count=0;
	do
	{
		min=-1;
		for(i=0;i<n;i++)
			if(!mark[i]&&(min==-1||tot[i]<tot[min]))
				min=i;
		if(min!=-1)
		{
			mark[min]=1;
			ch[count++]=min;
		for(i=0;i<n;i++)
			if(!mark[i]&&map[i][min])
			{
				mark[i]=1;
				for(j=0;j<n;j++)
					if(!mark[j]&&map[i][j])
						tot[j]--;
			}
		}
	}while(min!=-1);
	printf("%d\n",count);
}*/
int cmp(const void *t1,const void *t2)
{
	if(tot[*(int *)t1]>tot[*(int*)t2])
		return 1;
	return -1;
}
void run()
{
	int i,j;
	count=0;
	for(i=0;i<n;i++)
		ord[i]=i;
	qsort(ord,n,sizeof(int),cmp);
	for(i=0;i<n;i++)
		printf("%d ",ord[i]);
	putchar('\n');
	for(i=0;i<n;i++)
	{
		for(j=0;j<count;j++)
			if(map[ord[i]][ch[j]])break;
		if(j==count)
			ch[count++]=ord[i];
	}
	printf("%d\n",count);
}
void main()
{
	int i,j,stu,k;
	char ch;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				map[i][j]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%c",&stu,&ch);
			while(ch!='(')ch=getchar();
			scanf("%d%c",&tot[stu],&ch);
			while(ch!=')')ch=getchar();
			for(j=0;j<tot[stu];j++)
			{
				scanf("%d",&k);
				map[stu][k]=map[k][stu]=1;
			}
		}
		run();
	}
}