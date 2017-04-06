/*
ID:  mygali1
PROG: fence6
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 100000000
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("fence6.in");
ofstream out("fence6.out");
#endif

int len[200],num[2][200],mat[200][200],map[200][200];
int point[200][2],count,n;
char ok[200],mark[200][2],done[200];


void minpath(int s){
	int i,tot=0,min,ti;
	memset(ok,0,sizeof(ok));
	ok[s]=1;
	while(++tot<count){
		min=M;
		for(i=0;i<count;i++)
			if(!ok[i]&&map[i][s]&&map[i][s]<min){
				min=map[i][s];
				ti=i;
			}
		if(min==M)break;
		ok[ti]=1;
		for(i=0;i<count;i++)
			if(!ok[i]&&map[i][ti]&&(!map[i][s]||map[i][s]>map[i][ti]+map[ti][s]))
				map[i][s]=map[i][ti]+map[ti][s];
	}
}

void mycopy(){
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<count;j++)
			map[i][j]=mat[i][j];
}
void run(){
	int i,j,min,flag,ti,t;
	memset(mark,0,sizeof(mark));
	memset(mat,0,sizeof(mat));
	memset(done,0,sizeof(done));
	point[1][0]=0;mark[1][0]=done[1]=1;
	for(i=2;i<=n;i++)
		if(map[1][i]==1){
			if(map[i][1]==1){
				point[i][0]=0;
				mark[i][0]=1;
				done[i]++;
			}
			else {
				point[i][1]=0;
				mark[i][1]=1;
				done[i]++;
			}
		}
	count=0;
	while(1){
		flag=0;
		for(i=1;i<=n;i++)
			if(done[i]==1){
				flag=1;
				done[i]++;
				break;
			}
		if(!flag)break;
		if(!mark[i][0]){
			ti=0;
			mark[i][0]=1;
			point[i][0]=++count;
			mat[point[i][1]][count]=mat[count][point[i][1]]=len[i];
		}
		else{
			ti=1;
			mark[i][1]=1;
			point[i][1]=++count;
			mat[point[i][0]][count]=mat[count][point[i][0]]=len[i];
		}
		for(j=1;j<=n;j++)
			if(done[j]!=2&&map[i][j]==ti+1){
				done[j]++;
				point[j][map[j][i]-1]=count;
				mark[j][map[j][i]-1]=1;
				if(done[j]==2){
					mat[count][point[j][!(map[j][i]-1)]]=mat[point[j][!(map[j][i]-1)]][count]=len[j];
				}
			}
	}
	min=M;count++;
	for(i=0;i<count;i++)
		for(j=i+1;j<count;j++)
			if(mat[i][j]){
				t=mat[i][j];
				mat[i][j]=mat[j][i]=0;
				mycopy();
				minpath(i);
				if(map[j][i]&&map[j][i]+t<min)min=map[j][i]+t;
				mat[i][j]=mat[j][i]=t;
			}
	out<<min<<endl;
}
int main(){
	int i,j,t,k;
	while(in>>n){
		for(i=0;i<n;i++){
			in>>t;
			in>>len[t]>>num[t][0]>>num[t][1];
			for(j=0;j<num[t][0];j++){
				in>>k;
				map[t][k]=1;
			}
			for(j=0;j<num[t][1];j++){
				in>>k;
				map[t][k]=2;
			}
		}
		run();
	}
	return 0;
}