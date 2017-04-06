/*
ID:  mygali1
PROG: job
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 3456793
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("job.in");
ofstream out("job.out");
#endif

int fa[40],fb[40],f[1100],g[1100],n,m1,m2,ta[40],tb[40];
void run(){
	int i,j,min,k;
	memset(fa,0,sizeof(fa));
	memset(fb,0,sizeof(fb));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(i=1;i<=n;i++){
		min=10000000;
		for(j=0;j<m1;j++)
			if(fa[j]+ta[j]<min){
				min=fa[j]+ta[j];
				k=j;
			}
		fa[k]=g[i]=min;
		min=10000000;
		for(j=0;j<m2;j++)
			if(fb[j]+tb[j]<min){
				min=fb[j]+tb[j];
				k=j;
			}
		fb[k]=f[i]=min;
	}
	out<<g[n]<<' ';
	min=0;
	for(i=1;i<=n;i++)
		if(g[i]+f[n-i+1]>min){
			min=g[i]+f[n-i+1];
		}
	out<<min<<endl;
}
int main(){
	int i;
	in>>n>>m1>>m2;
	for(i=0;i<m1;i++)
		in>>ta[i];
	for(i=0;i<m2;i++)
		in>>tb[i];
	run();
	return 0;
}