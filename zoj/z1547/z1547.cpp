#include<iostream.h>
#include<math.h>
#include<stdlib.h>

#include<stdio.h>
#define MAXN 100000

int f[MAXN][3];

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void init(){
	int i,j,cnt=0,n,m;
	for(i=3;;i++){
		if(!(i%2)){
			if(i%4)continue;
			for(j=(int)sqrt(i*0.5/(1+sqrt(2)));j>=1;j--){
				if(i%(2*j))continue;
				n=j;m=i/(2*j);
				if(m%2==n%2||gcd(m,n)>1)continue;
				f[cnt][0]=2*m*n;
				f[cnt][1]=m*m-n*n;
				f[cnt++][2]=m*m+n*n;
				if(cnt==MAXN)return ;
			}
		}
		else{
			for(j=(int)sqrt(i/(1+sqrt(2)));j>=1;j--){
				if(i%j)continue;
				m=(j+i/j)/2;
				n=(i/j-j)/2;
				if(m%2==n%2||gcd(m,n)>1)continue;
				f[cnt][0]=m*m-n*n;
				f[cnt][1]=2*m*n;
				f[cnt++][2]=m*m+n*n;
				if(cnt==MAXN)return;
			}
		}
	}
}
/*
int cmp(const void *a,const void *b){
	if(*(int*)a!=*(int*)b)
		return *(int*)a-*(int*)b;
	return *((int*)a+1)-*((int*)b+1);
}

void init(){
	int m,n,cnt=0,i,j;
	for(m=1;m*2<=45000;m++){
		for(n=m+1;2*n*m<=45000;n++){
			if(n%2==m%2||gcd(m,n)>1)continue;
			if(2*m*n>n*n-m*m)continue;
			f[cnt][0]=2*m*n;
			f[cnt][1]=n*n-m*m;
			f[cnt++][2]=m*m+n*n;
		}
	}
	for(m=1;m<=45000;m++){
		for(n=1;m*n<=45000;n++){
			if(m%2!=n%2)continue;
			i=(m+n)/2;
			j=(n-m)/2;
			if(i%2==j%2||gcd(i,j)>1)continue;
			if(i*i-j*j>2*i*j)continue;
			f[cnt][0]=i*i-j*j;
			f[cnt][1]=2*i*j;
			f[cnt++][2]=i*i+j*j;
		}
	}
	qsort(f,cnt,sizeof(int)*3,cmp);
}*/

int main(){
	int n;
	init();
	while(scanf("%d",&n)==1)
		printf("%d %d %d\n",f[n-1][0],f[n-1][1],f[n-1][2]);
	return 0;
}