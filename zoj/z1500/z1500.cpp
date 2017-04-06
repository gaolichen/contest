#include<iostream.h>
#include<string.h>
#define T long long

int m;
T c[30][30];
char pre[30],aft[30];

void init(){
	int i,j;
	for(i=0;i<=20;i++)
		c[i][0]=c[i][i]=1;
	for(i=1;i<=20;i++)
		for(j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
}

T dfs(char*a,char*b,int len){
	if(a[0]!=b[len-1])return 0;
	if(len==1)return 1;
	int i,j,k,t;
	T ret=1;
	for(i=1,j=k=t=0;i<len;){
		while(b[j]!=a[i])j++;
		ret*=dfs(a+i,b+t,j-t+1);
		i+=j-t+1;
		t=j+1;
		k++;
	}
	return ret*c[m][k];
}

void run(){
	cout<<dfs(pre,aft,strlen(pre))<<endl;
}
int main(){
	init();
	while(1){
		cin>>m;
		if(!m)break;
		cin>>pre>>aft;
		run();
	}
	return 0;
}