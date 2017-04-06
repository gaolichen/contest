/*
ID:  mygali1
PROG: preface
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
ifstream in("preface.in");
ofstream out("preface.out");
#endif

char cap[7]={'I','V','X','L','C','D','M'};
int ten[4]={0,2,4,6};
int num[7]={1,5,10,50,100,500,1000};
int p[10][3]={{0,0,0},{1,0,0},{2,0,0},{3,0,0},{1,1,0},
{0,1,0},{1,1,0},{2,1,0},{3,1,0},{1,0,1}};
int f[4000][7];
void cut(int k){
	int i=0,t=k,j;
	while(i<4){
		j=k%10;
		f[t][ten[i]]+=p[j][0];
		f[t][ten[i]+1]+=p[j][1];
		f[t][ten[i]+2]+=p[j][2];
		k/=10;
		i++;
	}
}
void run(){
	int i;
	memset(f[0],0,sizeof(f));
	for(i=1;i<=3500;i++){
		memcpy(f+i,f+i-1,sizeof(f[0]));
		cut(i);
	}
}
int main(){
	int n,i;
	run();
//	for(i=0;i<=10;i++)
//		out<<f[i][0]<<' '<<f[i][1]<<' '<<f[i][2]<<endl;
	while(in>>n){
		for(i=0;i<7&&f[n][i];i++)
			out<<cap[i]<<' '<<f[n][i]<<endl;
	}
	return 0;
}