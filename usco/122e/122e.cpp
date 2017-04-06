/*
ID:  mygali1
PROG: milk2
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("milk2.in");
ofstream out("milk2.out");
#endif

struct node{
	int s,e;
};
node seg[6000];
char mark[6000];
int n;
int cmp(const void *t1,const void *t2){
		return ((node*)t1)->s-((node*)t2)->s;
}
void run(){
	int i,j,max1=0,max2=0,start,end;
	qsort(seg,n,sizeof(node),cmp);
	memset(mark,0,sizeof(mark));
	start=end=seg[0].s;
	for(i=0;i<n;i++)
		if(!mark[i]){
			if(seg[i].s-end>max2)max2=seg[i].s-end;
			start=seg[i].s;
			end=seg[i].e;
			for(j=i+1;j<n;j++)
				if(seg[j].s<=end){
					mark[j]=1;
					if(seg[j].e>end)end=seg[j].e;
				}
			if(end-start>max1)max1=end-start;
		}
	out<<max1<<' '<<max2<<endl;
}
int main(){
	int i;
	while(in>>n){
		for(i=0;i<n;i++)
			in>>seg[i].s>>seg[i].e;
		run();
	}
	return 0;
}