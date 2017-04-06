#include<iostream.h>
#include<string.h>

int f[110][110],n,a[110];

void run(){
	int i,j,k;
	memset(f,0,sizeof(f));
	for(i=2;i<n;i++){
		for(j=0;j<n-i;j++)
			for(k=j+1;k<j+i;k++)
				if(!f[j][j+i]||f[j][j+i]>a[j]*a[k]*a[j+i]+f[j][k]+f[k][j+i])
					f[j][j+i]=a[j]*a[k]*a[j+i]+f[j][k]+f[k][j+i];
	}
	cout<<f[0][n-1]<<endl;
}

int main(){
	int i;
	for(;cin>>n;run())
		for(i=0;i<n;i++){
			cin>>a[i];
		}
	return 0;
}