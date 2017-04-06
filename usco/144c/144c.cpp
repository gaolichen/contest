/*
ID:  mygali1
PROG: shuttle
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
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("shuttle.in");
ofstream out("shuttle.out");
#endif

char sk[1100][50],a[50];
int n,rec[1100];



int dfs(int k,int p){
	if(k==n*(n+2))
		return 1;
	memcpy(sk[k+1],sk[k],sizeof(sk[k]));
	if(p>=2&&sk[k][p-2]!=sk[k][p-1]&&sk[k][p-2]=='*'){
		rec[k]=p-2;
		sk[k+1][p]=sk[k+1][p-2];
		sk[k+1][p-2]='#';
		if(dfs(k+1,p-2))return 1;
		sk[k+1][p]=sk[k][p];
		sk[k+1][p-2]=sk[k][p-2];
	}
	if(p>=1&&sk[k][p-1]=='*'){
		rec[k]=p-1;
		sk[k+1][p]=sk[k+1][p-1];
		sk[k+1][p-1]='#';
		if(dfs(k+1,p-1))return 1;
		sk[k+1][p]=sk[k][p];
		sk[k+1][p-1]=sk[k][p-1];
	}
	if(p+1<2*n+1&&sk[k][p+1]=='@'){
		rec[k]=p+1;
		sk[k+1][p]=sk[k+1][p+1];
		sk[k+1][p+1]='#';
		if(dfs(k+1,p+1))return 1;
		sk[k+1][p]=sk[k][p];
		sk[k+1][p+1]=sk[k][p+1];
	}
	if(p+2<2*n+1&&sk[k][p+2]!=sk[k][p+1]&&sk[k][p+2]=='@'){
		rec[k]=p+2;
		sk[k+1][p]=sk[k+1][p+2];
		sk[k+1][p+2]='#';
		if(dfs(k+1,p+2))return 1;
		sk[k+1][p]=sk[k][p];
		sk[k+1][p+2]=sk[k][p+2];
	}
	return 0;

}

void run(){
	int i;
	for(i=0;i<n;i++)
		a[i]='*';
	a[n]='#';
	for(i=n+1;i<2*n+1;i++)
		a[i]='@';
	for(i=0;i<2*n+1;i++)
		sk[0][i]=a[i];
	dfs(0,n);
	for(i=0;i<n*(n+2);i++){
		if(i&&i%20==0)out<<endl;
		else if(i)out<<' ';
		out<<rec[i]+1;
	}
	out<<endl;
/*	int j,k;
	for(i=0;i<n*(n+2);i++){
		for(j=0;j<2*n+1;j++){
			if(a[j]=='#'){
				out<<' ';
				k=j;
			}
			else out<<a[j];
		}
		out<<endl;
		a[k]=a[rec[i]];
		a[rec[i]]='#';
	}*/
}

int main(){
	in>>n;
	run();
	return 0;
}