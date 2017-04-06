/*
ID:  mygali1
PROG: zerosum
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
ifstream in("zerosum.in");
ofstream out("zerosum.out");
#endif

int n,num[20],mark[20],op[20],sk[20];

int check(){
	int i,j,ret,t=n;
	for(i=1;i<=n;i++)
		num[i]=i;
	memset(mark,0,sizeof(mark));
	memcpy(op,sk,sizeof(sk));
	for(i=1;i<n;i++)
		if(op[i]==0){
			mark[i]=1;
			num[i+1]=num[i]*10+num[i+1];
		}
	for(i=j=1;i<n;i++)
		if(!mark[i]){
			op[j++]=op[i];
		}
		for(i=j=1;i<=n;i++)
			if(!mark[i])num[j++]=num[i];
		n=j-1;
		ret=num[1];
		for(i=1;i<n;i++){
			if(op[i]==1)
				ret+=num[i+1];
			else ret-=num[i+1];
		}
		n=t;
		return ret==0;
}

void output(){
	int i;
	out<<1;
	for(i=1;i<n;i++){
		if(sk[i]==0)out<<' ';
		if(sk[i]==1)out<<'+';
		if(sk[i]==2)out<<'-';
		out<<i+1;
	}
	out<<endl;
}
void dfs(int k){
	if(k==n){
		if(check())output();
		return ;
	}
	for(int i=0;i<3;i++){
		sk[k]=i;
		dfs(k+1);
	}
}
int main(){
	while(in>>n)dfs(1);
	return 0;
}