#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAXN 110

int maxc;
int c[MAXN],nmat[MAXN][MAXN],used[MAXN];
int vertex[MAXN],ret[MAXN];

struct NODE{
	int id,d,c;
	bool operator<(const NODE &a) const{
		if(c!=a.c)return c<a.c;
		return d<a.d;
	}
};
NODE nv[MAXN];

int dfs(int n,int k,int size){
	int i;
	if(size>maxc){
		maxc=size;
		for(i=0;i<maxc;i++)
			ret[i]=used[i];
		return 1;
	}
	if(k==n){
		return 0;
	}
	if(size+c[vertex[k]]<=maxc)return 0;
/*	int i,j;
	for(i=0;i<sv[k];i++){
		sv[k+1]=0;
		used[size]=vertex[k][i];
		for(j=i+1;j<sv[k];j++)
			if(nmat[vertex[k][i]][vertex[k][j]])
				vertex[k+1][sv[k+1]++]=vertex[k][j];
		if(dfs(k+1,size+1))return 1;
	}
	return 0;*/
	
	for(i=size-1;i>=0;i--)
		if(!nmat[used[i]][vertex[k]])break;
	if(i<0){
		used[size]=vertex[k];
		if(dfs(n,k+1,size+1))return 1;
	}
	return dfs(n,k+1,size);
}

void color(int mat[][MAXN],int n){
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

int maxclique(int mat[][MAXN],int n,int *v){
	int i,j;
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
	maxc=1;
	c[n-1]=1;
	int cnt;
	for(i=n-2;i>=0;i--){
		cnt=0;
		for(j=i+1;j<n;j++)
			if(nmat[i][j])
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
	int i,t,cnt=0,j,k,n,m;
	int mat[MAXN][MAXN],v[MAXN];
	char mark[MAXN];
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				mat[i][j]=mat[j][i]=1;
		for(i=0;i<m;i++){
			cin>>j>>k;
			j--;k--;
			mat[j][k]=mat[k][j]=0;
		}
		j=maxclique(mat,n,v);
		if(j==n){
			cout<<"Mission #"<<++cnt<<" is canceled."<<endl;
		}
		else{
			cnt++;
			memset(mark,0,sizeof(mark));
			cout<<"Must conquer "<<n-j<<" bases:"<<endl;
			for(i=0;i<j;i++)
				mark[v[i]]=1;
			for(i=j=0;i<n;i++)
				if(!mark[i]){
					if(j)cout<<' ';
					cout<<i+1;
					j=1;
				}
			cout<<endl;
		}
	}
	return 0;
}