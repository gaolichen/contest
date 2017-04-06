#include<stdio.h>
#include<iostream.h>

int n,m;
int f[110][110];
void init(){
	int i,j;
	f[0][0]=0;
	f[2][2]=1;
	f[2][1]=f[1][2]=0;
	f[2][0]=f[0][2]=0;
	for(i=2;i<=100;i++)
		for(j=i;j<=100;j++){
			f[i][j]=f[j][i]=2*f[i][j-1]-f[i][j-2];
			if(i==j)f[j][i]=(f[i][j]+=i-1);
		}
	for(i=2;i<=20;i++)
		printf("%d %d\n",i,f[i][i]);
	putchar('\n');

}

void run(){
	int i;
	double tot=1.0;
	for(i=n*n;i>=n*n-3;i--)
		tot*=i;
	tot*=m/(2400.0);
	printf("%.2lf\n",tot/f[n][n]);
}
int main(){
	init();
	while(1){
		cin>>n>>m;
		if(!n&&!m)break;
		run();
	}
	return 0;
}