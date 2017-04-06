#include<iostream.h>
#include<string.h>

int mark[5100],a[11000];
int n,m;


void run(){
	int i;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		mark[a[i]]++;
	int ret=0;
	for(i=0;i<m;i++)
		ret+=mark[i]*(mark[i]-1)/2;
	ret+=mark[0];
	cout<<ret<<endl;
}
int main(){
	int i;
	while(cin>>n>>m){
		for(i=0;i<n;i++){
			cin>>a[i];
			if(!i)a[i]%=m;
			else a[i]=(a[i]+a[i-1])%m;
		}
		run();
	}
	return 0;
}