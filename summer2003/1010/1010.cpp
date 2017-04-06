#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 110

using namespace std;

char mat[MAXN][MAXN];
char buf[2][MAXN];
int n;

int check(int k){
	int i,j,flag[2];
	flag[0]=flag[1]=0;
	for(i=0;i<2;i++){
		for(j=0;j<=k;j++){
			if(mat[k][j]==buf[i][j]||mat[k][j]=='?')continue;
			break;
		}
		if(j>k)flag[i]=1;
	}
	if(flag[0]&&flag[1])return 2;
	if(flag[0])return 0;
	return 1;
}
void run(){
	int i,j,max,min;
	max=min=0;
	for(i=0;i<n;i++){
		j=check(i);
		if(!j){
			max+=(i+2)/2;
			min+=(i+2)/2;
		}
		else if(j==1){
			max+=(i+1)/2;
			min+=(i+1)/2;
		}
		else {
			max+=(i+2)/2;
			min+=(i+1)/2;
		}
	}
	cout<<max<<' '<<min<<endl;
}
int main(){
	int i;
	for(i=0;i<MAXN;i++){
		if(i%2==0){
			buf[0][i]='@';
			buf[1][i]='*';
		}
		else {
			buf[0][i]='*';
			buf[1][i]='@';
		}
	}
	while(cin>>n){
		if(n<=0)break;
		for(i=0;i<n;i++)
			cin>>mat[i];
		run();
	}
	return 0;
}