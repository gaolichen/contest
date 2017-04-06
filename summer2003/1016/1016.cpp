#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int sk[20],n,ret;
char mark[20];

int inline check(int r,int c){
	if(mark[c])return 0;
	int i;
	for(i=0;i<r;i++){
		if(i+sk[i]==r+c||i-sk[i]==r-c)return 0;
	}
	return 1;
}

void dfs(int r){
	int i;
	if(r==n){
		ret++;
		if(ret<=3){
		for(i=0;i<r;i++){
			if(i)cout<<' ';
			cout<<sk[i]+1;
		}
		cout<<endl;
		}
		return ;
	}
	for(i=0;i<n;i++)
		if(check(r,i)){
			mark[i]=1;
			sk[r]=i;
			dfs(r+1);
			mark[i]=0;
		}
}

int main(){
	while(cin>>n){
		if(n<0)break;
		ret=0;
		memset(mark,0,sizeof(mark));
		dfs(0);
		cout<<ret<<endl;
	}
	return 0;
}