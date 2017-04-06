#include<stdio.h>
#include<math.h>
#include<string.h>

int m;
double x[10],y[10],mat[10][10],c[10][10],b[10],a[10];

void gauss(double mat[][10],double *g,int n){
	int i,j,k;
	double ans,tmp,max;
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
	printf("y=");
	printf("%lf",a[0]);
	for(i=1;i<n;i++){
		if(a[i]>=0)putchar('+');
		printf("%lfx",a[i]);
		if(i>1)printf("^%d",i);
	}
	putchar('\n');
	ans=max=0;
	for(i=0;i<m;i++){
		tmp=0;
		for(j=n-1;j>=0;j--)
			tmp=tmp*x[i]+a[j];
		ans+=(tmp-y[i])*(tmp-y[i]);
		if(fabs(tmp-y[i])>max)
			max=fabs(tmp-y[i]);
	}
	printf("%lf %lf\n",sqrt(ans),max);
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
	while(scanf("%d",&m)==1){
		for(i=0;i<m;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		run(1);/*一次拟合*/
		run(2);/*二次拟合*/
	}
	return 0;
}

/*

输入格式:

4
2 2
4 11
6 28
8 40


*/