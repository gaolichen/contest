#include<iostream.h>
#include<string.h>


int count,prime[100],mark[100],sk[100],n;
int tot[100],num[100][100];
void init(){
	int i,j;
	memset(prime,0,sizeof(prime));
	prime[0]=prime[1]=1;
	for(i=2;i<50;i++)
		if(!prime[i])
		for(j=i;j*i<50;j++)
			prime[i*j]=1;
}

void dfs(int k){
	int i;
	if(k==n){
		if(!prime[sk[n-1]+sk[0]]){
			for(i=0;i<n;i++){
				if(i)cout<<' ';
				cout<<sk[i];
			}
			cout<<endl;
		}
		return ;
	}
	for(i=0;i<tot[sk[k-1]];i++)
		if(!mark[num[sk[k-1]][i]]){
			sk[k]=num[sk[k-1]][i];
			mark[sk[k]]=1;
			dfs(k+1);
			mark[sk[k]]=0;
		}
}

void run(){
	int i,j;
	cout<<"Case "<<++count<<":"<<endl;
	if(n%2==1){
		cout<<endl;
		return ;
	}
	memset(tot,0,sizeof(tot));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(!prime[i+j])
				num[i][tot[i]++]=j;
	sk[0]=1;
	memset(mark,0,sizeof(mark));
	mark[1]=1;
	dfs(1);
	cout<<endl;
}
int main(){
	init();
	count=0;
	while(cin>>n)run();
	return 0;
}