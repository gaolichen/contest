#define for if(0);else for
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<sstream>
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

//判断p1,p2,p3是否在同一直线上，是返回1，否则返回0
//调用函数xmult3

int online(point p1,point p2,point p3)
{
	if(ESP(xmult3(p1,p2,p3)))return 1;
	return 0;
}

//判断p1,p2是否在直线l的同侧，不包括点在直线l上，是返回1，否则返回0
//如果p1,p2有一点再直线l上返回-1
//调用xmult3函数

int sameside(point p1,point p2,line l)
{
	if(xmult3(l.p,l.q,p1)*xmult3(l.p,l.q,p2)>esp)return 1;
	if(online(p1,l.q,l.p)||online(p2,l.p,l.q))return -1;
	return 0;
}

//判断线段l1与l2是否相交（不包括l1，l2在同一直线，单包括一个端点
//在另外一条线段上），是返回1，否则返回0
//调用sameside

int judgeinter(line l1,line l2)
{
	if(ESP(xmult3(l1.p,l1.q,l2.p))&&ESP(xmult3(l1.p,l1.q,l2.q))){
//		if(betweenline(l1,l2.p)||betweenline(l1,l2.q)||betweenline(l2,l1.p)||betweenline(l2,l1.q))
//			return 1; //如果只要有公共点就行，就包含此句
		return 0;
	}
	if(sameside(l1.p,l1.q,l2)==1)return 0;
	if(sameside(l2.p,l2.q,l1)==1)return 0;
	return 1;
}

double area(point *p,int n)
{
	int i;
	double s=0;
	p[n]=p[0];
	for(i=0;i<n;i++)
		s+=(p[i].x*p[i+1].y-p[i].y*p[i+1].x);
	s*=0.5;
	if(s>=0)return s;
	return -s;
}

point p[2100];
int n;

void run(){
	if(n<3){
		puts("Impossible");
		return ;
	}
	for(int i=n;i<n+n;i++)p[i]=p[i-n];
	for(int i=0;i<n;i++){
		line l;
		l.p=p[i];l.q=p[i+1];
		for(int j=i+2;j<i+n-1;j++){
			line tmp;
			tmp.p=p[j];tmp.q=p[j+1];
			if(judgeinter(l,tmp)){
				puts("Impossible");
				return ;
			}
		}
	}
	printf("%.2lf\n",area(p,n));
}
int main(){
	int cnt=0;
	while(cin>>n){
		if(!n)break;
		if(cnt)putchar('\n');
		for(int i=0;i<n;i++){
			cin>>p[i].x>>p[i].y;
		}
		printf("Figure %d: ",++cnt);
		run();
	}
	return 0;
}