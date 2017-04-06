#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<string>
using namespace std;



double q,m,e,b,v,t;
double pi=acos(-1.0);
int cnt=0;

void run(){
	double x,y,w;
	w=q*b/m;
	y=(b*v-e)*q/(m*w*w)*(1-cos(w*t));
	x=v*t-q*q*b*(v*b-e)/(m*m*w*w)*(t-sin(w*t)/w);
	printf("Case #%d:\n",++cnt);
	printf("%.3e %.3e\n\n",x,y);
}

int main(){
	while(scanf("%lf%lf%lf%lf%lf%lf",&q,&m,&e,&b,&v,&t)==6)run();
	return 0;
}
