/*
ID:  mygali1
PROG: holstein
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
#define MAXN 110
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("holstein.in");
ofstream out("holstein.out");
#endif

int v,need[30],sk[30],c[30][30],ret,tot[30],n,rec[30];

int ok(){
	int i;
	for(i=0;i<v;i++)
		if(tot[i]<need[i])return 0;
	return 1;
}

void dfs(int k,int ans){
	if(ans>=ret)return ;
	int i;
	if(k==n){
		if(ok()){
			ret=ans;
			for(i=0;i<ret;i++)
				rec[i]=sk[i];
		}
		return ;
	}
	for(i=0;i<v;i++)
		tot[i]+=c[k][i];
	sk[ans]=k;
	dfs(k+1,ans+1);
	for(i=0;i<v;i++)
		tot[i]-=c[k][i];
	dfs(k+1,ans);
}

void run(){
	int i;
	ret=100;
	memset(tot,0,sizeof(tot));
	dfs(0,0);
	out<<ret;
	for(i=0;i<ret;i++)
		out<<' '<<rec[i]+1;
	out<<endl;
}

int main(){
	int i,j;
	in>>v;
	for(i=0;i<v;i++)
		in>>need[i];
	for(i=0,in>>n;i<n;i++)
		for(j=0;j<v;j++)
			in>>c[i][j];
	run();
	return 0;
}