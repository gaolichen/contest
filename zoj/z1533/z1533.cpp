#include<iosteam.h>
#include<stdio.h>

double h,b,m;

void calc(double a,double b,double c){
	double dlt;
	dlt=b*b-4*a*c;
	if(dlt<0){
		cout<<-1<<endl;
		return;
	}
	int flag=0;
	double x[2];
	x[0]=(-b+
}
void run(){
	if(b<h||m<h){
		cout<<-1<<endl;
		return;
	}
	double l,c;
	l=2*sqrt(m*m-h*h)/h;
	c=acos(h/b);
	if(c>pi/4){
		cout<<-1<<endl;
		return;
	}
	c=tan(2*c);
	calc(c,l*c,l-c);
}

int main(){
	while(cin>>h>>b>>m)run();
	return 0;
}