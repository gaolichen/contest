#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;

//求网络最大流,邻接阵形式
//回返最大流量,flow返回每条边的流量
//传入网络节点数n,容量mat,源点source,汇点sink
#define MAXN 460
#define inf 1000000000
typedef int elem_t;

#ifndef DEBUG
#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output1.txt");
#endif

elem_t maxflow(int n,elem_t mat[][MAXN],int source,int sink,elem_t flow[][MAXN]){
	int pre[MAXN],que[MAXN],p,q,t,i,j;
	elem_t d[MAXN],s;
	if (source==sink)
		return inf;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			flow[i][j]=0;
	for (pre[sink]=1;pre[sink];){
		for (i=0;i<n;pre[i++]=0);
		pre[t=source]=source+1,d[t]=inf;
		for (p=0,q=1;p<q&&!pre[sink];t=que[++p])
			for (i=0;i<n;i++)
				if (!pre[i]&&mat[t][i]&&(s=mat[t][i]-flow[t][i])>0)
					pre[que[q++]=i]=t+1,d[i]=d[t]<s?d[t]:s;
				else if (!pre[i]&&mat[i][t]&&(s=flow[i][t])>0)
					pre[que[q++]=i]=-t-1,d[i]=d[t]<s?d[t]:s;
		for (i=sink;pre[i]&&i!=source;)
			if (pre[i]>0)
				flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
			else
				flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
	}
	for (s=i=0;i<n;i++)
		s+=flow[source][i];
	return s;
}

int n,m,cnt;
int mat[40][40],tmp1[40],tmp2[40];
int nmat[40][40];
int f[MAXN][MAXN],flow[MAXN][MAXN];

void calc(){
	int i,j;
	memset(tmp2,0,sizeof(tmp2));
	for(i=0;i<n;i++)
		if(tmp1[i])
			for(j=0;j<n;j++)
				if(mat[i][j]){
					tmp2[j]=1;
					break;
				}
}

void run(){
	int i,j,k;
	memset(nmat,0,sizeof(nmat));
	nmat[0][0]=1;
	cnt=2;
	for(i=0;i<n;i++)
		if(mat[0][i])nmat[1][i]=cnt++;
	memcpy(tmp2,mat[0],sizeof(tmp2));
	for(i=2;i<n;i++){
		memcpy(tmp1,tmp2,sizeof(tmp1));
		calc();
		for(j=0;j<n;j++)
			if(tmp2[j]){
				nmat[i][j]=cnt++;
			}
	}
	memset(f,0,sizeof(f));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(nmat[i][j])
				for(k=0;k<n;k++)
					if(mat[j][k])f[nmat[i][j]-1][nmat[i+1][k]-1]=1;
	}
	for(i=0;i<n;i++)
		if(nmat[i][n-1])f[nmat[i][n-1]-1][cnt-1]=1;
	cout<<maxflow(cnt,f,0,cnt-1,flow)<<endl;
}

int main(){
	int i,j,k;
	while(cin>>n>>m){
		memset(mat,0,sizeof(mat));
		for(i=0;i<m;i++){
			cin>>j>>k;
			mat[j][k]=1;
		}
		run();
	}
	return 0;
}
