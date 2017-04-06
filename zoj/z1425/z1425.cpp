#include<iostream.h>
#include<stdio.h>
#include<string.h>

int n[2],f[110][110],a[2][110];
void run(){
	int i,j,k,h;
	memset(f,0,sizeof(f));
	for(i=2;i<=n[0];i++)
		for(j=2;j<=n[1];j++){
			f[i][j]=f[i-1][j-1];
			if(f[i][j-1]>f[i][j])
				f[i][j]=f[i][j-1];
			if(f[i-1][j]>f[i][j])
				f[i][j]=f[i-1][j];
			if(a[0][i]!=a[1][j]){
				for(k=i-1;k>0;k--)
					if(a[0][k]==a[1][j])break;
				if(k<=0)continue;
				for(h=j-1;h>0;h--)
					if(a[1][h]==a[0][i])break;
				if(h<=0)continue;
				f[i][j]=(f[i][j]<f[k-1][h-1]+2?f[k-1][h-1]+2:f[i][j]);
			}
		}
	cout<<f[n[0]][n[1]]<<endl;
}
int main(){
	int t,j,i;
	cin>>t;
	while(t--){
		cin>>n[0]>>n[1];
		for(i=0;i<2;i++)
			for(j=0;j<n[i];j++)
				cin>>a[i][j+1];
		run();
	}
	return 0;
}