#include<stdio.h>
#include<math.h>
#define esp 1e-5

double f1(double x){
	return (x*x+10*cos(x))/(2*x-10*sin(x));
}

double f2(double x){
	return (1+atan(x)-x)/(1./(1+x*x)-1.0);
}

double netow(double x,double (*f)(double)){
	return fabs(f(x))<esp?x:netow(x-f(x),f);
}

int main(){
	printf("(1) answer = %.5lf\n",netow(1.0,f1));
	printf("(2) answer = %.5lf\n",netow(1,f2));
	return 0;
}