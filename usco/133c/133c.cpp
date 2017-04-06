/*
ID:  mygali1
PROG: packrec
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("packrec.in");
ofstream out("packrec.out");
#endif

int min,count,a[4][2],dir[4],rec[1000][2],mark[10],b[4][2];
int sk[10];

inline int max(int a,int b){
	return (a>b?a:b);
}

void insert(int w,int h){
	int t;
	if(w*h>min)return ;
	if(w>h){
		t=w;w=h;h=t;
	}
	if(w*h==min){
		rec[count][0]=w;
		rec[count++][1]=h;
		return ;
	}
	if(w*h<min){
		min=w*h;
		count=0;
		rec[count][0]=w;
		rec[count++][1]=h;
		if(min==36){
			out<<sk[0]<<' '<<sk[1]<<' '<<sk[2]<<' '<<sk[3]<<endl;
		}
	}
}
void check(){
	int i,w,h;
	for(i=0;i<4;i++){
		a[i][0]=b[sk[i]][0];
		a[i][1]=b[sk[i]][1];
	}
	for(i=w=0;i<4;i++)
		w+=a[i][dir[i]];
	for(i=h=0;i<4;i++)
		if(a[i][!dir[i]]>h)
			h=a[i][!dir[i]];
	insert(w,h);
	if(w*h==36)out<<"kaka "<<1<<endl;
	for(i=h=w=0;i<3;i++){
		w+=a[i][dir[i]];
		if(a[i][!dir[i]]>h)
			h=a[i][!dir[i]];
	}
	if(a[3][dir[3]]>w)w=a[3][dir[3]];
	h+=a[3][!dir[3]];
	insert(w,h);
	if(w*h==36)out<<"kaka "<<2<<endl;
	w=a[0][dir[0]]+a[1][dir[1]];
	if(a[2][dir[2]]>w)w=a[2][dir[2]];
	w+=a[3][dir[3]];
	h=max(a[0][!dir[0]],a[1][!dir[1]]);
	h+=a[2][!dir[2]];
	h=max(h,a[3][!dir[3]]);
	insert(w,h);
	if(w*h==36)out<<"kaka "<<3<<endl;
	w=a[0][dir[0]]+a[3][dir[3]]+max(a[1][dir[1]],a[2][dir[2]]);
	h=max(a[0][!dir[0]],a[1][!dir[1]]+a[2][!dir[2]]);
	h=max(h,a[3][!dir[3]]);
	insert(w,h);
	if(w*h==36)out<<"kaka "<<4<<endl;
	w=max(a[0][dir[0]],a[1][dir[1]]);
	w+=a[2][dir[2]]+a[3][dir[3]];
	h=max(a[0][!dir[0]]+a[1][!dir[1]],a[2][!dir[2]]);
	h=max(h,a[3][!dir[3]]);
	insert(w,h);
	if(w*h==36)out<<"kaka "<<5<<endl;
	w=max(a[0][dir[0]]+a[1][dir[1]],a[2][dir[2]]+a[3][dir[3]]);
	if(a[0][!dir[0]]<a[1][!dir[1]]){
		w=max(w,a[2][dir[2]]+a[1][dir[1]]);
	}
	else if(a[0][!dir[0]]>a[1][!dir[1]])
		w=max(w,a[3][dir[3]]+a[0][dir[0]]);
	h=max(a[0][!dir[0]]+a[2][!dir[2]],a[1][!dir[1]]+a[3][!dir[3]]);
	insert(w,h);
	if(w*h==36)out<<"kaka "<<6<<endl;
}
void dfs2(int k){
	if(k==4){
		check();
		return ;
	}
	for(dir[k]=0;dir[k]<2;dir[k]++)
		dfs2(k+1);
}

void dfs(int k){
	if(k==4){
		dfs2(0);
		return ;
	}
	for(int i=0;i<4;i++)
		if(!mark[i]){
			sk[k]=i;
			mark[i]=1;
			dfs(k+1);
			mark[i]=0;
		}
}
int cmp(const void *a,const void *b){
	return ((int*)a)[0]-((int*)b)[0];
}
void run(){
	int i;
	memset(mark,0,sizeof(mark));
	memset(dir,0,sizeof(dir));
	min=M;count=0;
	dfs(0);
	qsort(rec,count,sizeof(int)*2,cmp);
	out<<min<<endl;
	out<<rec[0][0]<<' '<<rec[0][1]<<endl;
	for(i=1;i<count;i++)
		if(rec[i][0]!=rec[i-1][0])
			out<<rec[i][0]<<' '<<rec[i][1]<<endl;
}
int main(){
	int i;
	while(in>>b[0][0]){
		in>>b[0][1];
		for(i=1;i<4;i++)
			in>>b[i][0]>>b[i][1];
		run();
	}
	return 0;
}