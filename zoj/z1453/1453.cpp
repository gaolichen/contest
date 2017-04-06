#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<math.h>
#include<time.h>
#define N 500
#define INT
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

point p0,p[500];
int n,sk[500];
/*
(p1-p0)���(p2-p0)
*/
T xmult3(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
/*
��p1p2�ľ���
*/
double pointdis(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int mycmp(const void *t1,const void *t2)
{
	if(ESP(xmult3(*(point*)t1,*(point*)t2,p0))){
		if(pointdis(*(point*)t1,p0)>pointdis(*(point*)t2,p0))return 1;
		return -1;
	}
	return xmult3(*(point*)t1,*(point*)t2,p0)<esp;
}
//��͹��,��㼯p[n]��͹�����������sk[]�͹���� *count����,����mycmp�Լ�ȫ�ֱ���p0
void graham(point *p,int n,int *sk,int *count){
	int i,pop;	
	for(i=0;i<n;i++)
		if(p[i].y<p[0].y||ESP(p[i].y-p[0].y)&&p[i].x<p[0].x){
			p0=p[i];p[i]=p[0];
			p[0]=p0;
		}
	p0=p[0];
	qsort(p+1,n-1,sizeof(point),mycmp);
	for(i=0;i<2;i++)sk[i]=i;
	for(i=2,pop=1;i<n;i++){
		while(pop>0&&xmult3(p[i],p[sk[pop]],p[sk[pop-1]])>=esp)
			pop--;
		sk[++pop]=i;
	}
	*count=pop+1;
}

void run(){
	int count,i;
	double s=0;
	point temp[1000];
	if(n==1){
		printf("0.00\n");
		return;
	}
	graham(p,n,sk,&count);
	for(i=0;i<count;i++)
		temp[i]=p[sk[i]];
	temp[count]=p[sk[0]];
	for(i=0;i<count;i++)
		s+=pointdis(temp[i],temp[i+1]);
	printf("%.2lf\n",s);
}

int main(){
	int i;
	while(1){
		cin>>n;
		if(!n)break;
		for(i=0;i<n;i++)
			cin>>p[i].x>>p[i].y;
		run();
	}
	return 0;
}