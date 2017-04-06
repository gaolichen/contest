/*
ID:  mygali1
PROG: agrinet
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("agrinet.in");
ofstream out("agrinet.out");
#endif

int map[300][300];

int mintree(int map[][300],int n){
	int i,j,ret=0,min,ti,nea[300];
	char mark[300];
	memset(mark,0,sizeof(mark));
	mark[0]=1;
	for(i=0;i<n;i++)
		nea[i]=map[0][i];
	j=1;
	while(j++<n){
		min=M;
		for(i=0;i<n;i++)
			if(!mark[i]&&nea[i]<min){
				min=nea[i];
				ti=i;
			}
		mark[ti]=1;
		for(i=0;i<n;i++)
			if(!mark[i]&&nea[i]>map[i][ti])
				nea[i]=map[i][ti];
		ret+=min;
	}
	return ret;
}
int main(){
	int i,j,n;
	while(in>>n){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				in>>map[i][j];
				if(map[i][j]==0)map[i][j]=M;
			}
		out<<mintree(map,n)<<endl;
	}
	return 0;
}