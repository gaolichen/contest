/*
ID:  mygali1
PROG: fence
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
ifstream in("fence.in");
ofstream out("fence.out");
#endif

int map[500][500],path[600],n,node[600];

void findpath(int n,int mat[][500],int now,int&step,int *path){
	int i=0;
	for(;i<n;)
		for(i=0;i<n;i++)
			if(mat[now][i]){
				mat[now][i]--;mat[i][now]--;
				findpath(n,mat,i,step,path);
				break;
			}
	path[step++]=now;
}
void run(){
	int i;
	for(i=0;i<500;i++)
		if(node[i]%2)break;
	if(i==500)
		for(i=0;i<500;i++)
			if(node[i])break;
	int ret=0;
	findpath(500,map,i,ret,path);
	for(i=ret-1;i>=0;i--)
		out<<path[i]+1<<endl;
}
int main(){
	int i,j,k;
	while(in>>n){
		memset(map,0,sizeof(map));
		memset(node,0,sizeof(node));
		for(i=0;i<n;i++){
			in>>j>>k;
			map[--j][--k]++;
			map[k][j]++;
			node[j]++;node[k]++;
		}
		run();
	}
	return 0;
}