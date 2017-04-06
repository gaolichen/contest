/*
ID:  mygali1
PROG: frac1
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("frac1.in");
ofstream out("frac1.out");
#endif

struct node{int a,b;};
node fra[30000];
int n;
int cmp(const void *t1,const void *t2){
	return ((node*)t1)->a*((node*)t2)->b-((node*)t1)->b*((node*)t2)->a;
}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void run(){
	int i,j,count=0;
	for(i=1;i<=n;i++)
		for(j=0;j<=i;j++)
			if(gcd(i,j)==1){
				fra[count].a=j;
				fra[count++].b=i;
			}
	qsort(fra,count,sizeof(node),cmp);
	for(i=0;i<count;i++)
		out<<fra[i].a<<'/'<<fra[i].b<<endl;
}
int main(){
	while(in>>n)run();
	return 0;
}