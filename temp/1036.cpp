#include<iostream.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char name[20][30];
int a[20],house[20],fl[20],len[20],mark[20],sk[20];
int dis[20][20],tot[20],ret[20][20];
int n,m,l,count,res;
int calc(int i,int j)
{
	int h1,h2,f1,f2;
	if(house[i]==house[j])
		return abs(fl[i]-fl[j])*len[house[i]];
	h1=house[i];h2=house[j];f1=fl[i];f2=fl[j];
	return dis[h1][h2]+f1*len[h1]+f2*len[h2];
}
void search(int k,int min)
{
	int i,j,t;
	if(k==count+1)
	{
		for(i=0;i<k;i++)
			cout<<sk[i]<<' ';
		cout<<endl;
		if(min+dis[house[sk[k-1]]][1]+len[house[sk[k-1]]]*fl[sk[k-1]]<res)
		res=min+dis[house[sk[k-1]]][1]+len[house[sk[k-1]]]*fl[sk[k-1]];
		return ;
	}
	for(i=0;i<count;i++)
		if(!mark[i])
			for(j=0;j<tot[i];j++)
			{
				t=calc(sk[k-1],ret[i][j]);
				if(min+t+dis[house[ret[i][j]]][1]+fl[ret[i][j]]*len[house[ret[i][j]]]>=res)
					continue;
				mark[i]=1;
				sk[k]=ret[i][j];
				search(k+1,min+t);
				mark[i]=0;
			}
}
void run()
{
	int i,j,t,k,done[20];
	memset(mark,0,sizeof(mark));
	for(i=1,j=0;i<=n;i++)
		if(!mark[i])
		{
			t=i;tot[j]=0;
			memset(done,0,sizeof(done));
			while(1)
			{
				ret[j][tot[j]++]=t;
				done[t]=1;
				t=a[t];
				if(t==i)
				{
					if(tot[j]==1)break;
					for(k=0;k<tot[j];k++)
						mark[ret[j][k]]=1;
					j++;
					break;
				}
				if(t==0||done[t])
					break;
			}
		}
	count=j;
	for(j=0;j<count;j++,cout<<endl)
		for(i=0;i<tot[j];i++)
			cout<<ret[j][i]<<' ';
	memset(mark,0,sizeof(mark));
	res=2100000000;
	sk[0]=0;
	search(1,0);
	cout<<res<<endl;
}
int main()
{
	int i,j,t1,t2;
	char name1[30],name2[30];
	while(1)
	{
		cin>>n>>m>>l;
		if(!n&&!m&&!l)break;
		memset(a,0,sizeof(a));
		house[0]=1;fl[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>name[i]>>house[i]>>fl[i];
			fl[i]--;
		}
		for(i=1;i<=m;i++)
			for(cin>>len[i],j=1;j<=m;j++)
				cin>>dis[i][j];
		for(i=0;i<l;i++)
		{
			cin>>name1>>name2;
			for(j=1;j<=n;j++)
			{
				if(strcmp(name1,name[j])==0)t1=j;
				if(strcmp(name2,name[j])==0)t2=j;
			}
			a[t1]=t2;
		}
		run();
	}
	return 0;
}

/*

18 9 18

e 5 3
h 1 4
a 7 3
m 9 2
i 3 4
j 8 5
k 5 7
q 9 3
r 7 2
n 2 5
b 2 1
c 3 1
p 4 5
f 6 2
g 7 1
d 4 2
l 6 3
o 7 3

5 0 20 20 20 20 20 20 20 20
5 20 0 20 20 20 20 20 20 20
5 20 20 0 20 20 20 20 20 20
5 20 20 20 0 20 20 20 20 20
5 20 20 20 20 0 20 20 20 20
5 20 20 20 20 20 0 20 20 20
5 20 20 20 20 20 20 0 20 20
5 0 20 20 20 20 20 20 0  20
5 0 20 20 20 20 20 20 20 0


c d
e f
d c
f e
g h
h g
a b
b a
m n
n m
i j
j i
k l
l k
o p
p o
q r
r q



  */