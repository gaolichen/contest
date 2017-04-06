/*
ID:  mygali1
PROG: frameup
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 3456793
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("frameup.in");
ofstream out("frameup.out");
#endif

int h,w,nr,count,miny[30],maxy[30],minx[30],maxx[30],sk[30];
char map[50][50],rec[100000][30],mark[30];

inline int min(int a,int b){
	return (a<b?a:b);
}
inline int max(int a,int b){
	return (a<b?b:a);
}

int check(int k,char map[][50],char temp[][50]){
	int i,j;
	for(i=miny[k];i<=maxy[k];i++){
		if(map[minx[k]][i]!='A'+k&&map[minx[k]][i]!='*')
			return 0;
		if(map[maxx[k]][i]!='A'+k&&map[maxx[k]][i]!='*')
			return 0;
	}
	for(i=minx[k];i<=maxx[k];i++){
		if(map[i][miny[k]]!='A'+k&&map[i][miny[k]]!='*')
			return 0;
		if(map[i][maxy[k]]!='A'+k&&map[i][maxy[k]]!='*')
			return 0;
	}
	for(i=0;i<h;i++)
		for(j=0;j<w;j++){
			temp[i][j]=map[i][j];
			if(temp[i][j]=='A'+k)
				temp[i][j]='*';
		}
	return 1;
	
}/*
int check(int k,char mat[][50],char temp[][50]){
	int i,j;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			temp[i][j]=mat[i][j];
	for(i=minx[k];i<=maxx[k];i++){
		temp[i][miny[k]]=k+'A';
		temp[i][maxy[k]]=k+'A';
	}
	for(i=miny[k];i<=maxy[k];i++){
		temp[minx[k]][i]=k+'A';
		temp[maxx[k]][i]=k+'A';
	}
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(map[i][j]!='.'&&mark[map[i][j]-'A']){
				if(temp[i][j]!=map[i][j])return 0;
			}
	return 1;
}*/
void dfs(int k,char map[][50]){
	int i;
	if(k==count){
		for(i=k-1;i>=0;i--)
			rec[nr][k-1-i]=sk[i]+'A';
		rec[nr++][k]='\0';
/*		for(i=0;i<k;i++)
			out<<char(sk[i]+'A');
		out<<endl;*/
		return ;
	}
	char temp[50][50];
	for(i=0;i<26;i++)
		if(!mark[i]&&check(i,map,temp)){
			mark[i]=1;
			sk[k]=i;
			dfs(k+1,temp);
			mark[i]=0;
		}
}
int cmp(const void *a,const void *b){
	return strcmp((char*)a,(char*)b);
}
void run(){
	int i,j,k;
	for(i=0;i<26;i++){
		minx[i]=miny[i]=M;
		maxx[i]=maxy[i]=-1;
		mark[i]=1;
	}
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)if(map[i][j]!='.'){
			k=map[i][j]-'A';
			minx[k]=min(minx[k],i);
			miny[k]=min(miny[k],j);
			maxx[k]=max(maxx[k],i);
			maxy[k]=max(maxy[k],j);
			mark[k]=0;
		}
//	for(i=0;i<26;i++)
//		out<<minx[i]<<' '<<miny[i]<<' '<<maxx[i]<<' '<<maxy[i]<<endl;
	count=0;
	for(i=0;i<26;i++)
		if(!mark[i])count++;
	nr=0;
	dfs(0,map);
	qsort(rec,nr,sizeof(rec[0]),cmp);
	for(i=0;i<nr;i++)
		out<<rec[i]<<endl;
}
int main(){
	int i;
	while(in>>h>>w){
		for(i=0;i<h;i++)
			in>>map[i];
		run();
	}
	return 0;
}