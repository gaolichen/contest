#include<stdio.h>
#include<string.h>
#include<math.h>
#define esp 1e-6

double a[10][10],x[10],b[10],l[10][10],u[10][10],c[10][10];
int n,p[10];

void gauss(double a[][10],double *b,int n,double *x){
	int i,j,max,k;
	double t1;
	for(i=0;i<n;i++)
	{	
		for(j=i+1,max=i;j<n;j++)
			if(fabs(a[j][i])>fabs(a[max][i]))
				max=j;
		if(fabs(a[max][i])<esp)continue;
		j=p[i];
		p[i]=p[max];
		p[max]=j;
		if(max!=i)
		{
			for(j=0;j<n;j++)
			{
				t1=a[i][j];a[i][j]=a[max][j];
				a[max][j]=t1;
				t1=c[i][j];c[i][j]=c[max][j];
				c[max][j]=t1;
			}
			t1=b[i];b[i]=b[max];
			b[max]=t1;
		}
		for(j=0;j<n;j++)
			if(j!=i)
			{
				if(fabs(a[j][i])<esp)continue;
				t1=a[j][i];
				for(k=i;k<n;k++)
					a[j][k]-=a[i][k]*t1/a[i][i];
				b[j]-=b[i]*t1/a[i][i];
			}
	}
	for(i=0;i<n;i++,putchar('\n')){
		for(j=0;j<n;j++)
			printf("%.2lf ",a[i][j]);
		printf("%.2lf",b[i]);
	}
	for(i=0;i<n;i++)
		x[i]=b[i]/a[i][i];
}

void run(){
	int i,j,k;
	memcpy(c,a,sizeof(a));
	for(i=0;i<n;i++)p[i]=i;
	gauss(a,b,n,x);
	for(i=0;i<n;i++)
		printf("x%d=%lf\n",i+1,x[i]);
	memset(l,0,sizeof(l));
	memset(u,0,sizeof(u));
	for(i=0;i<n;i++){
		for(j=i;j<n;j++)
			for(k=0,u[i][j]=c[i][j];k<i;k++)
				u[i][j]-=l[i][k]*u[k][j];
		l[i][i]=1;
		if(i!=n-1)
			for(j=i+1;j<n;j++){
				for(k=0,l[j][i]=c[j][i];k<i;k++)
					l[j][i]-=l[j][k]*u[k][i];
				l[j][i]/=u[i][i];
			}
	}
	for(i=0;i<n;i++,putchar('\n'))
		for(j=0;j<n;j++)
			printf("%d ",j==p[i]?1:0);
	printf("L\n");
	for(i=0;i<n;i++,putchar('\n'))
		for(j=0;j<n;j++)
			printf("%.2lf ",l[i][j]);
	printf("\nU\n");
	for(i=0;i<n;i++,putchar('\n'))
		for(j=0;j<n;j++)
			printf("%.2lf ",u[i][j]);
}

int main(){
	int i,j;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				scanf("%lf",&a[i][j]);
			scanf("%lf",&b[i]);
		}
		run();
	}
	return 0;
}
/*
ÊäÈë¸ñÊ½:

3
0 3 4 1
1 -1 1 2
2 1 2 3


*/