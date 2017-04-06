/*
ID:  mygali1
PROG: dualpal
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("dualpal.in");
ofstream out("dualpal.out");
#endif

int n,s;
int pal(int base,int n){
	int i,j,temp[40];
	i=0;
	while(n){
		temp[i++]=n%base;
		n/=base;
	}
	for(j=0;2*j<i;j++)
		if(temp[j]!=temp[i-j-1])return 0;
	return 1;
}
int check(int k){
	int i,j;
	for(i=2,j=0;i<=10;i++)
		if(pal(i,k))j++;
	if(j<2)return 0;
	out<<k<<endl;
	return 1;
}
void run(){
	int i,j;
	for(i=s+1,j=0;j<n;i++)
		if(check(i))j++;
}
int main(){
	while(in>>n>>s)run();
	return 0;
}
