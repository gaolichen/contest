#include<iostream.h>
#include<string.h>
#include<stdlib.h>

int m,n,a[10];
char sk[6000],ret[1000],mark[6000];
short ans[6000],pre[6000];

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

void bfs(){
	int opn=-1,cls,flag=0,i;
	for(i=0;i<m;i++)
		if(a[i]&&!mark[a[i]%n]){
			sk[++opn]=a[i];
			ans[opn]=a[i]%n;
			if(!ans[opn])flag=opn;
			mark[a[i]%n]=1;
			pre[opn]=-1;
		}
	cls=opn;
	opn=0;
	while(opn<=cls&&!mark[0]){
		for(i=0;i<m;i++)
			if(!mark[(10*ans[opn]+a[i])%n]){
				sk[++cls]=a[i];
				ans[cls]=(10*ans[opn]+a[i])%n;
				pre[cls]=opn;
				mark[ans[cls]]=1;
				if(!ans[cls]){
					flag=cls;
					break;
				}
				while(cls>=5999);
			}
		opn++;
	}
	if(!mark[0]){
		cout<<0<<endl;
		return ;
	}
	i=0;
	while(flag!=-1){
		ret[i++]=sk[flag];
		while(i>=1000);
		flag=pre[flag];
	}
	while(--i>=0)cout<<(int)ret[i];
	cout<<endl;
}

void run(){
	int i,j;
	if(n==0){
		cout<<0<<endl;
		return ;
	}
	qsort(a,m,sizeof(int),cmp);
	for(i=j=0;i<m;i++)
		if(!i||a[i]!=a[i-1])
			a[j++]=a[i];
	m=j;
	memset(mark,0,sizeof(mark));
	bfs();
}
int main(){
	int i;
	while(cin>>n>>m){
		for(i=0;i<m;i++)
			cin>>a[i];
		run();
	}
	return 0;
}