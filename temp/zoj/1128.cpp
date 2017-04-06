#include<stdio.h>
#include<stdlib.h>
double ex[200],ey[200],sx[200],sy[200];
double x[300],y[300];
int n;
int cmp(const void*t1,const void *t2)
{
	if(*(double*)t1>*(double *)t2)
		return 1;
	return -1;
}
int in(double x1,double x2,double y1,double y2)
{
	int i;
	for(i=0;i<n;i++)
		if(x1-sx[i]>-1e-6&&ex[i]-x2>-1e-6&&y1-sy[i]>-1e-6&&ey[i]-y2>-1e-6)
			return 1;
	return 0;
}
void run()
{
	int i,j=0;
	double s=0;
	for(i=0;i<n;i++)
	{
		x[j]=sx[i];
		y[j++]=sy[i];
		x[j]=ex[i];
		y[j++]=ey[i];
	}
	qsort(x,j,sizeof(double),cmp);
	qsort(y,j,sizeof(double),cmp);
	for(i=1;i<n+n;i++)
		if(x[i]-x[i-1]>1e-6)
		for(j=1;j<n+n;j++)
			if(y[j]-y[j-1]>1e-6&&in(x[i-1],x[i],y[j-1],y[j]))
		s+=(x[i]-x[i-1])*(y[j]-y[j-1]);
	printf("Total explored area: %.2lf\n\n",s);
}
void main()
{
	int i,count=0;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&sx[i],&sy[i],&ex[i],&ey[i]);
		printf("Test case #%d\n",++count);
		run();
		scanf("%d",&n);
	}
}

/*
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
struct rectangle{
	int c;
	double x1,y1,x2,y2;
};

rectangle rec[110];
int n;
int rectintersect(rectangle a,rectangle b,rectangle *cut){
	if(a.x1>=b.x2||a.x2<=b.x1)return 0;
	if(a.y2<=b.y1||a.y1>=b.y2)return 0;
	if(a.x1>=b.x1&&a.x2<=b.x2&&a.y1>=b.y1&&a.y2<=b.y2)
		return -1;
	int ret=0;
	if(a.x1<b.x1){
		cut[ret]=a;
		cut[ret++].x2=b.x1;
		a.x1=b.x1;
	}
	if(a.x2>b.x2){
		cut[ret]=a;
		cut[ret++].x1=b.x2;
		a.x2=b.x2;
	}
	if(a.y1<b.y1){
		cut[ret]=a;
		cut[ret++].y2=a.y1=b.y1;
	}
	if(a.y2>b.y2){
		cut[ret]=a;
		cut[ret++].y1=a.y2=b.y2;
	}
	return ret;
}
//求长方形的交
void cutrectangle(rectangle *init,int n,rectangle *end,int *nn){
	int i,j,rr=0,nr,k;
	rectangle cut[4];
	for(i=0;i<n;i++){
		end[rr]=init[i];
		nr=rr++;
		for(j=0;j<nr;j++){
			k=rectintersect(end[j],end[nr],cut);
			if(k==0)continue;
			if(k==-1){
				memmove(end+j,end+j+1,sizeof(rectangle)*(rr-j-1));
				j--;
				rr--;
				nr--;
				continue;
			}
			end[j]=cut[--k];
			while(k>0)end[rr++]=cut[--k];
		}
	}
	*nn=rr;
}

rectangle ans[5100];
void run(){
	int i,nn;
	double res=0;
	cutrectangle(rec,n,ans,&nn);
	for(i=0;i<nn;i++)
		res+=fabs(ans[i].x1-ans[i].x2)*fabs(ans[i].y1-ans[i].y2);
	printf("Total explored area: %.2lf\n\n",res);
}

int main(){
	int cnt=0,i;
	while(1){
		cin>>n;
		if(!n)break;
		for(i=0;i<n;i++){
			cin>>rec[i].x1>>rec[i].y1>>rec[i].x2>>rec[i].y2;
		}
		printf("Test case #%d\n",++cnt);
		run();
	}
	return 0;
}
*/