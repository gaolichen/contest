/*

#include<iostream.h>
#include<stdlib.h>

struct point{
	int x,y;
};

point p[110],tmp[110],ans,ans1;
int h,w,n;

int _cmp(const void *a,const void *b){
	return ((point*)a)->x-((point*)b)->x;
}

inline int min(int a,int b){
	return a>b?b:a;
}
int max_retangle(int h,int w,point *p,int n,point *ans){
	int i,j,ret=0,up,low;
	p[n].x=0;p[n++].y=0;
	p[n].x=0;p[n++].y=h;
	p[n].x=w;p[n++].y=0;
	p[n].x=w;p[n++].y=h;
	qsort(p,n,sizeof(struct point),_cmp);
	for(i=0;j=i,i<n;i++){
		while(j<n&&p[j].x==p[i].x)j++;
		up=0;low=h;
		for(;j<n;j++){
			if(p[j].y<up||p[j].y>low)continue;
			if(ret<min(low-up,p[j].x-p[i].x)){
				ret=min(low-up,p[j].x-p[i].x);
				ans->x=p[i].x;
				ans->y=up;
			}
			if(p[j].y>p[i].y)low=p[j].y;
			else up=p[j].y;
		}
	}
	return ret;
}

int cmp(const void *a,const void *b){
	return ((point*)a)->y-((point*)b)->y;
}

void run(){
	int i,j;
	i=max_retangle(h,w,p,n,&ans);
	j=max_retangle(h,w,tmp,n,&ans1);
	if(j>i){
		i=j;
		ans=ans1;
	}
	qsort(p,n+4,sizeof(struct point),cmp);
	for(j=0;j<n+3;j++)
		if(i<min(p[j+1].y-p[j].y,w)){
			i=min(p[j+1].y-p[j].y,w);
			ans.x=0;ans.y=p[j].y;
		}
	cout<<ans.x<<' '<<ans.y<<' '<<i<<endl;
}
int main(){
	int i;
	while(cin>>n>>w>>h){
		for(i=0;i<n;i++){
			cin>>p[i].x>>p[i].y;
			tmp[i].x=w-p[i].x;
			tmp[i].y=p[i].y;
		}
		run();
	}
	return 0;
}*/

#include<iostream.h>
#include<stdlib.h>

struct point{
	int x,y;
};

point p[110];
int n,h,w;

int _cmp1(const void *a,const void *b){
	return ((point*)a)->x-((point*)b)->x;
}

int _cmp2(const void *a,const void *b){
	return ((point*)a)->y-((point*)b)->y;
}

inline int min(int a,int b){
	return a<b?a:b;
}

int calc(int h,point *p,int n,point *ans){
	int i,j,ret=0,up,low;
	for(i=0;j=i,i<n;i++){
		while(j<n&&p[j].x==p[i].x)j++;
		up=0;low=h;
		for(;j<n;j++){
			if(ret<min(low-up,p[j].x-p[i].x)){
				ret=min((low-up),(p[j].x-p[i].x));
				ans->x=p[i].x;
				ans->y=up;
			}
			if(p[j].y<low&&p[j].y>=p[i].y)low=p[j].y;
			else if(p[j].y>up&&p[j].y<p[i].y)up=p[j].y;
		}
	}
	return ret;
}

int max_retangle(int h,int w,point *p,int n,point *ans){
	int i,ret=0;
	point tmp;
	p[n].x=0;p[n++].y=0;
	p[n].x=0;p[n++].y=h;
	p[n].x=w;p[n++].y=0;
	p[n].x=w;p[n++].y=h;
	qsort(p,n,sizeof(struct point),_cmp2);
	for(i=0;i<n-1;i++)
		if(ret<min(w,p[i+1].y-p[i].y)){
			ret=min(w,p[i+1].y-p[i].y);
			ans->x=0;
			ans->y=p[i].y;
		}
	qsort(p,n,sizeof(struct point),_cmp1);
	i=calc(h,p,n,&tmp);
	if(i>ret){
		ret=i;
		*ans=tmp;
	}
	for(i=0;i<n;i++)
		p[i].x=w-p[i].x;
	qsort(p,n,sizeof(struct point),_cmp1);
	i=calc(h,p,n,&tmp);
	if(i>ret){
		ret=i;
		ans->y=tmp.y;
		ans->x=w-(tmp.x+ret);
	}
	return ret;
}
void run(){
	int ret;
	point ans;
	ret=max_retangle(h,w,p,n,&ans);
	cout<<ans.x<<' '<<ans.y<<' '<<ret<<endl;
}

int main(){
	int i;
	while(cin>>n>>w>>h){
		for(i=0;i<n;i++){
			cin>>p[i].x>>p[i].y;
		}
		run();
	}
	return 0;
}