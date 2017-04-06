#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAXN 6

double a[MAXN][MAXN],b[MAXN];

void calc(double a[][MAXN],double *b,int n,double w,double *x,double *xx){
	int i,j;
	double dlt;
	for(i=0;i<n;i++){
		dlt=b[i];
		for(j=0;j<i;j++)
			dlt-=a[i][j]*xx[j];
		for(j=i;j<n;j++)
			dlt-=a[i][j]*x[j];
		xx[i]=x[i]+w*dlt/a[i][i];
	}
}

void sor(double a[][MAXN],double *b,int n,double w,double dlt){
	double x[MAXN],xx[MAXN],max;
	int i,cnt=0;
	memset(xx,0,sizeof(xx));
	while(1){
		cnt++;
		memcpy(x,xx,sizeof(xx));
		calc(a,b,n,w,x,xx);
		for(i=0,max=0;i<n;i++)
			if(fabs(xx[i]-x[i])>max)max=fabs(xx[i]-x[i]);
		if(max<dlt){
			printf("%d times\n",cnt);
			for(i=0;i<n;i++)
				printf("x%d = %lf\n",i+1,xx[i]);
			return ;
		}
	}
}

int main(){
	int i,j,n;
	double w,dlt;
	scanf("%d",&n);
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			scanf("%lf",&a[i][j]);
	for(i=0;i<6;i++)
		scanf("%lf",&b[i]);
	w=1.0;
	dlt=1e-5;
	sor(a,b,n,w,dlt);
	w=1.1;
	sor(a,b,n,w,dlt);
	return 0;
}

/*
input data:
6
4 -1 0 -1 0 0
-1 4 -1 0 -1 0
0 -1 4 0 0 -1
-1 0 0 4 -1 0
0 -1 0 -1 4 -1
0 0 -1 0 -1 4
2 1 2 2 1 2
*/