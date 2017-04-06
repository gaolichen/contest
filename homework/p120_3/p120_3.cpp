#include<stdio.h>

double a,b;

double f(double x){
	return x/(4+x*x);
}

void trapezoid(int n,double (*f)(double)){
	double h=(b-a)/n,ans=0;
	int i;
	for(i=1;i<=n;i++)
		ans+=h*0.5*(f(a+(i-1)*h)+f(a+i*h));
	printf("复合梯形公式: answer=%.7lf\n",ans);
}

void xinpu(int n,double (*f)(double)){
	double h=(b-a)/n,ans=h/6.0*(f(b)-f(a));;
	int i;
	for(i=0;i<n;i++)
		ans+=h/6.0*(4*f(a+(i+0.5)*h)+2*f(a+i*h));
	printf("复合辛普生公式: answer=%.7lf\n",ans);
}

int main(){
	a=3.0;b=6.0;
	trapezoid(8,f);
	xinpu(4,f);
	return 0;
}