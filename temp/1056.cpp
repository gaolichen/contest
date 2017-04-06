#include<stdio.h>
#include<stdlib.h>
#define M 20000
/*
typedef struct vnode{
	int vex;
	struct vnode *next;
}gra;
gra * dis[M];
int n;
void creategraph(gra *dis[M])
{
	gra *s;
	int i,j;
	for(i=0;i<n;i++)
		dis[i]=NULL;
	for(i=1;i<n;i++)
	{
		scanf("%d",&j);
		s=(gra*)malloc(sizeof(struct vnode));
		s->next=dis[i];
		dis[i]=s;
		s->vex=j-1;
		s=(gra*)malloc(sizeof(struct vnode));
		s->next=dis[j-1];
		dis[j-1]=s;
		s->vex=i;
	}
}
int bfs(int k)
{
	int i,open,close,sequ[M][2],a[M],t;
	gra *s;
	for(i=0;i<n;i++)
		a[i]=0;
	open=close=0;
	sequ[0][0]=k;
	sequ[0][1]=0;
	while(open<=close)
	{
		t=sequ[open][0];
		s=dis[t];
		while(s!=NULL)
		{
			if(s->vex!=k&&!a[s->vex])
			{
			a[s->vex]=1;
		    sequ[++close][0]=s->vex;
		    sequ[close][1]=sequ[open][1]+1;
			}
		    s=s->next;
		}
		open++;
	}
	return sequ[close][1];
}*/
void main()
{
	int i,m,t,cen[M],min;
	while(scanf("%d",&n)==1)
	{
		min=M;
		//creategraph(dis);
		for(i=0;i<n;i++)
		{
			t=bfs(i);
			if(t<min)
			{
				min=t;
				m=0;
				cen[m++]=i;
			}
			else if(t==min)
				cen[m++]=i;
		}
		printf("%d",cen[0]+1);
		for(i=1;i<m;i++)
			printf(" %d",cen[i]+1);
		printf("\n");
	}
}