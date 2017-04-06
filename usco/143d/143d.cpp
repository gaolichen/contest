/*
ID:  mygali1
PROG: shopping
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("shopping.in");
ofstream out("shopping.out");
#endif

int ser[100][5],s,b,num[100],p[100],cost[10],tot[10],code[10];
int f[6][6][6][6][6],c[100][10],d[100][10];

int check(int i,int j,int k,int h,int l,int m){
	if(i<ser[m][0])return 0;
	if(j<ser[m][1])return 0;
	if(k<ser[m][2])return 0;
	if(h<ser[m][3])return 0;
	if(l<ser[m][4])return 0;
	return 1;
}

int calc(int i,int j,int k,int h,int l,int m){
	return f[i-ser[m][0]][j-ser[m][1]][k-ser[m][2]][h-ser[m][3]][l-ser[m][4]]+p[m];
}

void run(){
	int i,j,k,h,l,m,t;
	memset(ser,0,sizeof(ser));
	for(i=0;i<s;i++)
		for(j=0;j<num[i];j++){
			for(k=0;k<b;k++)
				if(c[i][j]==code[k])break;
			ser[i][k]=d[i][j];
		}
	memset(f,0,sizeof(f));
	for(i=0;i<=tot[0];i++)
		for(j=0;j<=tot[1];j++)
			for(k=0;k<=tot[2];k++)
				for(h=0;h<=tot[3];h++)
					for(l=0;l<=tot[4];l++){
						f[i][j][k][h][l]=i*cost[0]+j*cost[1]+
							k*cost[2]+h*cost[3]+l*cost[4]; 
						for(m=0;m<s;m++)
							if(check(i,j,k,h,l,m)){
								t=calc(i,j,k,h,l,m);
//								out<<t<<endl;
								if(f[i][j][k][h][l]>t)
									f[i][j][k][h][l]=t;
							}
					}
//	for(i=0;i<5;i++)
//		out<<tot[i]<<' ';
//	out<<endl;
	out<<f[tot[0]][tot[1]][tot[2]][tot[3]][tot[4]]<<endl;
}

int main(){
	int i,j;
	memset(num,0,sizeof(num));
	memset(tot,0,sizeof(tot));
	in>>s;
	for(i=0;i<s;i++){
		in>>num[i];
		for(j=0;j<num[i];j++)
			in>>c[i][j]>>d[i][j];
		in>>p[i];
		}
	in>>b;
	for(i=0;i<b;i++){
		in>>code[i]>>tot[i]>>cost[i];
	}
	run();
	return 0;
}