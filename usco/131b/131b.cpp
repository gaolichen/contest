/*
ID:  mygali1
PROG: lamps
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
ifstream in("lamps.in");
ofstream out("lamps.out");
#endif

int light[200],mark[200],n,c,num[4],count;
char buf[20][200];
int check(){
	int i;
	memset(light,0,sizeof(light));
	i=num[0]+num[1]+num[2]+num[3];
	if(i>c||i%2!=c%2)return 0;
	if(num[0])
		for(i=1;i<=n;i++)
			light[i]=1;
	if(num[1])
		for(i=1;i<=n;i+=2)light[i]=!light[i];
	if(num[2])
		for(i=2;i<=n;i+=2)light[i]=!light[i];
	if(num[3])
		for(i=1;i<=n;i+=3)light[i]=!light[i];
	for(i=1;i<=n;i++)
		if(mark[i]&&mark[i]%2!=light[i])return 0;
	for(i=1;i<=n;i++)
		buf[count][i-1]=(light[i]?'0':'1');
	buf[count++][n]=0;
	return 1;
}

int cmp(const void *t1,const void *t2){
	return strcmp((char*)t1,(char *)t2);
}
void run(){
	count=0;
	for(num[0]=1;num[0]>=0;num[0]--)
		for(num[1]=1;num[1]>=0;num[1]--)
			for(num[2]=1;num[2]>=0;num[2]--)
				for(num[3]=1;num[3]>=0;num[3]--)
					check();
	if(!count)
		out<<"IMPOSSIBLE"<<endl;
	else{
		qsort(buf,count,sizeof(buf[0]),cmp);
		for(int i=0;i<count;i++)
			out<<buf[i]<<endl;
	}
}
int main(){
	int i;
	while(in>>n){
		in>>c;
		memset(mark,0,sizeof(mark));
		while(1){
			in>>i;
			if(i==-1)break;
			mark[i]=2;
		}
		while(1){
			in>>i;
			if(i==-1)break;
			mark[i]=1;
		}
		run();
	}
	return 0;
}