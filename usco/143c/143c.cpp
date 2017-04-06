/*
ID:  mygali1
PROG: cowcycle
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("cowcycle.in");
ofstream out("cowcycle.out");
#endif

double best,rot[100],m,x[100];
int f,r,f1,f2,r2,r1,sk[100],sk1[100],rec1[100],rec2[100];

int cmp(const void *a ,const void * b){
	if(*(double*)a-*(double*)b>0)return 1;
	return -1;
}

void check(){
	int i,j,count=0;
	double sum=0;
	if(sk[f-1]*sk1[r-1]<3*sk[0]*sk1[0])
		return ;
	for(i=0;i<f;i++)
		for(j=0;j<r;j++)
			rot[count++]=(double)sk[i]/sk1[j];
	qsort(rot,count,sizeof(double),cmp);
	for(i=1;i<count;i++){
		x[i-1]=rot[i]-rot[i-1];
//		out<<x[i-1]<<' ';
	}
//	out<<endl;
	m=(rot[count-1]-rot[0])/(count-1);
	for(i=0;i<count-1;i++)
		sum+=x[i]*x[i];
	if(sum/(count-1)-m*m<best-(1e-10)){
		best=sum/(count-1)-m*m;
		for(i=0;i<f;i++)
			rec1[i]=sk[i];
		for(i=0;i<r;i++)
			rec2[i]=sk1[i];
	}
//	out<<best<<endl;
}
void dfs1(int k,int s){
	if(k==r){
		check();
		return ;
	}
	if(s>r2)return ;
	int i;
	for(i=s;i<=r2;i++){
		sk1[k]=i;
		if(r-k-1>r2-i)break;
		if(k==0){
			if(sk[f-1]*r2<sk1[0]*3*sk[0])
				break;
		}
		dfs1(k+1,i+1);
	}
}
void dfs(int k,int s){
	if(k==f){
		dfs1(0,r1);
		return ;
	}
	if(s>f2)return ;
	int i;
	for(i=s;i<=f2;i++){
		sk[k]=i;
		if((f-k-1)>f2-i)break;
		dfs(k+1,i+1);
	}
}
void run(){
	if(f==r&&r==1){
		out<<f1<<endl<<r1<<endl;
		return ;
	}
	best=M;
	dfs(0,f1);
	int i;
//	out<<best<<endl;
	for(i=0;i<f;i++){
		if(i)out<<' ';
		out<<rec1[i];
	}
	for(out<<endl,i=0;i<r;i++){
		if(i)out<<' ';
		out<<rec2[i];
	}
	out<<endl;
}
int main(){
	in>>f>>r;
	in>>f1>>f2>>r1>>r2;
	run();
	return 0;
}