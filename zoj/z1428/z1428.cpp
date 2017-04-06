#include<iostream.h>
#include<string.h>

int f[30][30][30],d[30][30],n;
char mark[30][30][30];

void run(){
	int i,j,k;
	memset(mark,0,sizeof(mark));
	mark[0][0][0]=1;
	for(i=0;i<n-1;i++)
		for(j=0;j<=i;j++)
			for(k=0;k<=j;k++)
				if(mark[j][k][i]){
					if(!mark[j][k][i+1]||f[j][k][i]+d[i][i+1]<f[j][k][i+1]){
						f[j][k][i+1]=f[j][k][i]+d[i][i+1];
						mark[j][k][i+1]=1;
					}
					if(!mark[i][k][i+1]||f[j][k][i]+d[j][i+1]<f[i][k][i+1]){
						f[i][k][i+1]=f[j][k][i]+d[j][i+1];
						mark[i][k][i+1]=1;
					}
					if(!mark[i][j][i+1]||f[j][k][i]+d[k][i+1]<f[i][j][i+1]){
						f[i][j][i+1]=f[j][k][i]+d[k][i+1];
						mark[i][j][i+1]=1;
					}
				}
	int ans=2100000000;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if(mark[j][i][n-1]&&f[j][i][n-1]<ans)
				ans=f[j][i][n-1];
	cout<<ans<<endl;
}

int main(){
	int t,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		memset(d,0,sizeof(d));
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++){
				cin>>d[i][j];
				d[j][i]=d[i][j];
			}
		run();
	}
	return 0;
}