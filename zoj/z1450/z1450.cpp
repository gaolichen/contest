#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
#include<time.h>
#define N 110
//#define INT
#ifdef INT
#define ESP(x) ((x)==0)
#define T int
#define esp 0
#else
#define ESP(x) (fabs((x))<1e-10)
#define T double
#define esp (1e-10)
#endif

typedef struct node{
	T x,y;
}point;
typedef struct node1{
	point p,q;
}line;

/*
输入点p
*/
int getpoint(point *p){
	if(scanf("%lf %lf",&p->x,&p->y)==2)return 1;
	return 0;
}
/*
输出点p
*/
void printpoint(point p){
	printf("%lf %lf\n",p.x,p.y);
}
/*
向量p叉乘向量q
*/
T xmult2(point p,point q)
{
	return p.x*q.y-q.x*p.y;
}
/*
(p1-p0)叉乘(p2-p0)
*/
T xmult3(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
/*
判断p1,p2,p3是否在同一直线上，是返回1，否则返回0
调用函数xmult3
*/
int online(point p1,point p2,point p3)
{
	if(ESP(xmult3(p1,p2,p3)))return 1;
	return 0;
}
/*
判断浮点数x0是否在闭区间[x1,x2]上
*/
int between(double x1,double x2,double x0)
{
	if((x1-x0)*(x2-x0)<=esp)return 1;
	return 0;
}
/*
判断点p是否在线段l上，包括端点。是返回1，否则返回0
调用online和between
*/
int betweenline(line l,point p)
{
	if(!online(l.p,l.q,p))return 0;
	if(!between(l.p.x,l.q.x,p.x)||!between(l.p.y,l.q.y,p.y))
		return 0;
	return 1;
}
/*
判断p1,p2是否在直线l的同侧，不包括点在直线l上，是返回1，否则返回0
如果p1,p2有一点再直线l上返回-1
调用xmult3函数
*/
int sameside(point p1,point p2,line l)
{
	if(xmult3(l.p,l.q,p1)*xmult3(l.p,l.q,p2)>esp)return 1;
	if(online(p1,l.q,l.p)||online(p2,l.p,l.q))return -1;
	return 0;
}
/*
判断l1和l2是否平行(不包括重合)，是返回1，否则返回0
如果l1,l2重合返回-1
调用online
*/
int parallel(line l1,line l2)
{
	if(online(l1.p,l1.q,l2.p)&&online(l1.p,l1.q,l2.q))return -1;
	if(ESP((l1.q.y-l1.p.y)*(l2.q.x-l2.p.x)-(l1.q.x-l1.p.x)*(l2.q.y-l2.p.y)))
		return 1;
	return 0;
}
/*
判断直线l1和l2是否垂直，是返回1，否则返回0
*/
int plump(line l1,line l2)
{
	if(ESP((l1.p.x-l1.q.x)*(l2.p.x-l2.q.x)+(l1.p.y-l1.q.y)*(l2.p.y-l2.q.y)))
		return 1;
	return 0;
}
/*
判断线段l1与l2是否相交（不包括l1，l2在同一直线，单包括一个端点
在另外一条线段上），是返回1，否则返回0
调用sameside
*/
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
/*
计算直线l1,l2的交点，结果为p
*/
void intersect(line l1,line l2,point *p)
{
	T dlt;
	dlt=(l1.q.y-l1.p.y)*(l2.p.x-l2.q.x)+(l1.q.x-l1.p.x)*(l2.q.y-l2.p.y);
	p->x=(l1.p.x*l1.q.y-l1.q.x*l1.p.y)*(l2.p.x-l2.q.x)+(l1.q.x-l1.p.x)*(l2.p.x*l2.q.y-l2.q.x*l2.p.y);
	p->y=(l1.q.y-l1.p.y)*(l2.p.x*l2.q.y-l2.q.x*l2.p.y)-(l1.p.x*l1.q.y-l1.q.x*l1.p.y)*(l2.q.y-l2.p.y);
	p->x/=dlt;
	p->y/=dlt;
}
/*
点p1p2的距离
*/
double pointdis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
/*
计算直线l和点p的距离，返回结果
调用 xmult3和pointdis
*/
double li_po_dis(line l,point p)
{
	return fabs(xmult3(l.p,l.q,p))/pointdis(l.p,l.q);
}
/*
返回(p1-p0)点乘(p2-p0)
*/
T pointmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
/*
返回线段l和点p的距离，调用pointmult和pointdis，li_po_dis
*/
double duan_po_dis(line l,point p)
{
	if(pointmult(p,l.p,l.q)<-esp)return pointdis(p,l.q);
	if(pointmult(p,l.q,l.p)<-esp)return pointdis(p,l.p);
	return li_po_dis(l,p);
}
/*
判断p0是否在三角形p1p2p3内（不包括边上），是返回1，否返回0
调用xmult3
*/
int intriangle(point p1,point p2,point p3,point p0)
{
	if(xmult3(p1,p0,p2)*xmult3(p2,p0,p3)<esp)return 0;
	if(xmult3(p2,p0,p3)*xmult3(p3,p0,p1)<esp)return 0;
	return 1;
}
/*
判断p0是否在三角形p1p2p3的边上，是返回1，否返回0
调用betweenline
*/
int ontriangle(point p1,point p2,point p3,point p0)
{
	line l;
	l.p=p1,l.q=p2;
	if(betweenline(l,p0))return 1;
	l.q=p3;
	if(betweenline(l,p0))return 1;
	l.p=p2;
	if(betweenline(l,p0))return 1;
	return 0;
}
/*
判断三角形p1p2p3和线段l的关系，如果l在三角形某边上返回3
否则返回交点个数，调用online judgeinter betweenline
*/
int li_tri_ins(line l,point p1,point p2,point p3)
{
	int i=0;
	line l1;
	if(online(p1,p2,l.p)&&online(p1,p2,l.q))return 3;
	if(online(p2,p3,l.p)&&online(p2,p3,l.q))return 3;
	if(online(p3,p1,l.p)&&online(p3,p1,l.q))return 3;
	l1.p=p1;l1.q=p2;
	if(judgeinter(l,l1))i++;
	l1.q=p3;
	if(judgeinter(l,l1))i++;
	l1.p=p2;
	if(judgeinter(l,l1))i++;
	if(betweenline(l,p1))i--;
	if(betweenline(l,p2))i--;
	if(betweenline(l,p3))i--;
	return i;
}
/*
判断点p是否在多边形p[n]内，是返回1否则返回0
调用judgeinter
*/
int inpoly(point p0,point *p,int n)
{
	int i,j;
	T maxx=0,maxy=0;
	point tp;
	line tl,l[N];
	for(i=0;i<n;i++){
		if(p[i].x>maxx)maxx=p[i].x;
		if(p[i].y>maxy)maxy=p[i].y;
		l[i].p=p[i];
		l[i].q=p[i+1];
	}
	tp.x=maxx+(T)abs(rand());
	srand(time(NULL));
	tp.y=maxy+(T)abs(rand());//注意:这里数据可能超出 2^15 导致算 xmutl的时候溢出
	tl.p=p0;tl.q=tp;
	for(i=0,j=0;i<n;i++)
		if(judgeinter(tl,l[i]))
			j++;
	if(j%2)return 1;
	return 0;
}
/*
返回多边形p[n]的面积
*/
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

point p0;
int mycmp(const void *t1,const void *t2)
{
	if(ESP(xmult3(*(point*)t1,*(point*)t2,p0))){
		if(pointdis(*(point*)t1,p0)>pointdis(*(point*)t2,p0))return 1;
		return -1;
	}
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
	for(i=0;i<2;i++)sk[i]=i;
	for(i=2,pop=1;i<n;i++){
		while(pop>=0&&xmult3(p[i],p[sk[pop]],p[sk[pop-1]])>=esp)
			pop--;
		sk[++pop]=i;
	}
	*count=pop+1;
}

int n,sk[N],cnt;
double ans;
point tp[N],p[N],ansp;

int check(double r,point pp){
	int i;
	for(i=0;i<cnt;i++)
		if(pointdis(p[i],pp)-r>esp)return 0;
	return 1;
}

double kaka(point p){
	return p.x*p.x+p.y*p.y;
}
double calc(point p1,point p2,point p3,point *ret){
	double k,x1,y1,x2,y2,x3,y3,b1,b2;
	x1=p1.x;y1=p1.y;
	x2=p2.x;y2=p2.y;
	x3=p3.x;y3=p3.y;
	k=2*((x3*y2-x2*y3)+(x1*y3-x3*y1)+(x2*y1-x1*y2));
	b1=(x3*y2*x3-x2*x2*y3)+(x1*x1*y3-x3*x3*y1)+(x2*x2*y1-x1*x1*y2)-(y2-y1)*(y1-y3)*(y3-y2);
	b2=(x1-x2)*kaka(p3)+(x2-x3)*kaka(p1)+(x3-x1)*kaka(p2);
	ret->x=b1/k;
	ret->y=b2/k;
	return pointdis(*ret,p1);
}
void run(){
	int i,j,k;
	double tmp1,max;
	point tmp;
	ans=210000000;
	if(n==1){
		printf("%.2lf %.2lf 0.00\n",tp[0].x,tp[0].y);
		return ;
	}
	graham(tp,n,sk,&cnt);
	for(i=0;i<cnt;i++)
		p[i]=tp[sk[i]];
	for(i=0,max=0;i<cnt;i++)
		for(j=i+1;j<cnt;j++){
			tmp1=0.5*pointdis(p[i],p[j]);
			if(tmp1>max){
				max=tmp1;
				ansp.x=0.5*(p[i].x+p[j].x);
				ansp.y=0.5*(p[i].y+p[j].y);
			}
		}
	if(check(max,ansp)){
		if(fabs(ansp.x)<0.005)ansp.x=0;
		if(fabs(ansp.y)<0.005)ansp.y=0;
		printf("%.2lf %.2lf %.2lf\n",ansp.x,ansp.y,max);
		return ;
	}
	for(i=0;i<cnt;i++)
		for(j=i+1;j<cnt;j++)
			for(k=j+1;k<cnt;k++)
				if(!online(p[i],p[j],p[k])){
					tmp1=calc(p[i],p[j],p[k],&tmp);
					if(tmp1>=ans)continue;
					if(check(tmp1,tmp)){
						ans=tmp1;
						ansp=tmp;
					}
			}
	if(fabs(ansp.x)<0.005)ansp.x=0;
		if(fabs(ansp.y)<0.005)ansp.y=0;
	printf("%.2lf %.2lf %.2lf\n",ansp.x,ansp.y,ans);
}
int main(){
	int i;
	while(1){
		cin>>n;
		if(!n)break;
		for(i=0;i<n;i++)
			cin>>tp[i].x>>tp[i].y;
		run();
	}
	return 0;
}