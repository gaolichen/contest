/*
ID:  mygali1
PROG: runround
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
ifstream in("runround.in");
ofstream out("runround.out");
#endif
int num[10],temp[10],n;
char mark[10];
int check(int n){
	int i=0,j;
	memset(mark,0,sizeof(mark));
	while(n){
		temp[i++]=n%10;
		n/=10;
	}
	for(j=0;j<i;j++){
		num[i-j-1]=temp[j];
		mark[temp[j]]++;
		if(!temp[j]||mark[temp[j]]>1)break;
	}
	if(j<i)return 0;
	int len=i,t=0;
	memset(mark,0,sizeof(mark));
	j=num[0];i=0;
//	if(flag==81362)out<<len<<' '<<j<<endl;
	while(t<len){
		i=(i+j)%len;
		j=num[i];
		if(mark[j])break;
		t++;
		mark[j]=1;
	}
	if(t<len)return 0;
	if(j!=num[0])return 0;
	return 1;
}
void run(){
	int i;
	for(i=n+1;;i++)
		if(check(i))break;
	out<<i<<endl;
}
int main(){
	while(in>>n)run();
	return 0;
}