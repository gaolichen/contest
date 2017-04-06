#include<iostream.h>
#include<string.h>
#define inf 10000

short f[110],g[110][110][2];
int n,m;

void run(){
	int i,j,k,h;
	f[0]=0;
	for(i=1;i<=m;i++)f[i]=i;
	for(i=m+1;i<=2*m;i++)f[i]=m;
	for(i=2*m+1;i<=n;i++){
		g[i][0][1]=i;
		g[0][i][0]=0;
		for(j=1;j<i;j++){
			g[j][i-j][0]=f[j];
			g[j][i-j][1]=i-f[i-j];
		}
		for(j=i-1;j>=0;j--)
			for(k=i-j-1;k>=0;k--){
				g[j][k][0]=0;
				g[j][k][1]=inf;
				for(h=1;h<=m&&h<=i-j-k;h++){
					if(g[j][k][0]<g[j+h][k][1])
						g[j][k][0]=g[j+h][k][1];
					if(g[j][k][1]>g[j][k+h][0])
						g[j][k][1]=g[j][k+h][0];
				}
			}
		f[i]=g[0][0][0];
	}
	cout<<f[n]<<endl;
}

int main(){
	while(cin>>n>>m)run();
	return 0;
}