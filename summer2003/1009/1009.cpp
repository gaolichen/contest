#include<iostream>
#include<cstring>
#define MAXN 110

using namespace std;

char mat[MAXN][MAXN];
int f[MAXN][MAXN],n;
void run(){
	int i,j,k,h;
	int max;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
			max=0;
			for(k=i;k>0&&max<j;k--){
				for(h=j;h>max;h--)
					if(mat[k-1][h-1]=='#'){
						max=h;
						break;
					}
				f[i][j]+=j-max;
			}
		}
	cout<<f[n][n]<<endl;
}

int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>mat[i];
		run();
	}
	return 0;
}