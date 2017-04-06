#include<stdio.h>
#include<string.h>
int n,p[1200],com[1200][1200],rq[1200];
int ns[1200],son[1200][1200],tot[1200];
void run()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			if(i==j)
			{
				com[rq[i]][rq[j]]=rq[i];
				com[rq[j]][rq[i]]=rq[i];
			}
			else 
			{
				com[rq[i]][rq[j]]=com[rq[i]][p[rq[j]]];
				com[rq[j]][rq[i]]=com[rq[i]][p[rq[j]]];
			}
		}
}
void init()
{
	int i,open=0,close=0;
	for(i=1;i<n;i++)
		if(!p[i])break;
	rq[0]=i;
	while(open<=close)
	{
		for(i=0;i<ns[rq[open]];i++)
			rq[++close]=son[rq[open]][i];
		open++;
	}
}
void main()
{
	int i,j,k,t,m;
	char ch;
	while(scanf("%d",&n)==1)
	{
	memset(p,0,sizeof(int)*(n+1));
	for(i=0;i<n;i++)
	{
		scanf("%d%c",&t,&ch);
		while(ch!=':')scanf("%c",&ch);
		while(ch!='(')scanf("%c",&ch);
		scanf("%d",&m);
		ns[t]=m;
		scanf("%c",&ch);
		while(ch!=')')scanf("%c",&ch);
		for(j=0;j<m;j++)
		{
			scanf("%d",&k);
			p[k]=t;
			son[t][j]=k;
		}
	}
	init();
	run();
	scanf("%d%c",&m,&ch);
	memset(tot,0,sizeof(int)*(n+1));
	for(i=0;i<m;i++)
	{
		while(ch!='(')scanf("%c",&ch);
		scanf("%d%c",&j,&ch);
		while(ch!=',')scanf("%c",&ch);
		scanf("%d%c",&k,&ch);
		tot[com[j][k]]++;
		while(ch!=')')scanf("%c",&ch);
	}
	for(i=n-1;i>=0;i--)
		if(tot[rq[i]])
			printf("%d:%d\n",rq[i],tot[rq[i]]);
	}
}