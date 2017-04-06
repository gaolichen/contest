/*
ID:  mygali1
PROG: game1
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
ifstream in("game1.in");
ofstream out("game1.out");
#endif

int n,a[200],tot,f[200][200],g[200][200];

void run(){
	int i,j;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(i=0;i<n;i++){
		f[i][1]=a[i];
		g[i][1]=0;
	}
	for(j=2;j<=n;j++)
		for(i=n-1;i>=0;i--)
		if(i+j-1<n){
			f[i][j]=g[i][j-1]+a[i+j-1];
			if(a[i]+g[i+1][j-1]>f[i][j])
				f[i][j]=a[i]+g[i+1][j-1];
			g[i][j]=f[i][j-1]+g[i][j-1]+a[i+j-1]-f[i][j];
		}
	out<<f[0][n]<<' '<<tot-f[0][n]<<endl;
}

int main(){
	int i;
	while(in>>n){
		for(i=tot=0;i<n;i++){
			in>>a[i];
			tot+=a[i];
		}
		run();
	}
	return 0;
}