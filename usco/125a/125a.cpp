/*
ID:  mygali1
PROG: palsquare
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
ifstream in("palsquare.in");
ofstream out("palsquare.out");
#endif
int b;
int check(int k){
	int i=0,temp[30];
	while(k){
		temp[i++]=k%b;
		k/=b;
	}
	int j=i;
	for(i=0;2*i<=j;i++)
		if(temp[i]!=temp[j-i-1])return 0;
	return 1;
}
void output(int k){
	int i=0,temp[30];
	while(k){
		temp[i++]=k%b;
		k/=b;
	}
	while(--i>=0){
		if(temp[i]<10)
		out<<temp[i];
		else out<<char(temp[i]-10+'A');
	}
}
void run(){
	int i;
	for(i=1;i<=300;i++)
		if(check(i*i)){
			output(i);
			out<<' ';
			output(i*i);
			out<<endl;
		}
}
int main(){
	while(in>>b)run();
	return 0;
}