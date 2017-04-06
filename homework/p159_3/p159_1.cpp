#include<stdio.h>
#include<math.h>
#define esp 1e-7

double diedai(double x,double (*f)(double)){
	double ret;
	ret=f(x);
	if(fabs(ret-x)<esp)return ret;
	return diedai(ret,f);
}

double f(double x){
	return 1.0+1/(x*x);
}

int main(){
	printf("answer = %.6lf\n",diedai(1.5,f));
	return 0;
}