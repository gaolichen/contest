/*
ID:  mygali1
PROG: clocks
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
ifstream in("clocks.in");
ofstream out("clocks.out");
#endif
int a[10];
void run(){
	int i,j,count=1000,sk[10],num[10];
	for(i=0;i<9;i++)
		a[i]=(a[i]/3)%4;
	for(num[9]=0;num[9]<4;num[9]++)
		for(num[8]=0;num[8]<4;num[8]++)
			for(num[7]=0;num[7]<4;num[7]++){
				num[5]=(40-(a[7]+num[7]+num[8]+num[9]))%4;
				num[4]=(40-(a[6]+num[7]+num[8]))%4;
				num[6]=(40-(a[8]+num[8]+num[9]))%4;
				num[3]=(40-(a[5]+num[5]+num[6]+num[9]))%4;
				num[1]=(40-(a[4]+num[3]+num[5]+num[7]+num[9]))%4;
				if((num[1]+num[4]+num[5]+num[7]+a[3])%4)continue;
				num[2]=(40-(a[2]+num[3]+num[6]))%4;
				if((a[1]+num[1]+num[2]+num[3]+num[5])%4)continue;
				if((a[0]+num[1]+num[2]+num[4])%4)continue;
				for(i=1,j=0;i<=9;i++)
					j+=num[i];
				if(j<count){
					count=j;
					memcpy(sk,num,sizeof(num));
				}
			}
	count=0;
	for(i=1;i<=9;i++)
		for(j=0;j<sk[i];j++){
			if(count++)out<<' ';
			out<<i;
		}
	out<<endl;
}
int main(){
	int i;
	while(in>>a[0]){
		for(i=1;i<9;i++)
			in>>a[i];
		run();
	}
	return 0;
}
