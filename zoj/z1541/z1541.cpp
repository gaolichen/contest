#include<iostream.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define inf 10000000
#define esp 1e-6

int n,a[110];
double minr,maxr;
double pi=acos(-1.0);

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

double mybsearch(){
	int i;
	double tmp=0,mid;
	mid=(maxr+minr)*0.5;
	for(i=0;i<n-1;i++){
		tmp+=2*asin(a[i]*0.5/mid);
	}
	tmp=2*pi-tmp;
	tmp=2*mid*sin(tmp*0.5);
	if(fabs(tmp-a[n-1])<esp){
		return mid;
	}
	if(tmp>a[n-1]){
		maxr=mid;
		return mybsearch();
	}
	minr=mid;
	return mybsearch();
}
void run(){
	int i,j;
	qsort(a,n,sizeof(int),cmp);
	for(i=j=0;i<n-1;i++)
		j+=a[i];
	if(j<=a[n-1]){
		printf("0.00\n");
		return ;
	}
	minr=a[n-1]*0.5;maxr=inf;
	double r=mybsearch();
	double tmp,t=0,s=0;
	for(i=0;i<n-1;i++){
		tmp=2*asin(a[i]*0.5/r);
		s+=sin(tmp);
		t+=tmp;
	}
	s-=sin(t);
	s*=0.5*r*r;
	printf("%.2lf\n",s);
}

int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>a[i];
		run();
	}
	return 0;
}