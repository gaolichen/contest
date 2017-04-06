/*
ID:  mygali1
PROG: calfflac
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
ifstream in("calfflac.in");
ofstream out("calfflac.out");
#endif

char buf[21000],temp[21000];
int r[21000],max,len,count;

int check(int k,int *t){
	int i,max1,max2;
	for(i=max1=1;i+k<count&&i<=k;i++){
		if(temp[k+i]!=temp[k-i])break;
		max1+=2;
	}
	for(i=max2=0;i+k+1<count&&i<=k;i++){
		if(temp[k+i+1]!=temp[k-i])break;
		max2+=2;
	}
	if(max1>max2){
		*t=0;
		return max1;
	}
	*t=1;return max2;
}

void output(int cen,int l,int t){
	int i,st,en;
	if(t==0){
		st=r[cen-l/2];
		en=r[cen+l/2];
	}
	else {
		st=r[cen-l/2+1];
		en=r[cen+l/2];
	}
	out<<l<<endl;
	for(i=st;i<=en;i++)
		out<<buf[i];
	out<<endl;
}
void run(){
	int i,j,t,flag,type;
	for(i=j=0;i<len;i++){
		if(buf[i]>='a'&&buf[i]<='z'){
			r[j]=i;
			temp[j++]=buf[i];
		}
		else if(buf[i]>='A'&&buf[i]<='Z'){
			r[j]=i;
			temp[j++]=buf[i]-'A'+'a';
		}
	}
	count=j;max=0;
	for(i=0;i<count;i++){
		j=check(i,&t);
		if(j>max){
			max=j;flag=i;
			type=t;
		}
	}
	output(flag,max,type);
}
int main(){
	len=0;
	while(in.getline(temp,20900)){
		strcpy(buf+len,temp);
		len=len+strlen(temp)+1;
		buf[len-1]='\n';
	}
	run();
	return 0;
}