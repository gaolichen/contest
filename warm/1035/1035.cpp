#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector < vector < int > > a,b;

vector<int> aa,bb,cc;
int n,name[110];

int pre[110][110];

char mat[110][110],mark[110];

int check(vector<int> & v){
	int i,j;
	for(i=0;i<v.size();i++)
		for(j=i+1;j<v.size();j++)
			if(!mat[v[i]][v[j]])
				return 0;
	return 1;
}


int dfs(int n,int *name){
	if(n==0)return 1;
	int i,j=0;
	memset(mark,0,sizeof(mark));
	int flag=1;
	mark[j]=1;
	int change=0;
	while(1){
		change=0;
		for(flag=1;flag<3;flag++)
		for(i=0;i<n;i++)
			if(mark[i]==flag){
				for(j=0;j<n;j++)
					if(i!=j&&(!mat[name[i]][name[j]])){
						if(mark[j]&&mark[j]==flag)return 0;
						if(!mark[j]){
							mark[j]=(flag==2?1:2);
							change=1;
						}
					}
			}
		if(!change)break;
	}
	aa.clear();bb.clear();cc.clear();
	for(i=0;i<n;i++){
		if(mark[i]==1)
			aa.push_back(name[i]);
		else if(mark[i]==2)
			bb.push_back(name[i]);
		else cc.push_back(name[i]);
	}
	for(i=0;i<cc.size();i++){
		for(j=0;j<aa.size();j++)
			if(!mat[cc[i]][aa[j]])return 2;
		for(j=0;j<bb.size();j++)
			if(!mat[cc[i]][bb[j]])return 3;
	}
	if(!check(aa)||!check(bb))return 4;
	a.push_back(aa);b.push_back(bb);
	for(j=0;j<cc.size();j++)
		name[j]=cc[j];
	return dfs(j,name);
}
vector<int> best;
void dp(){
	int i,j,k;
	memset(mat,0,sizeof(mat));
	memset(pre,0,sizeof(pre));
	mat[0][a[0].size()]=mat[0][b[0].size()]=1;
	pre[0][a[0].size()]=0;
	pre[0][b[0].size()]=1;
	for(i=1;i<a.size();i++){
		for(j=0;j+j<=n;j++)
			if(mat[i-1][j]){
				mat[i][j+a[i].size()]=mat[i][j+b[i].size()]=1;
				pre[i][j+a[i].size()]=0;
				pre[i][j+b[i].size()]=1;
			}
	}
	for(i=n/2;i>=0;i--)
		if(mat[a.size()-1][i])break;
	if(i<0){
		return ;
	}
	j=a.size()-1;
	while(i!=0){
		if(!pre[j][i]){
			for(k=0;k<a[j].size();k++)
				best.push_back(a[j][k]);
			i-=a[j].size();
		}
		else{
			for(k=0;k<b[j].size();k++)
				best.push_back(b[j][k]);
			i-=b[j].size();
		}
		j--;
	}
}
int Count;

void run(){
	int i,j;
	for(i=0;i<n;i++)
		name[i]=i;
	Count=0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			if(!mat[i][j]||!mat[j][i])
				mat[i][j]=mat[j][i]=0;
			if(mat[i][j])Count++;
		}
	i=dfs(n,name);
	if(i!=1){
		cout<<"No solution"<<endl;
		return ;
	}
	best.clear();
	dp();
	if(!best.size()){
		cout<<"No solution"<<endl;
		return ;
	}
	memset(mark,0,sizeof(mark));
	cout<<best.size();
	for(i=0;i<best.size();i++){
		mark[best[i]]=1;
		cout<<' '<<best[i]+1;
	}
	cout<<endl;
	cout<<n-best.size();
	for(i=0;i<n;i++)
		if(!mark[i])cout<<' '<<i+1;
	cout<<endl;
}


int main(){
	int t,i,j,cnt=0;
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();b.clear();
		memset(mat,0,sizeof(mat));
		for(i=0;i<n;i++)
			while(1){
				cin>>j;
				if(!j)break;
				mat[i][--j]=1;
			}
		if(cnt++)cout<<endl;
		run();
	}
	return 0;
}