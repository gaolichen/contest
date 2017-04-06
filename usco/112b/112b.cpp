/*
ID:  mygali1
PROG: pprime
*/

#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("pprime.in");
ofstream out("pprime.out");
#endif

int a,b,p[10000],count,pp[10000];
char mark[10000+1];
void prime(){	
	memset(mark,0,sizeof(mark));
	int i,j;
	count=0;
	mark[0]=mark[1]=1;
	for(i=2;i<10000;i++)
	if(!mark[i]){
		p[count++]=i;
		for(j=i;j*i<=10000;j++)
			mark[j*i]=1;
	}
}
int cmp(const void *t1,const void *t2){
	return *(int*)t1-*(int*)t2;
}

int check(int k,int t){
	int i;
	i=k;
	if(t==0)
		i/=10;
	while(i){
		k=10*k+i%10;
		i/=10;
	}
	return k;
}
void run(){
	int i,tot=0,j,k;
	for(i=1;i<10000;i++){
		j=check(i,0);
		if(j>=a&&j<=b){
			if(j<=10000&&!mark[j])pp[tot++]=j;
			else if(j>10000){
				for(k=0;k<count;k++)
					if(j%p[k]==0)break;
				if(k==count)pp[tot++]=j;
			}
		}
		j=check(i,1);
		if(j>=a&&j<=b){
			if(j<=10000&&!mark[j])pp[tot++]=j;
			else if(j>10000){
				for(k=0;k<count;k++)
					if(j%p[k]==0)break;
				if(k==count)pp[tot++]=j;
			}
		}
	}
	qsort(pp,tot,sizeof(int),cmp);
	for(i=0;i<tot;i++){
		if(i&&pp[i]==pp[i-1])continue;
		out<<pp[i]<<endl;
	}
}
int main(){
	prime();
	while(in>>a>>b){
		run();
	}
	return 0;
}