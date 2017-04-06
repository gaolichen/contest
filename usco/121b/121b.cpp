/*
ID:  mygali1
PROG: castle
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
ifstream in("castle.in");
ofstream out("castle.out");
#endif

int p[4]={1,8,2,4};
int my[4]={-1,0,0,1};
int mx[4]={0,1,-1,0};
char dic[4]={'W','S','N','E'};
int mark[55][55],count,h,w,size,s[50*50+100];
char map[55][55][4];
int check(int x,int y,int k){
	if(x+mx[k]<0||x+mx[k]>=h||y+my[k]<0||y+my[k]>=w)return 0;
	if(mark[x+mx[k]][y+my[k]])return 0;
	return 1;
}
void dfs(int x,int y){
	int i;
	for(i=0;i<4;i++)
		if(!map[x][y][i]&&check(x,y,i)){
			size++;
			mark[x+mx[i]][y+my[i]]=count;
			dfs(x+mx[i],y+my[i]);
		}
}

int calc(int x,int y,int k){
	int x1,y1;
	x1=x+mx[k];y1=y+my[k];
	if(x1<0||x1>=h||y1<0||y1>=w)return 0;
	if(mark[x][y]==mark[x1][y1])return s[mark[x][y]];
	else return s[mark[x][y]]+s[mark[x1][y1]];
}
void run(){
	memset(mark,0,sizeof(mark));
	int i,j,max=0,ti,tj,tk,k;
	count=0;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(!mark[i][j]){
				size=1;
				mark[i][j]=++count;
				dfs(i,j);
				s[count]=size;
				if(size>max)max=size;
			}
	out<<count<<endl;
	out<<max<<endl;
	max=0;
	for(i=0;i<w;i++)
		for(j=h-1;j>=0;j--)
			for(k=0;k<4;k++)
			if(map[j][i][k]){
				size=calc(j,i,k);
				if(size>max){
					max=size;
					ti=j;tj=i;tk=k;
				}
			}
	out<<max<<endl;
	out<<ti+1<<' '<<tj+1<<' '<<dic[tk]<<endl;;
}
int main(){
	int i,j,t,k;
	while(in>>w>>h){
		memset(map,0,sizeof(map));
		for(i=0;i<h;i++)
			for(j=0;j<w;j++){
				in>>t;
				for(k=0;k<4;k++)
					if(t&p[k])map[i][j][k]=1;
			}
		run();
	}
	return 0;
}