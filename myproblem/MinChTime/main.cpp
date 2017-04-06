#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
#define inf 1000000
int p[6][2]={{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
#define DEBUG
#ifdef DEBUG
#define cin in
//#define cout out
ifstream in("test.in");
ifstream out("test.out");
#endif

#define MAXN 1100
#define min(a,b) ((a)>(b)?(b):(a))
int a[MAXN],b[MAXN];
int mat[4][4],nmat[4][4];
int best,ret,sk[10],tot[10],n;
char mark[4];

void dfs1(int k,int cut,int s){
	if(ret>=best)return ;
	int i;
	if(k==s){
		if(nmat[sk[k-1]][sk[0]]){
			sk[k]=sk[0];
			cut=min(cut,nmat[sk[k-1]][sk[0]]);
			for(i=0;i<k;i++)
				nmat[sk[i]][sk[i+1]]-=cut;
			ret+=(s-1)*cut;
		}
		return ;
	}
	if(!k){
		for(i=0;i<4;i++){
			sk[0]=i;
			mark[i]=1;
			dfs1(k+1,cut,s);
			mark[i]=0;
		}
		return ;
	}
	for(i=0;i<4;i++)
		if(!mark[i]){
			sk[k]=i;
			mark[i]=1;
			dfs1(k+1,min(cut,mat[sk[k-1]][sk[k]]),s);
			mark[i]=0;
		}
}
void dfs(int k,int rem){
	int i;
	if(k==6){
		ret=rem;
		memcpy(nmat,mat,sizeof(mat));
		memset(mark,0,sizeof(mark));
		dfs1(0,inf,3);
		dfs1(0,inf,4);
		if(ret<best){
			int j;
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					if(nmat[i][j])return ;
					cout<<"kaka!~~~~"<<endl;
			best=ret;
		}
		return ;
	}
	for(i=0;i<=tot[k];i++){
		mat[p[k][0]][p[k][1]]+=i;
		mat[p[k][1]][p[k][0]]+=i;
		dfs(k+1,rem-i);
		mat[p[k][0]][p[k][1]]-=i;
		mat[p[k][1]][p[k][0]]-=i;
	}
}

void run(){
	int i;
	memcpy(b,a,sizeof(a));
	sort(b,b+n);
	memset(mat,0,sizeof(mat));
	for(i=0;i<n;i++)
		if(a[i]!=b[i])mat[a[i]][b[i]]++;
	for(i=0;i<6;i++){
		tot[i]=min(mat[p[i][0]][p[i][1]],mat[p[i][1]][p[i][0]]);
		mat[p[i][0]][p[i][1]]-=tot[i];
		mat[p[i][1]][p[i][0]]-=tot[i];
	}
	int t=0;
	for(i=0;i<6;i++)
		t+=tot[i];
	best=inf;
	dfs(0,t);
	cout<<best<<endl;
}
int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>a[i];
		run();
	}
	return 0;
}