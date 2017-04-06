#include<stdio.h>
#include<math.h>

int n;
double x[20],y[20],tar,dy[20];

void run1(){
	int i,j;
	double ans=0,t,tmp;
	for(i=1;i<n;i++){
		for(j=n-1;j>=i;j--)
			dy[j]-=dy[j-1];
	}
	t=(tar-x[0])/(x[1]-x[0]);
	n--;tmp=1;
	for(i=0;i<=n;i++){
		if(i)tmp/=i;
		ans+=dy[i]*tmp;
		tmp*=(t-i);
	}
	printf("The answer is %.4lf\n",ans);
	ans=tmp/(n+1);
	for(i=0;i<n+1;i++)
		ans*=(x[1]-x[0]);
	ans*=exp(x[n]);
	printf("R%d(%.2lf) < %lf\n",n,tar,fabs(ans));
	n++;
}

void run2(){
	int i,j;
	double ans=0,tmp;
	for(i=1;i<n;i++){
		for(j=n-1;j>=i;j--)
			dy[j]=(dy[j]-dy[j-1])/(x[j]-x[j-i]);
	}
	for(i=0;i<n;i++){
		for(j=0,tmp=dy[i];j<i;j++)
			tmp*=(tar-x[j]);
		ans+=tmp;
	}
	printf("The answer is %.4lf\n",ans);
}
int main(){
	int i;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++){
			scanf("%lf %lf",&x[i],&y[i]);
			dy[i]=y[i];
		}
		scanf("%lf",&tar);
//		run1();
		run2();
	}
	return 0;
}