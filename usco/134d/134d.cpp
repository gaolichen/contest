/*
ID:  mygali1
PROG: transform
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
//#define open1 open
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("transform.in");
ofstream out("transform.out");
#endif

char bef[20][20],aft[20][20];
char sk[10][20][20],rec[10][100];
int n;
int close1,open1,next1[100],op1[100],sp1[100];

int mycmp(char a[][20],char b[][20]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=b[i][j])return 1;
	return 0;
}

void mycpy(char a[][20],char b[][20]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=b[i][j];
}
void change(char a[][20],int p,char b[][20]){
	int i,j;
	char temp[20][20];
	if(p==4){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][n-j-1]=a[i][j];
		return ;
	}
	if(p==1){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][j]=a[n-1-j][i];
		return;
	}
	if(p<4){
		mycpy(temp,a);
		for(i=0;i<p;i++){
			change(temp,1,b);
			mycpy(temp,b);
		}
		return;
	}
	change(a,4,b);
	mycpy(temp,b);
	change(temp,p-4,b);
}

int check(int k,int p){
	int i;
	char b[20][20];
	change(sk[k],p,b);
	for(i=1;i<=close1;i++)
		if(mycmp(b,sk[i])==0)return 0;
	return 1;
}
void run(){
	int i,step=0,count,t,j;
//	if(mycmp(bef,aft)==0){
//		out<<6<<endl;
//		return;
//	}
	open1=close1=0;
	mycpy(sk[0],bef);
	next1[0]=-1;op1[0]=-1;
	sp1[0]=0;
	while(open1<=close1){
		if(step&&sp1[open1]==step)break;
		for(i=1;i<=7;i++)
			if(check(open1,i)){
//				out<<open1<<endl;
				close1++;
				change(sk[open1],i,sk[close1]);
				next1[close1]=open1;
				sp1[close1]=sp1[open1]+1;
				op1[close1]=i;
				if(mycmp(sk[close1],aft)==0){
					if(!step)step=sp1[close1];
				}
			}
		open1++;
	}
	if(!step){
		out<<7<<endl;
		return;
	}
	
	count=0;
	for(i=close1;i>0;i--){
		if(sp1[close1]<step)break;
		if(mycmp(sk[i],aft)==0){
			t=i;
			for(j=0;;j++){
				rec[count][step-1-j]=op1[t]+'0';
				if(rec[count][step-1-j]>'5')
					rec[count][step-1-j]='5';
				t=next1[t];
				if(!t)break;
			}
			rec[count++][step]='\0';
		}
	}
	j=0;
	for(i=0;i<count;i++)
		if(strcmp(rec[i],rec[j])<0)j=i;
	out<<rec[j]<<endl;
}
int main(){
	int i;
	while(in>>n){
		
		for(i=0;i<n;i++)
			in>>bef[i];
		for(i=0;i<n;i++)
			in>>aft[i];
		run();
	}
	return 0;
}