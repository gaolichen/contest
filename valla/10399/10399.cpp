#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 3000000

int p[1000000],n,count;
char mark[M+1],f[1000000];

void run(){
	int i,j,k;
	i=count-1;
	j=i-1;
	memset(f,0,sizeof(f));
	f[j]=1;
	while(j>0&&p[i]-p[j]<=n)f[--j]=1;
	if(j>=0){
		for(;j>=0;j--){
			for(k=j+1;k<i;k++){
				if(p[k]-p[j]>n)break;
				if(f[k]==1){
					f[j]=2;
					break;
				}
			}
			if(!f[j])f[j]=1;
		}
	}
	for(i=0;p[i]<=n;i++)
		if(f[i]==1)break;
	if(p[i]>n)
		cout<<"B"<<endl;
	else
		cout<<"A "<<p[i]<<endl;
}
void init(){
	int i,j;
	count=0;
	memset(mark,0,sizeof(mark));
	for(i=2;i<=M;i++)
		if(!mark[i]){
		for(j=i;i*j>0&&i*j<=M;j++)
			mark[i*j]=1;
		p[count++]=i;
		}
}
int main(){
	int t;
	init();
	cin>>t;
	while(t--){
		cin>>n;
		run();
	}
	return 0;
}