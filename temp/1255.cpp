#include<stdio.h>
#include<string.h>
int a[4]={0,0,1,-1};
int b[4]={1,-1,0,0};
char map[100][100];
int n;
int can(char map[100][100],char ch)
{
	int i,j,x[10000],y[10000],close,open,mark[100][100],ti,tj;	
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		if(map[i][0]==ch&&!mark[i][0])
		{
			close=open=0;
			mark[i][0]=1;
			x[0]=i;y[0]=0;
			while(open<=close)
			{
				if(y[open]==n-1)
					return 1;
				ti=x[open];tj=y[open];
				for(j=0;j<4;j++)
				if(ti+a[j]>=0&&ti+a[j]<n&&tj+b[j]>=0&&tj+b[j]<n&&
				!mark[ti+a[j]][tj+b[j]]&&map[ti+a[j]][tj+b[j]]==ch)
				{
					mark[ti+a[j]][tj+b[j]]=1;
					x[++close]=ti+a[j];
					y[close]=tj+b[j];
				}
				open++;
			}
		}
	return 0;
}
/*
int can2(char map[100][100],char ch)
{
	int i,j,x[10000],y[10000],close,open,u[10000],mark[100][100];
	int ti,tj;
	memset(u,0,sizeof(int)*n*n);
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		if(!mark[i][0]&&(map[i][0]==ch||map[i][0]=='U'))
		{
			close=open=0;
			x[open]=i;
			y[open]=0;
			u[open]=0;
			mark[i][0]=1;
			if(map[i][0]=='U')u[open]=1;
			while(open<=close)
			{
				if(y[open]==n-1)
					return 1;
				ti=x[open];tj=y[open];
				for(j=0;j<4;j++)
				if(ti+a[j]>=0&&ti+a[j]<n&&tj+b[j]>=0&&tj+b[j]<n
				&&!mark[ti+a[j]][tj+b[j]])
				{
					if(map[ti+a[j]][tj+b[j]]==ch)
					{
						x[++close]=ti+a[j];
						y[close]=tj+b[j];
						u[close]=u[open];
						mark[ti+a[j]][tj+b[j]]=1;
					}
				else if(map[ti+a[j]][tj+b[j]]=='U'&&!u[open])
					{
					     x[++close]=ti+a[j];
						 y[close]=tj+b[j];
						 u[close]=1;
						 mark[ti+a[j]][tj+b[j]]=1;
					}
				}
				open++;
			}
		}
		return 0;
}*/
void run()
{
	int i,j;
	char tmap[100][100];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			tmap[i][j]=map[j][i];
	if(can(map,'W'))
	{
		printf("White has a winning path.\n");
		return ;
	}
	if(can(tmap,'B'))
	{
		printf("Black has a winning path.\n");
		return ;
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(map[i][j]=='U')
			{
			map[i][j]='W';
	if(can(map,'W'))
	{
		printf("White can win in one move.\n");
		return ;
	}
	map[i][j]='U';
			}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		if(tmap[i][j]='U')
		{
		tmap[i][j]='B';
	if(can(tmap,'B'))
	{
		printf("Black can win in one move.\n");
		return ;
	}
	tmap[i][j]='U';
		}
	printf("There is no winning path.\n");
}
void main()
{
	int i;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		run();
		scanf("%d",&n);
	}
}