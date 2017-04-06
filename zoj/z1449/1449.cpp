#include<iostream.h>
#include<string.h>

int a[21][21][21],n;
void run(){
	int max=-2100000000,sum,i,j,k,h,l;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=i+1;k<=n;k++)
				for(h=j+1;h<=n;h++){
					for(sum=0,l=0;l<n;l++){
						sum=(sum>0?sum:0)+a[l][k][h]-a[l][i][h]-a[l][k][j]+a[l][i][j];
						max=(max>sum?max:sum);
					}
				}
	cout<<max<<endl;
}

int main(){
	int i,j,k;
	while(1){
		cin>>n;
		if(!n)break;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++){
					cin>>a[i][j][k];
					a[i][j][k]+=a[i][j-1][k]+a[i][j][k-1]-a[i][j-1][k-1];
				}
		run();
	}
	return 0;
}