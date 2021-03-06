#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 60
#define elem_t char
struct NODE{
	int id,d,c;
	bool operator<(const NODE &a) const{
		if(c!=a.c)return c<a.c;
		return d<a.d;
	}
};

int c[MAXN],used[MAXN];
elem_t nmat[MAXN][MAXN];
int vertex[MAXN],ret[MAXN],maxc;
NODE nv[MAXN];

int dfs(int n,int k,int size){
	int i;
	if(size>maxc){
		for(i=0,maxc=size;i<size;i++)
			ret[i]=used[i];
		return 1;
	}
	if(k==n){
		return 0;
	}
	if(size+c[vertex[k]]<=maxc)return 0;
	for(i=size-1;i>=0;i--)
		if(!nmat[used[i]][vertex[k]])break;
	if(i<0){
		used[size]=vertex[k];
		if(dfs(n,k+1,size+1))return 1;
	}
	return dfs(n,k+1,size);
}

void color(elem_t mat[][MAXN],int n){
	int i,opn,cls,sk[MAXN],j,k;
	char mark[MAXN];
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++)if(!c[i]){
		c[i]=1;
		sk[opn=cls=0]=i;
		while(opn<=cls){
			for(j=i+1;j<n;j++)
				if(!c[j]&&mat[sk[opn]][j]){
					memset(mark,0,sizeof(char)*(n-i+1));
					for(k=i;k<n;k++)
						if(mat[k][j]&&c[k])mark[c[k]]=1;
					for(k=1;k<=n-i;k++)
						if(!mark[k])break;
					c[j]=k;
					sk[++cls]=j;
				}
			opn++;
		}
	}
}

//求最大团 传入mat[][]连接矩阵 和大小n 返回最大团的大小
//v[]存求得的最大团

int maxclique(elem_t mat[][MAXN],int n,int *v){
	if(n<1)return n;
	int i,j,cnt;
	color(mat,n);
	for(i=0;i<n;i++){
		nv[i].d=0;nv[i].id=i;
		nv[i].c=c[i];
		for(j=0;j<n;j++)
			if(i!=j&&mat[i][j])
				nv[i].d++;
	}
	sort(nv,nv+n);
	memset(nmat,0,sizeof(nmat));
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(mat[nv[i].id][nv[j].id])
				nmat[i][j]=nmat[j][i]=1;
	int d[MAXN];
	maxc=c[0]=d[0]=1;
	for(i=1;i+i<=n;i++){
		for(cnt=0,j=i-1;j>=0;j--)if(nmat[i][j])
			vertex[cnt++]=j;
		used[0]=i;
		dfs(cnt,0,1);
		d[i]=c[i]=maxc;
	}
//	cout<<d[n/2]<<endl;
	maxc=c[n-1]=1;
	for(i=n-2;i>=0;i--){
		if(i+i<=n){
			if(d[i]+c[i+1]<=maxc){
//				cout<<"kaka"<<endl;
				break;
			}
		}
		for(cnt=0,j=i+1;j<n;j++)if(nmat[i][j])
			vertex[cnt++]=j;
		used[0]=i;
		dfs(cnt,0,1);
		c[i]=maxc;
	}
	for(i=0;i<c[0];i++)
		v[i]=nv[ret[i]].id;
	return c[0];
}


int main(){
	char mat[MAXN][MAXN];
	int v[MAXN];
	int n,i,j,k,m;
	while(1){
		cin>>n;
		if(n<0)break;
		memset(mat,0,sizeof(mat));
		for(i=0;i<n;i++){
			cin>>m;
			for(j=0;j<m;j++){
				cin>>k;
				mat[i][k-1]=mat[k-1][i]=1;
			}
		}
		cout<<maxclique(mat,n,v)<<endl;;
	}
	return 0;
}
