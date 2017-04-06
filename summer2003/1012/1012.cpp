#include<string.h>
#include<iostream.h>
#define M 2100000000
#define between(x,a) ((x)>=0&&(x)<(a))
#define inmat(x,y,a,b) (between(x,a)&&between(y,b))
int mx[8]={1,2,2,1,-1,-2,-2,-1};
int my[8]={2,1,-1,-2,-2,-1,1,2};
int tree[70][70],mat[10][10];

int mintree(int map[][70],int n){
	int i,j,ret=0,min,ti,nea[70];
	char mark[70];
	memset(mark,0,sizeof(mark));
	mark[0]=1;
	for(i=0;i<n;i++)
		nea[i]=map[0][i];
	j=1;
	while(j++<n){
		min=M;
		for(i=0;i<n;i++)
			if(!mark[i]&&nea[i]<min){
				min=nea[i];
				ti=i;
			}
		mark[ti]=1;
		for(i=0;i<n;i++)
			if(!mark[i]&&nea[i]>map[i][ti])
				nea[i]=map[i][ti];
		ret+=min;
	}
	return ret;
}

void run(){
	int i,j,k;
	for(i=0;i<64;i++)
		for(j=0;j<64;j++)
			tree[i][j]=M;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			for(k=0;k<8;k++)
				if(inmat(i+mx[k],j+my[k],8,8)){
					tree[i*8+j][(i+mx[k])*8+(j+my[k])]=mat[i][j]+mat[i+mx[k]][j+my[k]];
				}
	cout<<mintree(tree,64)<<endl;
}

int main(){
	int i,j,t;
	cin>>t;
	while(t--){
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				cin>>mat[i][j];
		run();
	}
	return 0;
}