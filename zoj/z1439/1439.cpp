#include<math.h>
#include<stdio.h>
#include<iostream.h>

double dis(double x1,double y1,double z1,double x2,double y2,double z2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main(){
	double x1,x2,x3,y1,y2,y3,z1,z2,z3;
	double a,b,c,p,s,k;
	while(cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3){
		a=dis(x1,y1,z1,x2,y2,z2);
		b=dis(x1,y1,z1,x3,y3,z3);
		c=dis(x3,y3,z3,x2,y2,z2);
		p=(a+b+c)*0.5;
		s=(p*(p-a)*(p-b)*(p-c));
		k=8*s/(a*b*c*(a+b+c));
		printf("%.3lf\n",k*k);
	}
	return 0;
}