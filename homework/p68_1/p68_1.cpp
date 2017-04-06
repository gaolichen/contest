#include<stdio.h>
#include<math.h>

double x[20],y[20],tar;
int n;

void run(){
	int i,j;
	double ans=0,tmp;
	for(i=0;i<n;i++,ans+=tmp)
		for(j=0,tmp=y[i];j<n;j++)
			if(j!=i)tmp*=(tar-x[j])/(x[i]-x[j]);
	printf("The answer is %.4lf\n",ans);
	for(i=0,ans=1;i<n;i++)
		ans*=(tar-x[i]);
	for(i=0,ans/=n;i<n;i++)ans/=x[0];
	printf("R%d(%.2lf) < %lf\n",n-1,tar,fabs(ans));
}
int main(){
	int i;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		scanf("%lf",&tar);
		run();
	}
	return 0;
}

/*
data
4

10 2.3026
11 2.3979
12 2.4849
13 2.5649

11.75
*/