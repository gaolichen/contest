#include<iostream.h>
#include<string.h>
#include<math.h>
#define esp 1e-6
#define MAXN 200

double z[MAXN];

double calc1(double mat[][MAXN],int *r,int m,int n){
	double x[MAXN];
	int i;
	memset(x,0,sizeof(x));
	for(i=0;i<m;i++)
		x[r[i]]=mat[i][m+n];
	double ret=0;
	for(i=0;i<n;i++)
		ret+=z[i]*x[i];
	return ret;
}

void change(double mat[][MAXN],int x,int y,int m,int n){
	int i,j;
	double tmp;
	for(i=0;i<n;i++)
		if(i!=y)mat[x][i]/=mat[x][y];
	mat[x][y]=1;
	for(i=0;i<m;i++)
		if(i!=x){
			tmp=mat[i][y];
			for(j=0;j<n;j++)
				mat[i][j]-=tmp*mat[x][j];
		}
}

double calc(double mat[][MAXN],int *r,int m,int n){
	int i,j;
	for(i=0;i<=n+m;i++)
		if(mat[m][i]>esp)break;
	if(i>n+m){
		return calc1(mat,r,m,n);
	}
	int max=0;
	for(i=0;i<n+m;i++)
		if(mat[m][i]>mat[m][max])max=i;
	int min=-1;
	for(j=0;j<m;j++){
		if(mat[j][max]>esp&&(min==-1||mat[j][n+m]/mat[j][max]<mat[min][n+m]/mat[min][max]))
			min=j;
	}
	change(mat,min,max,m+1,n+m+1);
	r[min]=max;
	return calc(mat,r,m,n);
}

	/**
	 *  x[][]*a[]<=b[]; max{ret=z[]*a[]}
	 */

double pl(double *z,double x[][MAXN],double *b,int m,int n){
	double mat[MAXN][MAXN];
	int r[MAXN];
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			mat[i][j]=x[i][j];
		for(j=n;j<n+m;j++){
			if(j==n+i)mat[i][j]=1;
			else mat[i][j]=0;
		}
		mat[i][n+m]=b[i];
	}
	for(i=0;i<=m+n;i++){
		if(i<n)mat[m][i]=z[i];
		else mat[m][i]=0;
	}
	for(i=0;i<m;i++)r[i]=i+n;
	return calc(mat,r,m,n);
}