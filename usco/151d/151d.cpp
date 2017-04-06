
/*
ID:  mygali1
PROG: latin
*/
#define for if(0);else for
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
#define MAXN 110
//#define DEBUG
#ifdef DEBUG
#define cin cin
#define cout cout
#else 
#define cin in
#define cout out
ifstream in("latin.in");
ofstream out("latin.out");
#endif

int n;
int ans;
char r[10][10],c[10][10];

int dfs(int x,int y){
	if(x==n-1){
		return 1;
	}
	if(y>=n){
		return dfs(x+1,1);
	}
	int ret=0;
	int     s[2] = {-1, -1},t=0;
	for(int i=0;i<n;i++)if(!r[x][i]&&!c[y][i]){
		if(i>y)t=1;
		if(x==1&&s[t]!=-1){
			ret+=s[t];continue;	
		}
		r[x][i]=c[y][i]=1;
		s[t]=dfs(x,y+1);
		ret+=s[t];
		r[x][i]=c[y][i]=0;
	}
	return ret;
}
void run(){
	memset(r,0,sizeof(r));memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)r[0][i]=c[0][i]=r[i][i]=c[i][i]=1;
	long long ret=(long long)dfs(1,1);
	for(int i=n-1;i>=1;i--)ret*=i;
	cout<<ret<<endl;
}
int main(){
	while(cin>>n){
		run();
	}
	return 0;
}