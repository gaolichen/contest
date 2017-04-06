#include<stdio.h>
#include<string.h>
#include<iostream.h>

int n,nc;
int p[8]={1,2,4,8,16,32,64,128};


unsigned char mark[3000000];
char sub[17000000];
int cap[30],a[100];


int calc(int *a){
	int i,ret=0;
	for(i=0;i<n;i++){
		ret=ret*(nc)+a[i]-1;
	}
	return ret;
}

void run(){
	int i,cnt=0,j;
	memset(cap,0,sizeof(cap));
	for(i=0;sub[i];i++){
		if(cnt==nc)break;
		if(!cap[sub[i]-'a']){
			cap[sub[i]-'a']=1;
			cnt++;
		}
	}
	cnt=1;
	for(i=0;i<26;i++)
		if(cap[i])cap[i]=cnt++;
	cnt=0;
	for(i=0;sub[i+n-1];i++){
		for(j=0;j<n;j++){
			a[j]=cap[sub[i+j]-'a'];
		}
		j=calc(a);
		if(!(mark[j/8]&p[j%8])){
			mark[j/8]+=p[j%8];
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
int main(){
	int t;
	char buf[100];
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&nc);
		memset(mark,0,sizeof(mark));
		gets(buf);
		gets(sub);
		run();
		if(t)putchar('\n');
	}
	return 0;
}