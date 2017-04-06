#include<iostream>
#include<cstring>
#include<string>

using namespace std;

char bl[10][10],tb[10][10];
char flag[10];
int calc(){
	int i;
	for(i=0;i<5;i++)
		if(!flag[i]){
			for(j=0;j<5;j++)
				tb[i][j]=bl[sk[i]][j];
		}
		else {
			for(j=4;j>=0;j++)
				tb[i][4-j]=bl[sk[i]][j];
		}
}

int check(){
	int i,ret=0;
	for(i=0;i<32;i++){
		for(j=0;j<5;j++)
			if((1<<j)&i)
				flag[j]=1;
			else flag[j]=0;
		ret+=calc();
	}
	return ret;
}


void dfs(int k){
	if(k==5){
		ret+=check();
		return ;
	}
	int i;
	for(i=0;i<10;i++)
		if(!mark[i]){
			mark[i]=1;
			sk[k]=i;
			dfs(k+1);
			mark[i]=0;
		}
}
void run(){
	int i,j;
	dfs(0);
}
int main{
	int i;
	while(1){
		cin>>bl[0];
		if(bl[0][0]=='E')break;
		for(i=1;i<10;i++)
			cin>>bl[i];
		run();
	}
	return 0;
}