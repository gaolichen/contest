#include<iostream.h>
#include<stdlib.h>

struct point{
	int x,y;
};

int _cmp1(const void *a,const void *b){
	return ((point*)a)->x-((point*)b)->x;
}

int _cmp2(const void *a,const void *b){
	return ((point*)a)->y-((point*)b)->y;
}

int calc(int h,point *p,int n,point *ans,int *rh,int *rw){
	int i,j,ret=0,up,low;
	for(i=0;j=i,i<n;i++){
		while(j<n&&p[j].x==p[i].x)j++;
		up=0;low=h;
		for(;j<n;j++){
			if(ret<(low-up)*(p[j].x-p[i].x)){
				ret=(low-up)*(p[j].x-p[i].x);
				ans->x=p[i].x;
				ans->y=up;
				*rh=low-up;
				*rw=p[j].x-p[i].x;
			}
			if(p[j].y<low&&p[j].y>=p[i].y)low=p[j].y;
			else if(p[j].y>up&&p[j].y<p[i].y)up=p[j].y;
		}
	}
	return ret;
}

int max_retangle(int h,int w,point *p,int n,point *ans,int *rh,int *rw){
	int i,ret=0,tw,th;
	point tmp;
	p[n].x=0;p[n++].y=0;
	p[n].x=0;p[n++].y=h;
	p[n].x=w;p[n++].y=0;
	p[n].x=w;p[n++].y=h;
	qsort(p,n,sizeof(struct point),_cmp2);
	for(i=0;i<n-1;i++)
		if(ret<w*(p[i+1].y-p[i].y)){
			*rh=p[i+1].y-p[i].y;
			*rw=w;
			ret=w*(p[i+1].y-p[i].y);
			ans->x=0;
			ans->y=p[i].y;
		}
	qsort(p,n,sizeof(struct point),_cmp1);
	i=calc(h,p,n,&tmp,&th,&tw);
	if(i>ret){
		ret=i;
		*ans=tmp;
		*rh=th;
		*rw=tw;
	}
	for(i=0;i<n;i++)
		p[i].x=w-p[i].x;
	qsort(p,n,sizeof(struct point),_cmp1);
	i=calc(h,p,n,&tmp,&th,&tw);
	if(i>ret){
		ret=i;
		*rh=th;
		*rw=tw;
		ans->y=tmp.y;
		ans->x=w-(tmp.x+tw);
	}
	return ret;
}