/*
ID:  mygali1
PROG: humble
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("humble.in");
ofstream out("humble.out");
#endif

int f[110000],a[110],n,m,g[110000];
int cmp(const void*t1,const void *t2){
	return *(int*)t1-*(int*)t2;
}
void run(){
	int i,j,k,min;
	qsort(a,m,sizeof(int),cmp);
	f[0]=1;
	for(i=0;i<m;i++)g[i]=0;
	for(i=1;i<=n;i++){
		min=2100000000;
		for(j=0;j<m;j++)
			if(a[j]*f[g[j]]<min){
				min=a[j]*f[g[j]];
				k=j;
			}
		f[i]=min;
		g[k]++;
		for(j=0;j<m;j++)
			if(a[j]*f[g[j]]<=f[i])g[j]++;
	}
//	out<<endl;
	out<<f[n]<<endl;
}
int main(){
	int i;
	while(in>>m>>n){
		for(i=0;i<m;i++)
			in>>a[i];
		run();
	}
	return 0;
}