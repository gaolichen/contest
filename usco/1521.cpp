/*
ID:  mygali1
PROG: fc
*/
#define for if(0);else for
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<time.h>
#include<fstream>
using namespace std;
#define N 110
//#define INT
#ifdef INT
#define ESP(x) ((x)==0)
#define T int
#define esp 0
#else
#define ESP(x) (fabs((x))<1e-8)
#define T double
#define esp (1e-10)
#endif

typedef struct node{
	T x,y;
}point;
typedef struct node1{
	point p,q;
}line;

//(p1-p0)叉乘(p2-p0)

T xmult3(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

//点p1p2的距离

double pointdis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

point p0;
int mycmp(const void *t1,const void *t2)
{
//	if(ESP(xmult3(*(point*)t1,*(point*)t2,p0))){
//		if(pointdis(*(point*)t1,p0)>pointdis(*(point*)t2,p0))return 1;
//		return -1;
//	}
	return xmult3(*(point*)t1,*(point*)t2,p0)<esp;
}
//求凸包,求点集p[n]的凸包，结果放再sk[]里，凸包有 *count个点,调用mycmp以及全局变量p0
void graham(point *p,int n,int *sk,int *count){
	int i,pop;	
	for(i=0;i<n;i++)
		if(p[i].y<p[0].y||ESP(p[i].y-p[0].y)&&p[i].x<p[0].x){
			p0=p[i];p[i]=p[0];
			p[0]=p0;
		}
	qsort(p+1,n-1,sizeof(point),mycmp);
	qsort(p+1,n-1,sizeof(point),mycmp);
	for(int k=0;k<n;k++)
	cout<<p[k].x+800<<' '<<p[k].y+1000<<' '<<xmult3(p[k],p[(k+1)%n],p0)<<endl;
	for(i=0;i<2;i++)sk[i]=i;
	for(i=2,pop=1;i<n;i++){
		while(pop>0&&xmult3(p[i],p[sk[pop]],p[sk[pop-1]])>=esp)
			pop--;
		sk[++pop]=i;
	}
	*count=pop+1;
}

point p[11000];
int sk[11000];
int n;
void run(){
	int cnt;cout<<endl;
	graham(p,n,sk,&cnt);
	sk[cnt]=sk[0];
	
//	for(int i=0;i<n;i++)
//	cout<<p[i].x+800<<' '<<p[i].y+1000<<endl;
	cout<<endl;
	for(int i=0;i<cnt;i++)
	cout<<p[sk[i]].x+800<<' '<<p[sk[i]].y+1000<<endl;
	double ret=0;
	for(int i=0;i<cnt;i++)ret+=pointdis(p[sk[i]],p[sk[i+1]]);
//	FILE *fp=fopen("fc.out","w");
//	fprintf(fp,"%.2lf\n",ret);
	cout<<ret<<endl;
}

int main(){
//	ifstream cin("fc.in");
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
		run();
	}
	return 0;
}