/*
ID:  mygali1
PROG: spin
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
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("spin.in");
ofstream out("spin.out");
#endif

int num[6],s[6][6],e[6][6],v[5];

int check(){
	int i,j,k;
	for(i=0;i<360;i++){
		for(j=0;j<5;j++){
			for(k=0;k<num[j];k++){
				if(s[j][k]<e[j][k]&&s[j][k]<=i&&e[j][k]>=i)
					break;
				if(s[j][k]>e[j][k]&&(i>=s[j][k]||i<=e[j][k]))
					break;
			}
			if(k==num[j])break;
		}
		if(j==5)return 1;
	}
	return 0;
}
void run(){
	int i,j,k;
	
	for(i=0;i<360;i++){
		if(check())break;
		for(j=0;j<5;j++)
			for(k=0;k<num[j];k++){
				s[j][k]=(s[j][k]+v[j])%360;
				e[j][k]=(e[j][k]+v[j])%360;
			}
//			cout<<i<<endl;
	}
	if(i==360)out<<"none"<<endl;
	else out<<i<<endl;                                                                                                                                                                                                                                                                                  
}
int main(){
	int i,j;
	for(i=0;i<5;i++){
		in>>v[i]>>num[i];
		for(j=0;j<num[i];j++){
			in>>s[i][j]>>e[i][j];
			e[i][j]=(s[i][j]+e[i][j])%360;
		}
	}
	run();
	return 0;
}