#include<stdio.h>
#include<math.h>
#include<string.h>


int m;
double x[10],y[10],mat[10][10],c[10][10],b[10],a[10];

void gauss(double mat[][10],double *g,int n){
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j){
				g[j]-=g[i]*(mat[j][i]/mat[i][i]);
				for(k=n-1;k>=i;k--)
					mat[j][k]-=mat[i][k]*(mat[j][i]/mat[i][i]);
			}
	for(i=0;i<n;i++){
		a[i]=g[i]/mat[i][i];
	}
	printf("W=");
	printf("%lft^(%lf)\n",exp(a[0]),a[1]);
}

void run(int n){
	int i,j,k;
	double tmp;
	for(i=0;i<m;i++){
		tmp=1.0;
		for(j=0;j<=n;j++){
			c[i][j]=tmp;
			tmp*=x[i];
		}
	}
	memset(mat,0,sizeof(mat));
	memset(b,0,sizeof(b));
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			for(k=0;k<m;k++)
				mat[i][j]+=c[k][i]*c[k][j];
	for(i=0;i<=n;i++)
		for(k=0;k<m;k++)
			b[i]+=c[k][i]*y[k];
	gauss(mat,b,n+1);
}
int main(){
	int i;
	double tmp1,tmp2;
	while(scanf("%d",&m)==1){
		for(i=0;i<m;i++){
			scanf("%lf %lf",&tmp1,&tmp2);
			x[i]=log(tmp1);
			y[i]=log(tmp2);
		}
		run(1);
	}
	return 0;
}

/*
7
1 4.22
2 4.02
4 3.85
8 3.59
16 3.44
32 3.02
64 2.59

*/