/*
ID:  mygali1
PROG: fence4
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
#include<iomanip.h>
#include<time.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 1000000000
#define N 300
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
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("fence4.in");
ofstream out("fence4.out");
#endif

typedef struct node{
	T x,y;
}point;
typedef struct node1{
	point p,q;
}line;

point v,fen[N];
line l[N];
/*
����p�������q
*/
T xmult2(point p,point q)
{
	return p.x*q.y-q.x*p.y;
}
/*
(p1-p0)���(p2-p0)
*/
T xmult3(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
/*
�ж�p1,p2,p3�Ƿ���ͬһֱ���ϣ��Ƿ���1�����򷵻�0
���ú���xmult3
*/
int online(point p1,point p2,point p3)
{
	if(ESP(xmult3(p1,p2,p3)))return 1;
	return 0;
}
/*
�жϸ�����x0�Ƿ��ڱ�����[x1,x2]��
*/
int between(double x1,double x2,double x0)
{
	if((x1-x0)*(x2-x0)<=esp)return 1;
	return 0;
}
/*
�жϵ�p�Ƿ����߶�l�ϣ������˵㡣�Ƿ���1�����򷵻�0
����online��between
*/
int betweenline(line l,point p)
{
	if(!online(l.p,l.q,p))return 0;
	if(!between(l.p.x,l.q.x,p.x)||!between(l.p.y,l.q.y,p.y))
		return 0;
	return 1;
}
/*
�ж�p1,p2�Ƿ���ֱ��l��ͬ�࣬����������ֱ��l�ϣ��Ƿ���1�����򷵻�0
���p1,p2��һ����ֱ��l�Ϸ���-1
����xmult3����
*/
int sameside(point p1,point p2,line l)
{
	if(xmult3(l.p,l.q,p1)*xmult3(l.p,l.q,p2)>esp)return 1;
	if(online(p1,l.q,l.p)||online(p2,l.p,l.q))return -1;
	return 0;
}
/*
�ж�l1��l2�Ƿ�ƽ��(�������غ�)���Ƿ���1�����򷵻�0
���l1,l2�غϷ���-1
����online
*/
int parallel(line l1,line l2)
{
	if(online(l1.p,l1.q,l2.p)&&online(l1.p,l1.q,l2.q))return -1;
	if(ESP((l1.q.y-l1.p.y)*(l2.q.x-l2.p.x)-(l1.q.x-l1.p.x)*(l2.q.y-l2.p.y)))
		return 1;
	return 0;
}
/*
�ж�ֱ��l1��l2�Ƿ�ֱ���Ƿ���1�����򷵻�0
*/
int plump(line l1,line l2)
{
	if(ESP((l1.p.x-l1.q.x)*(l2.p.x-l2.q.x)+(l1.p.y-l1.q.y)*(l2.p.y-l2.q.y)))
		return 1;
	return 0;
}
/*
�ж��߶�l1��l2�Ƿ��ཻ��������l1��l2��ͬһֱ�ߣ�������һ���˵�
������һ���߶��ϣ����Ƿ���1�����򷵻�0
����sameside
*/
int judgeinter(line l1,line l2)
{
	if(ESP(xmult3(l1.p,l1.q,l2.p))&&ESP(xmult3(l1.p,l1.q,l2.q))){
		if(betweenline(l1,l2.p)||betweenline(l1,l2.q)||betweenline(l2,l1.p)||betweenline(l2,l1.q))
			return 1; //���ֻҪ�й�������У��Ͱ����˾�
		return 0;
	}
	if(sameside(l1.p,l1.q,l2)==1)return 0;
	if(sameside(l2.p,l2.q,l1)==1)return 0;
	return 1;
}
int judgeinter2(line l1,line l2)
{
	if(ESP(xmult3(l1.p,l1.q,l2.p))&&ESP(xmult3(l1.p,l1.q,l2.q))){
//		if(betweenline(l1,l2.p)||betweenline(l1,l2.q)||betweenline(l2,l1.p)||betweenline(l2,l1.q))
//			return 1; //���ֻҪ�й�������У��Ͱ����˾�
		return 0;
	}
	if(sameside(l1.p,l1.q,l2)==1)return 0;
//	if(sameside(l2.p,l2.q,l1)==1)return 0;
	return 1;
}
/*
����ֱ��l1,l2�Ľ��㣬���Ϊp
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
��p1p2�ľ���
*/
double pointdis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int samepoint(point a,point b){
	return ESP(a.x-b.x)&&ESP(a.y-b.y);
}
int mark[N],n;
void run(){
	int i,j,k,ti;
	double s,min;
	point temp,t,tt;
	line tl,ttl;
	if(n<=3){
		out<<"NOFENCE"<<endl;
		return ;
	}
	for(i=0;i<n;i++){
		l[i].p=fen[i];
		l[i].q=fen[i+1];
	}
	for(i=0;i<n;i++)
		for(j=(i+2)%n;(j+1)%n!=i;j++)
			if(judgeinter(l[i],l[j%n])){
				out<<"NOFENCE"<<endl;
				return ;
			}
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			temp.x=(fen[i].x+fen[j].x)*0.5;
			temp.y=(fen[i].y+fen[j].y)*0.5;
			min=M;
			tl.p=v;tl.q=temp;
			for(k=0;k<n;k++)
				if(judgeinter2(l[k],tl)){
					intersect(tl,l[k],&t);
					ttl.p=v;ttl.q=t;
					if(!betweenline(ttl,temp)&&!betweenline(tl,t))continue;
					s=pointdis(t,v);
					if(s<min){
						min=s;
						ti=k;
						tt=t;
					}
				}
			if(min==M)continue;
			if(!samepoint(tt,l[ti].p)&&!samepoint(tt,l[ti].q))
				mark[ti]=1;
		}
	for(i=j=0;i<n;i++)
		if(mark[i])j++;
	out<<j<<endl;
	setprecision(0);	
	for(i=0;i<n-2;i++)
		if(mark[i])
			out<<fen[i].x<<' '<<fen[i].y<<' '<<fen[i+1].x<<' '<<fen[i+1].y<<endl;
	if(mark[n-1])
		out<<fen[0].x<<' '<<fen[0].y<<' '<<fen[n-1].x<<' '<<fen[n-1].y<<endl;
	i=n-2;
	if(mark[n-2])
		out<<fen[i].x<<' '<<fen[i].y<<' '<<fen[i+1].x<<' '<<fen[i+1].y<<endl;
}
int main(){
	int i;
	while(in>>n){
		in>>v.x>>v.y;
		for(i=0;i<n;i++)
			in>>fen[i].x>>fen[i].y;
		fen[n]=fen[0];
		run();
	}
	return 0;
}