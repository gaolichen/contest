#include<stdio.h>

typedef struct{
	double a,b;
}answer;

void f(double x,answer *y){
	y->a=x;
	y->b=1.0;
}

void euler(double b,double x,answer y,double h,void (*f)(double,answer *yy)){
	printf("y(%.1lf) = %.2lfa + %.2lfb\n",x,y.a,y.b);
	if(x+h>b)return ;
	answer yy1,yy2;
	f(x,&yy1);
	f(x+h,&yy2);
	y.a+=h*0.5*(yy1.a+yy2.a);
	y.b+=h*0.5*(yy1.b+yy2.b);
	euler(b,x+h,y,h,f);
}

int main(){
	answer ans;
	ans.a=ans.b=0;
	euler(1,0,ans,0.2,f);
	return 0;
}