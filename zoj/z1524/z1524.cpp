#include<iostream.h>
#include<stdio.h>
#include<string.h>

int list[200],pro[110000];
double cost[110000],f[110],g[110];
int m,n;

void run(){
	int i,j;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(i=1;i<=n;i++){
		for(j=1,f[0]=0;j<=m&&j<=i;j++)
			if(list[j-1]==pro[i-1]&&(j==1||g[j-1])){
				if(!f[j]||f[j]>g[j-1]+cost[i-1])
					f[j]=g[j-1]+cost[i-1];
//				printf("%d %d %lf\n",i,j,f[i][j]);
			}
		memcpy(g,f,sizeof(g));
	}
	if(!f[m])
		printf("Impossible\n");
	else printf("%.2lf\n",f[m]);
}


int main(){
	int i;
	while(cin>>m>>n){
		if(!m&&!n)break;
		for(i=0;i<m;i++)
			cin>>list[i];
		for(i=0;i<n;i++)
			cin>>pro[i]>>cost[i];
		run();
	}
	return 0;
}