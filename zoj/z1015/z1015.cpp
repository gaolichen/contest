#include<iostream.h>
#include<string.h>
#include<stdio.h>

int n,m,sk[2000],count;
char map[1100][1100],mark[1100];

int dfs(int k){
	int i;
	for(i=0;i<n;i++)
		if(!mark[i]&&!map[i][sk[1]]&&map[i][sk[k-1]]){
			sk[count++]=i;
			if(map[i][sk[0]])return 1;
			mark[i]=1;
		}
	if(k<count&&dfs(k+1))return 1;
	return 0;
}
void run(){
	int i,j,k;
	if(m>=n*(n-1)/2-1){
		puts("Perfect");
		return ;
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(map[i][j])
				for(k=0;k<n;k++)
					if(map[j][k]&&k!=i&&!map[i][k]){
						sk[0]=i;sk[1]=j;
						sk[2]=k;
						memset(mark,0,sizeof(mark));
						mark[i]=mark[j]=mark[k]=1;
						count=3;
						if(dfs(3)){
							puts("Imperfect");
							return ;
						}
					}
	puts("Perfect");
}
int main(){
	int i,j,k;
	while(1){
		scanf("%d%d",&n,&m);
		if(!n&&!m)break;
		memset(map,0,sizeof(map));
		for(i=0;i<m;i++){
			scanf("%d%d",&j,&k);
			map[j-1][k-1]=map[k-1][j-1]=1;
		}
		run();
		putchar('\n');
	}
	return 0;
}