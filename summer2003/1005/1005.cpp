#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 110000
#ifdef WIN32
#define i64 __int64
#else
#define i64 long long
#endif
int f[MAXN],fcnt;
int p[MAXN],pcnt;
char mark[MAXN];

void init(){
	i64 i,j;
	pcnt=0;
	memset(mark,0,sizeof(mark));
	for(i=2;i<MAXN;i++)
		if(!mark[i]){
			for(j=i*i;j>0&&j<MAXN;j+=i)
				mark[j]=1;
			p[pcnt++]=(int)i;
		}
	fcnt=0;
	for(i=2;i+6<MAXN;i++)
		if(!mark[i]&&!mark[i+6])
			f[fcnt++]=i;
}
int main(){
	int cnt=0,n;
	init();
	while(cin>>n){
		int i=f[n-1];
		if(cnt&&cnt%5==0)
			putchar('\n');
		else if(cnt)putchar(',');
		printf("(%5d,%6d)",i,i+6);
		cnt++;
	}
	putchar('\n');
	return 0;
}
