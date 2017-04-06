#ifdef WIN32
#	pragma warning(disable:4786)
#define for if(0);else for
#endif
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

#define MAXN 200
int n;
int mat[MAXN][MAXN];
int a[MAXN];

//��Դ���·��,bellman_ford�㷨,�ڽ�����ʽ,���Ӷ�O(n^3)
//���Դs�����е�����·��,����ͼ�Ĵ�Сn���ڽ���mat
//���ص�������̾���min[]��·��pre[],pre[i]��¼s��i·����i�ĸ����,pre[s]=-1
//�ɸ���·Ȩ����,·Ȩ��Ϊ��,��ͼ�������������ʧ��,����0
//�Ż�:��ɾȥ����ʹ��dijkstra����Ͻ�,���ٵ�������

#define inf 1000000000
typedef int elem_t;

int bellman_ford(int n,elem_t mat[][MAXN],int s,elem_t* min,int* pre){
	int v[MAXN],i,j,k,tag;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&mat[k][i]>=0&&min[k]+mat[k][i]<min[i])
				min[i]=min[k]+mat[pre[i]=k][i];
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=i=0;i<n;i++)
			for (k=0;k<n;k++)
				if (min[k]+mat[k][i]<min[i])
					min[i]=min[k]+mat[pre[i]=k][i],tag=1;
	return j<=n;
}
void run(){
/*	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			if(i!=k)
			for(int j=0;j<n;j++)if(j!=k){
				if(mat[i][j]>mat[i][k]+mat[k][j])mat[i][j]=mat[i][k]+mat[k][j];
				if(i==j&&mat[i][j]<0){
					puts("impossible");return ;
				}
			}*/
	int min[MAXN],pre[MAXN];
	if(!bellman_ford(n,mat,0,min,pre)){
		cout<<"impossible"<<endl;return ;
	}
	int m=0;
	for(int i=0;i<n;i++){
		if(-min[i]<m)m=-min[i];
	}
	if(m<0){
		cout<<"impossible"<<endl;return ;
	}
	for(int i=0;i<n;i++){
		printf("%d %d\n",i+1,-min[i]);
	}
}

int b[2];
int main(){
	char s[100];
	int cnt=0;
	while(1){
//		cin>>n;
		scanf("%d",&n);
		if(n>110){
			while(1);
			return 0;
		}
		if(!n)break;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)
			if(i==j)mat[i][j]=0;
			else mat[i][j]=210000000;
//		memset(mat,0,sizeof(mat));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
//			cin>>a[i];
		while(1){
//			cin>>s;
			scanf("%s",s);
			if(s[0]=='#')break;
			int t1,t2;
//			cin>>t1>>t2;
			scanf("%d %d",&t1,&t2);
			if(!strcmp(s,"SAS")){
				mat[t2-1][t1-1]=0;
			}
			else if(!strcmp(s,"SAF")){
				mat[t2-1][t1-1]=-a[t2-1];
			}
			else if(!strcmp(s,"FAF")){
				mat[t2-1][t1-1]=a[t1-1]-a[t2-1];
			}
			else {
				mat[t2-1][t1-1]=a[t1-1];
			}
		}
//		cout<<"Case "<<++cnt<<":"<<endl;
		printf("Case %d:\n",++cnt);
		run();
//		cout<<endl;
		putchar('\n');
	}

	return 0;
}