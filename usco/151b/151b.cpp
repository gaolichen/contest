/*
ID:  mygali1
PROG: subset
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
ifstream in("subset.in");
ofstream out("subset.out");
#endif

int n,sum;
unsigned f[800];


void run(){
	if(n*(n+1)/2%2){
		out<<0<<endl;
		return ;
	}
	memset(f,0,sizeof(f));
	f[0]=1;
	int i,j;
	sum=n*(n+1)/4;
	for(i=1;i<=n;i++)
		for(j=sum;j>=0;j--)
			if(f[j])f[i+j]+=f[j];
	out<<f[sum]/2<<endl;
}

int main(){
	in>>n;
	run();
	return 0;
}