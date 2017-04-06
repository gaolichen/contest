#include<stdio.h>
#include<math.h>

double f(double x,double y){
	return x+y;
}

void runge_kutta(int n,double x,double y,double h,double (*f)(double,double)){
	double k1,k2,k3,k4;
	printf("y(%.1lf) = %.2lf\n",x,y);
	if(n==0)return ;
	k1=f(x,y);
	k2=f(x+h*0.5,y+h*0.5*k1);
	k3=f(x+h*0.5,y+h*0.5*k2);
	k4=f(x+h,y+h*k3);
	y+=h/6.0*(k1+2*k2+2*k2+k4);
	runge_kutta(n-1,x+h,y,h,f);
}
int main(){
	runge_kutta(20,0,-1.0,0.1,f);
	return 0;
}