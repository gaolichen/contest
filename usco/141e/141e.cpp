/*
ID:  mygali1
PROG: ariprog
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 100000000
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("ariprog.in");
ofstream out("ariprog.out");
#endif

int n,m,mark[140000],p[25000],np[140000],num[25000];
int tot,seq[11000][2];
void init(){
	int i,j;
	memset(mark,0,sizeof(mark));
	for(i=0;i<=250;i++)
		for(j=i;j<=250;j++)
			if(!mark[i*i+j*j]||mark[i*i+j*j]>j+1)
				mark[i*i+j*j]=j+1;
}

int check(int a,int b){
	int i;
	for(i=1;i<n;i++)
		if(!mark[i*b+a]||mark[i*b+a]>m+1)return 0;
//	if(n*b+a<=m*m+m*m&&mark[n*b+a]&&mark[n*b+a]<=m)return 0;
	return 1;
}

void insert(int j,int i){
	seq[tot][1]=i;
	seq[tot++][0]=j-(n-1)*i;
}

int cmp(const void *a,const void *b){
	if(((int*)a)[1]!=((int*)b)[1])
		return ((int*)a)[1]-((int*)b)[1];
	return ((int*)a)[0]-((int*)b)[0];
}
void run(){
	int i,j,flag=0,count=0,st;
	for(i=count=0;i<=m*m*2;i++)
		if(mark[i]&&mark[i]<=m+1){
			p[count++]=i;
			np[i]=count-1;
		}
	st=tot=0;
	/*
	for(i=1;i<=m*m*2;i++){
		while(st<count&&p[st]<i)st++;
		if(st<count)
		for(j=st;j<count&&p[j]<=2*m*m;j++){
			if(!mark[p[j]-i]||mark[p[j]-i]>m+1){
				num[j]=1;
				continue;
			}
			if(p[j]-i<i){
				num[j]=2;
				continue;
			}
			num[j]=num[np[p[j]-i]]+1;
			if(num[j]>=n)insert(p[j],i);
		}
	}*/
	for(i=0;i<count-1;i++){
		for(j=i;j<count-1&&(p[j+1]-p[i])*(n-1)+p[i]<=2*m*m;j++)
			if(check(p[i],p[j+1]-p[i])){
				seq[tot][0]=p[i];
				seq[tot++][1]=p[j+1]-p[i];
			}
	}
	if(!tot)out<<"NONE"<<endl;
	qsort(seq,tot,sizeof(int)*2,cmp);
	for(i=0;i<tot;i++){
		out<<seq[i][0]<<' '<<seq[i][1]<<endl;
	}
//	out<<tot<<endl;
}
int main(){
	init();
	while(in>>n>>m)run();
	return 0;
}