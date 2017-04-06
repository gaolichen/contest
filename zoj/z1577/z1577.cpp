#include<iostream.h>
#include<string.h>
#define i64 long long

const int maxn=1000000;

int x,y,p[maxn],cnt;
char mark[maxn];
void run(){
	if(y%x){
		cout<<0<<endl;
		return;
	}
	y/=x;
	int ret=1,i,j;
	for(i=0;j=0,i<cnt&&p[i]<=y;i++,ret<<=(j?1:0))
		while(y%p[i]==0)y/=p[j++,i];
	cout<<ret<<endl;
}

void init(){
	i64 i,j;
	memset(mark,0,sizeof(mark));
	for(i=2,cnt=0;i<maxn;i++)if(!mark[i]){
		for(j=i*i;j<maxn;j+=i)
			mark[j]=1;
		p[cnt++]=(int)i;
	}
}
int main(){
	init();
	while(cin>>x>>y)run();
	return 0;
}