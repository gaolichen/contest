#include<stdio.h>
#include<math.h>

double trapezoid(int n,double a,double b,double (*f)(double)){
	double h=(b-a)/n,ans=0;
	int i;
	for(i=1;i<=n;i++)
		ans+=h*0.5*(f(a+(i-1)*h)+f(a+i*h));
	return ans;
}

double xinpu(int n,double a,double b,double (*f)(double)){
	double h=(b-a)/n,ans=h/6.0*(f(b)-f(a));;
	int i;
	for(i=0;i<n;i++)
		ans+=h/6.0*(4*f(a+(i+0.5)*h)+2*f(a+i*h));
	return ans;
}

double f(double x){
	return exp(x);
}

int main(){
	printf("复合梯形公式: answer=%.7lf\n",trapezoid(400,0,1,f));
	printf("复合辛普生公式: answer=%.7lf\n",xinpu(5,0,1,f));
	return 0;
}