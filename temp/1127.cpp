#include<stdio.h>
#include<string.h>
int map[30][30],n,m;
char inf[2];
void run()
{
	int i,j,cuur,sk[50],open,close,bfn[50],mark[50],max;
	cuur=inf[0]-'A';
	for(i=0;i<26;i++)
		bfn[i]=100;
	bfn[cuur]=0;printf("%c",'A'+cuur);
	for(i=1;i<m;i++)
	{
		memset(mark,0,sizeof(mark));
		open=close=0;
		sk[0]=cuur;mark[cuur]=1;
		bfn[cuur]=0;max=cuur;
		while(open<=close)
		{
			if(bfn[sk[open]]>bfn[max])
				max=sk[open];
			else if(bfn[sk[open]]==bfn[max]&&sk[open]<max)
				max=sk[open];
			for(j=0;j<n;j++)
	if(!mark[j]&&map[sk[open]][j])
	{
		mark[j]=1;
		sk[++close]=j;
		if(bfn[j]>bfn[sk[open]]+1)
		bfn[j]=bfn[sk[open]]+1;
	}
	        open++;
		}
		cuur=max;
		printf(" %c",'A'+cuur);
	}
	putchar('\n');
}
void main()
{
	int i;
	char str1[2],str2[2];
	printf("Program 8 by team X\n");
	while(scanf("%d%s%d",&n,inf,&m)==3)
	{
		memset(map,0,sizeof(map));
		for(i=0;i<n-1;i++)
		{
			scanf("%s%s",str1,str2);
map[str1[0]-'A'][str2[0]-'A']=map[str2[0]-'A'][str1[0]-'A']=1;
		}
		run();
	}
	printf("End of program 8 by team X\n");
}