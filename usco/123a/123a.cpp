/*
ID:  mygali1
PROG: maze1
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
ifstream in("maze1.in");
ofstream out("maze1.out");
#endif

int w,h,count,x[4000],y[4000],dis[110][40],ex[4],ey[4];
int mx[4]={0,0,1,-1};
int my[4]={1,-1,0,0};
char map[210][80];

int check(int x,int y,int k){
	int tx,ty;
	tx=2*x+1;ty=2*y+1;
	tx+=mx[k];
	ty+=my[k];
	if(tx<=0||tx>=2*h||ty<=0||ty>=2*w)return 0;
	if(map[tx][ty]!=' ')return 0;
	if(dis[x+mx[k]][y+my[k]]&&dis[x+mx[k]][y+my[k]]<=dis[x][y]+1)return 0;
	return 1;
}
void run(){
	int i,j,open,close,tx,ty;
	count=0;
	for(i=1;i<2*w+1;i+=2){
		if(map[0][i]==' '){
			ex[count]=0;
			ey[count++]=i/2;
		}
		if(map[2*h][i]==' '){
			ex[count]=h-1;
			ey[count++]=i/2;
		}
	}
	for(i=1;i<2*h+1;i+=2){
		if(map[i][0]==' '){
			ex[count]=i/2;
			ey[count++]=0;
		}
		if(map[i][2*w]==' '){
			ex[count]=i/2;
			ey[count++]=w-1;
		}
	}
	memset(dis,0,sizeof(dis));
	for(i=0;i<count;i++){
//		out<<ex[i]<<' '<<ey[i]<<endl;
		open=close=0;
		dis[ex[i]][ey[i]]=1;
		x[0]=ex[i];y[0]=ey[i];
		while(open<=close){
			tx=x[open];
			ty=y[open];
			for(j=0;j<4;j++)
				if(check(tx,ty,j)){
					x[++close]=tx+mx[j];
					y[close]=ty+my[j];
					dis[x[close]][y[close]]=dis[tx][ty]+1;
				}
			open++;
		}
	}
	int max=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
//			out<<dis[i][j]<<' ';
			if(dis[i][j]&&dis[i][j]>max)max=dis[i][j];
		}
//		out<<endl;
	}
	out<<max<<endl;
}
int main(){
	int i;
	while(in>>w>>h){
		in.getline(map[0],110);
		for(i=0;i<2*h+1;i++)
			in.getline(map[i],110);
//		for(i=0;i<2*h+1;i++)
//			out<<map[i]<<endl;
		run();
	}
	return 0;
}