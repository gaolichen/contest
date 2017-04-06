/*
ID:  mygali1
PROG: range
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("range.in");
ofstream out("range.out");
#endif

int n,mat[300][300];
char map[300][300];
int found(int b){
	int i,j,h,ret=0;
	for(i=0;i+b-1<n;i++)
		for(j=0;j+b-1<n;j++){
			h=mat[i+b-1][j+b-1];
			if(i)h-=mat[i-1][j+b-1];
			if(j)h-=mat[i+b-1][j-1];
			if(i&&j)h+=mat[i-1][j-1];
			if(h==b*b)ret++;
//			out<<b<<' '<<h<<endl;
		}
	return ret;
}
void run(){
	int i,j;
	memset(mat,0,sizeof(mat));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i)mat[i][j]+=mat[i-1][j];
			if(j)mat[i][j]+=mat[i][j-1];
			if(i&&j)mat[i][j]-=mat[i-1][j-1];
			if(map[i][j]=='1')mat[i][j]++;
		}
	for(i=2;i<=n;i++){
		j=found(i);
		if(!j)break;
		out<<i<<' '<<j<<endl;
	}
}
int main(){
	int i;
	while(in>>n){
		for(i=0;i<n;i++)
			in>>map[i];
		run();
	}
	return 0;
}