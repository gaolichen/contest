/*
ID:  mygali1
PROG: kimbits
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
ifstream in("kimbits.in");
ofstream out("kimbits.out");
#endif

int n,l,m;
char buf[40];
unsigned int f[40][40];
void calc(int n,int l,int m){
	int i=0;
	if(n<0||l<=0)return ;
	while(f[i][l]<=m)i++;
	i--;
	if(i<0)return ;
	buf[i]='1';
	calc(i-1,l-1,m-f[i][l]+1);
}

int main(){
	int i,j;
	memset(f,0,sizeof(f));
	for(i=0;i<=31;i++)
		f[i][0]=1;
	for(i=1;i<=31;i++)
		for(j=1;j<=31;j++){
			if(j>0)f[i][j]+=f[i-1][j-1];
			f[i][j]+=f[i-1][j];
		}
	for(i=31;i>=0;i--)f[i][1]++;
	for(i=31;i>=0;i--)
		for(j=1;j<=31;j++)
			f[i][j]+=f[i][j-1];
	while(in>>n>>l>>m){
		memset(buf,'0',sizeof(buf));
		calc(n,l,m);
		for(i=n-1;i>=0;i--)out<<buf[i];
		out<<endl;
	}
	return 0;
}