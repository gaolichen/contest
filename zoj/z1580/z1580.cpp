#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define esp 1e-8
#define equel(a,b) (fabs((a)-(b))<esp)

struct point{
	double x,y;
};
point p[1100];
int ret,n;

int cmp(const void *a,const void *b){
		if(((point*)a)->x>((point*)b)->x)
			return 1;
		return -1;
}

int mybsear(int a,int b,double x){
	if(a+1==b)return a;
	int mid=(a+b)/2;
	if(equel(p[mid].x,x)||p[mid].x>x){
		return mybsear(a,mid,x);
	}
	else return mybsear(mid,b,x);
}

int check(int a,int b,int c){
	return equel((p[a].x-p[c].x)*(p[b].x-p[c].x)+(p[a].y-p[c].y)*(p[b].y-p[c].y),0);
}

double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void calc(int a,int b){
	point c;
	double r,minx,maxx;
	int i,j;
	c.x=0.5*(p[a].x+p[b].x);
	c.y=0.5*(p[a].y+p[b].y);
	r=dis(c,p[a]);
	minx=c.x-r;
	maxx=c.x+r+esp;
	i=mybsear(0,n,minx);
	j=mybsear(0,n,maxx);
	for(;i<j;i++)
		if(i!=a&&i!=b&&check(a,b,i))ret++;
//	ret++;
}

void run(){
	int i,j;
	qsort(p,n,sizeof(double)*2,cmp);
	for(i=ret=0;i<n;i++)
		for(j=i+1;j<n;j++)
			calc(i,j);
//	cout<<ret<<endl;
	printf("%d\n",ret);
}

int main(){
	int i;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		run();
	}
	return 0;
}