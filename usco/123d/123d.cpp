/*
ID:  mygali1
PROG: fracdec
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("fracdec.in");
ofstream out("fracdec.out");
#endif

char buf[110001];
int a,b,mark[110001];
void run(){
	int i,j;
	i=a/b;
	a%=b;
	sprintf(buf,"%d",i);
	i=strlen(buf);
	buf[i++]='.';
	memset(mark,0,sizeof(mark));
	mark[a]=i-1;
	while(1){
		a*=10;
		buf[i++]=a/b+'0';
		a%=b;
		if(a==0||mark[a])break;
		mark[a]=i-1;
	}
	if(a==0){
		buf[i]='\0';
		for(j=0;j<i;j++){
			if(j&&j%76==0)out<<endl;
			out<<buf[j];
		}
		out<<endl;
	}
	else{
		buf[i++]=')';
		for(j=0;j<=mark[a];j++){
			if(j&&j%76==0)out<<endl;
			out<<buf[j];
		}
		out<<'(';
		for(;j<i;j++){
			if((j+1)%76==0)out<<endl;
			out<<buf[j];
		}
		out<<endl;

	}
}
int main(){
	while(in>>a>>b)run();
	return 0;
}