#include<iostream.h>
#include<string.h>

char buf[110][300];
int f[110][300],n;

void run(){
	int i,j,ret=0,k;
	memset(f,0,sizeof(f));
	if(buf[n-1][0]=='-')f[n-1][0]=1;
	for(i=n-2;i>=0;i--){
		for(j=0;j<2*(n-i)-1;j+=2){
			if(j==2*(n-i)-2){
				if(buf[i][j]=='-')f[i][j]=1;
				continue;
			}
			for(k=0;k+j<2*(n-i)-1&&buf[i][k]!='#';k++);
			if(!k){
				f[i][j]=0;
				continue;
			}
			if(k%2==0)k--;
			if(f[i+1][j]>=k-2)f[i][j]=k;
			else if(f[i+1][j])f[i][j]=f[i+1][j]+2;
			else f[i][j]=1;
		}
	}
	for(i=0;i<n;i++){
		for(j=1;j<2*(n-i)-1;j+=2){
			if(!i){
				if(buf[i][j]=='-')f[i][j]=1;
				continue;
			}
			for(k=0;k+j<2*(n-i)-1&&buf[i][j+k]!='#';k++);
			if(!k)continue;
			if(k%2==0)k--;
			if(f[i-1][j+2]==0){
				f[i][j]=1;
			}
			else if(f[i-1][j+2]>=k-2)
				f[i][j]=k;
			else f[i][j]=f[i-1][j+2]+2;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<2*(n-i)-1;j++)
			if(f[i][j]>ret)ret=f[i][j];
	ret=(ret+1)*(ret+1)/4;
	cout<<"The largest triangle area is "<<ret<<"."<<endl;
}

int main(){
	int i,cnt=0;
	while(1){
		cin>>n;
		if(!n)break;
		for(i=0;i<n;i++)
			cin>>buf[i];
		cout<<"Triangle #"<<++cnt<<endl;
		run();
		cout<<endl;
	}
	return 0;
}