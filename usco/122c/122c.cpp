/*
ID:  mygali1
PROG: money
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("money.in");
ofstream out("money.out");
#endif

int v,n,a[30];
long long f[30][11000];
void run(){
	int i,j,k;
	memset(f,0,sizeof(f));
	for(i=0;i*a[0]<=n;i++)
		f[0][i*a[0]]=1;
	for(i=1;i<v;i++)
		for(j=0;j<=n;j++)
			for(k=0;k*a[i]<=j;k++)
				f[i][j]+=f[i-1][j-k*a[i]];
	out<<f[v-1][n]<<endl;
}
int main(){
	int i;
	while(in>>v>>n){
		for(i=0;i<v;i++)
			in>>a[i];
		run();
	}
	return 0;
}