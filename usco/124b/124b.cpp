/*
ID:  mygali1
PROG: milk3
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("milk3.in");
ofstream out("milk3.out");
#endif

int f[30],a[3],c[1000][3],temp[3],mark[21][21][21];
int pure(int va,int vb,int a,int b){
	int t=va;
	vb+=va;
	va=0;
	if(vb>b){
		t-=vb-b;
		vb-=b;
	}
	return t;
}

void run(){
	int i,j,open,close,k;
	memset(mark,0,sizeof(mark));
	mark[0][0][a[2]]=1;
	open=close=0;
	c[0][0]=0;c[0][1]=0;c[0][2]=a[2];
	while(open<=close){
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(i!=j){
					k=pure(c[open][i],c[open][j],a[i],a[j]);
					memcpy(temp,c[open],sizeof(c[open]));
					temp[i]-=k;
					temp[j]+=k;
					if(mark[temp[0]][temp[1]][temp[2]])continue;
					mark[temp[0]][temp[1]][temp[2]]=1;
					c[++close][0]=temp[0];
					c[close][1]=temp[1];
					c[close][2]=temp[2];
				}
			open++;
	}
	j=0;
	for(i=0;i<=a[2];i++)
		if(mark[0][a[2]-i][i]){
			if(j++)out<<' ';
			out<<i;
		}
	out<<endl;
}
int main(){
	while(in>>a[0]>>a[1]>>a[2])run();
	return 0;
}