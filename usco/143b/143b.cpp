/*
ID:  mygali1
PROG: prefix
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 3456793
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("prefix.in");
ofstream out("prefix.out");
#endif

int f[210000],len,count;
char cod[210000],c[300][20];
int cmp(const void *a,const void *b){
	return strcmp((char*)a,(char*)b);
}
void run(){
	int i,j,best=0;
	char *find,ch,temp[20];
	memset(f,0,sizeof(f));
	for(i=0;i<len;i++){
		ch=cod[i+1];
		cod[i+1]='\0';
		for(j=0;i-j>=0&&j<10;j++){
			strcpy(temp,cod+i-j);
			find=(char*)bsearch(temp,c,count,sizeof(c[0]),cmp);
			if(find!=NULL){
				if(f[i+1]<f[i-j]+j+1)
					f[i+1]=f[i-j]+j+1;
			}
		}
		if(f[i+1]==i+1&&f[i+1]>best)best=f[i+1];
		cod[i+1]=ch;
	}
	out<<best<<endl;
}

int main(){
	char buf[100];
	count=0;
	while(in>>c[count]){
		if(c[count][0]=='.')break;
		count++;
	}
	qsort(c,count,sizeof(c[0]),cmp);
	len=0;
	while(in>>buf){
		strcpy(cod+len,buf);
		len+=strlen(buf);
	}
//	out<<count<<endl;
//	for(int i=0;i<count;i++)
//		out<<c[i]<<' ';
//	out<<endl;
//	out<<buf<<endl;
	run();
	return 0;
}