#include<stdio.h>
#include<math.h>
#include<string.h>

double x[10],y[10],s,t,mat[10][10],a[10],g[10];

int n;

void gauss(double mat[][10],double *g,int n){
	int i,j,k;
	double tmp;
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
	for(i=1;i<n;i++){
		printf("S%d(x)=",i);
		tmp=(a[i]-a[i-1])/(6*(x[i]-x[i-1]));
		printf("%lfx^3",tmp);
		tmp=0.5*(x[i]*a[i-1]-x[i-1]*a[i])/(x[i]-x[i-1]);
		if(tmp>=0)putchar('+');
		printf("%lfx^2",tmp);
		tmp=0.5*(x[i-1]*x[i-1]*a[i]-x[i]*x[i]*a[i-1])/(x[i]-x[i-1]);
		tmp+=(y[i]-y[i-1])/(x[i]-x[i-1])+(x[i]-x[i-1])*(a[i-1]-a[i])/6.0;
		if(tmp>=0)putchar('+');
		printf("%lfx",tmp);
		tmp=1/6.0*(a[i-1]*x[i]*x[i]*x[i]-a[i]*x[i-1]*x[i-1]*x[i-1])/(x[i]-x[i-1]);
		tmp+=(x[i]*y[i-1]-x[i-1]*y[i])/(x[i]-x[i-1]);
		tmp+=1/6.0*(a[i]*x[i-1]-a[i-1]*x[i])*(x[i]-x[i-1]);
		if(tmp>=0)putchar('+');
		printf("%lf",tmp);
		printf("\t(%.2lf<=x<=%.2lf)\n",x[i-1],x[i]);
	}
	putchar('\n');
}

void run1(){
	int i;
	memset(mat,0,sizeof(mat));
	for(i=1;i<n;i++){
		mat[i][i-1]=(x[i]-x[i-1])/(x[i+1]-x[i-1]);
		mat[i][i]=2;
		mat[i][i+1]=1-mat[i][i-1];
		g[i]=6.0/(x[i+1]-x[i-1])*((y[i+1]-y[i])/(x[i+1]-x[i])-(y[i]-y[i-1])/(x[i]-x[i-1]));
	}
	mat[0][0]=mat[n][n]=2;mat[0][1]=mat[n][n-1]=1;
	g[0]=6.0/(x[1]-x[0])*((y[1]-y[0])/(x[1]-x[0])-s);
	g[n]=6.0/(x[n]-x[n-1])*(t-(y[n]-y[n-1])/(x[n]-x[n-1]));	
	gauss(mat,g,n+1);
}

void run2(){
	int i;
	memset(mat,0,sizeof(mat));
	for(i=1;i<n;i++){
		mat[i][i-1]=(x[i]-x[i-1])/(x[i+1]-x[i-1]);
		mat[i][i]=2;
		mat[i][i+1]=1-mat[i][i-1];
		g[i]=6.0/(x[i+1]-x[i-1])*((y[i+1]-y[i])/(x[i+1]-x[i])-(y[i]-y[i-1])/(x[i]-x[i-1]));
	}
	mat[0][0]=mat[n][n]=1;
	g[0]=s;
	g[n]=t;
	gauss(mat,g,n+1);
}
int main(){
	int i;
	while(scanf("%d",&n)==1){
		for(i=0;i<=n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		scanf("%lf %lf",&s,&t);
		run1();/*第一种边界*/
		run2();/*第二种边界*/
	}
	return 0;
}
/*
输入格式:

3
0 0
1 0
2 0
3 0
1 0


*/