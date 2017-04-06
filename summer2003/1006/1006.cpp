#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

char mark[5100],done[5100];
int f[5100],g[5100],n,a[110],tot;

void run(){
	int i,j;
	memset(mark,0,sizeof(mark));
	memset(f,0,sizeof(f));
	mark[0]=1;
	for(i=0;i<n;i++){
		memcpy(g,f,sizeof(int)*(tot+1));
		memcpy(done,mark,sizeof(char)*(tot+1));
		for(j=0;j<=tot;j++)
			if(done[j]){
				if(f[j+a[i]]<g[j]+a[i]){
					f[j+a[i]]=g[j]+a[i];
					mark[j+a[i]]=1;
				}
				if(f[abs(j-a[i])]<g[j]+a[i]){
					f[abs(j-a[i])]=g[j]+a[i];
					mark[abs(j-a[i])]=1;
				}
			}
	}
	if(!f[0]){
		cout<<"Sorry"<<endl;
	}
	else cout<<f[0]/2<<endl;
}

int main(){
	int i;
	while(1){
		cin>>n;
		if(n<=0)break;
		tot=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			tot+=a[i];
		}
		run();
	}
	return 0;
}