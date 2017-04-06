/*
ID:  mygali1
PROG: numtri
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
ifstream in("numtri.in");
ofstream out("numtri.out");
#endif

int f[1100][1100],a[1100][1100],n;
void run(){
	int i,j;
	f[1][0]=a[1][0];
	for(i=2;i<=n;i++)
		for(j=0;j<i;j++){
			f[i][j]=f[i-1][j-1]+a[i][j];
			if(j<i-1&&f[i-1][j]>f[i-1][j-1])
				f[i][j]=f[i-1][j]+a[i][j];
		}
	j=f[n][0];
	for(i=0;i<n;i++)
		if(f[n][i]>j)j=f[n][i];
	out<<j<<endl;
}
int main(){
	int i,j;
	while(in>>n){
		for(i=1;i<=n;i++)
			for(j=0;j<i;j++)
				in>>a[i][j];
		run();
	}
	return 0;
}