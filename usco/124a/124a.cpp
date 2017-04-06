/*
ID:  mygali1
PROG: inflate
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
ifstream in("inflate.in");
ofstream out("inflate.out");
#endif

int f[11000],n,m,p[11000],t[11000];
void run(){
	int i,j;
	f[0]=0;
	for(i=1;i<=m;i++){
		f[i]=f[i-1];
		for(j=0;j<n;j++)
			if(t[j]<=i&&f[i]<f[i-t[j]]+p[j])
				f[i]=f[i-t[j]]+p[j];
	}
	out<<f[m]<<endl;
}
int main(){
	int i;
	while(in>>m>>n){
		for(i=0;i<n;i++)
			in>>p[i]>>t[i];
		run();
	}
	return 0;
}