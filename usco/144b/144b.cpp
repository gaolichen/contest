/*
ID:  mygali1
PROG: ratios
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
#define MAXN 110
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("ratios.in");
ofstream out("ratios.out");
#endif

int a[3],b[3],gol[3],org[3][3];

int calc(int a[][3]){
	return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-
		a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+
		a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void run(){
	int i,j,dlt,tmp[3][3];
	dlt=calc(org);
//	out<<dlt<<endl;
	if(dlt==0){
		out<<"NONE"<<endl;
		return ;
	}
	for(i=0;i<3;i++){
		memcpy(tmp,org,sizeof(org));
		for(j=0;j<3;j++)
			tmp[i][j]=gol[j];
		a[i]=calc(tmp);
		if(a[i]>0&&dlt<0||a[i]<0&&dlt>0){
			out<<"NONE"<<endl;
			return ;
		}
	}
	for(i=0;i<3;i++){
		j=gcd(dlt,a[i]);
		if(j==0)b[i]=0;
		else
		b[i]=dlt/j;
//		out<<b[i]<<endl;
	}
	j=gcd(b[0],b[1]);
	if(j)j=b[0]*b[1]/j;
	if(j)j=j*b[2]/gcd(j,b[2]);
	else j=b[2];
	for(i=0;i<3;i++){
		a[i]=a[i]*j/dlt;
		out<<a[i]<<' ';
	}
	out<<j<<endl;
}

int main(){
	in>>gol[0]>>gol[1]>>gol[2];
	for(int i=0;i<3;i++)
		in>>org[i][0]>>org[i][1]>>org[i][2];
	run();
	return 0;
}