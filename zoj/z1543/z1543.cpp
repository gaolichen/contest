#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int w[11000];

int cmp(const void *a,const void*b){
	return -*(int*)a+*(int*)b;
}

void run(){
	int i;
	double ans;
	qsort(w,n,sizeof(int),cmp);

	ans=w[0];
	for(i=1;i<n;i++)
		ans=2*sqrt(ans*w[i]);
	printf("%.3lf\n",ans);
}
int main(){
	int i;
	while(cin>>n){
		for(i=0;i<n;i++)
			cin>>w[i];
		run();
	}
	return 0;
}