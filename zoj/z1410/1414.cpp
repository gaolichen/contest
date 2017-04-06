#include<iostream.h>
#define M 35000
unsigned int f[M],g[M],n;
inline int dig(int n){
	int ret=0;
	while(n){
		ret++;
		n/=10;
	}
	return ret;
}
void init(){
	int i;
	f[1]=1;f[0]=0;
	for(i=2;i<M;i++)
		f[i]=f[i-1]+dig(i);
	g[1]=1;g[0]=0;
	for(i=2;i<M;i++)
		g[i]=g[i-1]+f[i];
}

void run(){
	unsigned int i,j;
	for(i=1;;i++)
		if(g[i]>=n)break;
	if(g[i]==n){
		cout<<i%10<<endl;
		return ;
	}
//	cout<<i<<endl;
	j=n-g[i-1];
	for(i=1;;i++)
		if(f[i]>=j)break;
	if(f[i]==j){
		cout<<i%10<<endl;
		return ;
	}
//	cout<<i<<endl;
	j-=f[i-1];
	j=dig(i)-j;
//	cout<<j<<endl;
	while(j--){
		i/=10;
	}
	cout<<i%10<<endl;
}
int main(){
	init();
//	for(int i=1;i<=10;i++)
//		cout<<g[i]<<' '<<f[i]<<endl;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		run();
	}
	return 0;
}