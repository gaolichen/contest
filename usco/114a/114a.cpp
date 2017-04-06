/*
ID:  mygali1
PROG: checker
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
ifstream in("checker.in");
ofstream out("checker.out");
#endif

int n,sk[20],ans;
char mark[20];
int check(int k,int r){
	int i;
	for(i=0;i<k;i++){
		if(r+k==sk[i]+i)return 0;
		if(r-k==sk[i]-i)return 0;
	}
	return 1;
}
void dfs(int k){
	if(k==n){
		ans++;
		if(ans<=3){
			for(int i=0;i<n;i++){
				if(i)out<<' ';
				out<<sk[i]+1;
			}
			out<<endl;
		}
		return ;
	}
	for(int i=0;i<n;i++)
		if(!mark[i]&&check(k,i)){
			mark[i]=1;
			sk[k]=i;
			dfs(k+1);
			mark[i]=0;
		}
}
void run(){
	memset(mark,0,sizeof(mark));
	ans=0;
	dfs(0);
	out<<ans<<endl;
}
int main(){
	while(in>>n)run();
	return 0;
}