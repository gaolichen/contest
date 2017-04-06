/*
ID:  mygali1
PROG: nuggets
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define MAX 2000000
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("nuggets.in");
ofstream out("nuggets.out");
#endif

//#ifdef MAX
//#   undef MAX
//#define MAX 2000000
//#endif

int a[20],n;
char mark[MAX];
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void run(){
	int i,j,min,count;
	j=a[0];
	for(i=0;i<n;i++)
		j=gcd(j,a[i]);
	if(j>1){
		out<<0<<endl;
		return;
	}
	memset(mark,0,sizeof(mark));
	mark[0]=1;
	min=a[0];
	for(i=0;i<n;i++)
		if(a[i]<min)min=a[i];
	for(i=1,count=0;i<MAX;i++){
		for(j=0;j<n&&!mark[i];j++)
			if(a[j]<=i&&mark[i-a[j]])
				mark[i]=1;
		if(mark[i])count++;
		else count=0;
		if(count==min)break;
	}
	out<<i-min<<endl;
/*	for(i=0;i<MAX;i++)
		if(mark[i])
		for(j=0;j<n;j++)
			for(k=1;k*a[j]+i<MAX;mark[k*a[j]+i]=1,k++);
	for(i=1,j=0;i<MAX;i++){
		if(mark[i])j++;
		else j=0;
		if(min==j)break;
	}
	if(i<MAX)
		out<<i-j<<endl;*/
}

int main(){
	int i;
//	out<<MAX<<endl;
	while(in>>n){
		for(i=0;i<n;i++)
			in>>a[i];
		run();
	}
	return 0;
}