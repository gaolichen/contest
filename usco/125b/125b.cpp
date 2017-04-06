/*
ID:  mygali1
PROG: fact4
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("fact4.in");
ofstream out("fact4.out");
#endif

int nozero(int n){
	if(n==0)return 1;
	int last=1,i;
	if(n>=10)last=6;
	for(i=n%10;i>=1;i--)
		if(i!=5)last*=i;
	i=(n/5)%4;
	while(i--)last*=8;
	last*=nozero(n/5);
	return last%10;
}
int main(){
	int n;
	while(in>>n)
		out<<nozero(n)<<endl;
	return 0;
}