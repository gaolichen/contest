/*
ID:  mygali1
PROG: ttwo
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("ttwo.in");
ofstream out("ttwo.out");
#endif

int mx[4]={-1,0,1,0};
int my[4]={0,1,0,-1};
char mark[10][10][4][10][10][4];
char map[10][10];

void move(int *x,int *y,int *d){
	int tx,ty;
	tx=*x+mx[*d];
	ty=*y+my[*d];
	if(tx<0||tx>=10||ty<0||ty>=10||map[tx][ty]=='*'){
		tx=*x;ty=*y;
		(*d)=(*d+1)%4;
	}
	*x=tx;*y=ty;
}
void run(){
	int i,j,fx,fy,cx,cy,fdic,cdic;
	memset(mark,0,sizeof(mark));
	for(i=0;i<10;i++)
		for(j=0;j<10;j++){
			if(map[i][j]=='F'){
				fx=i;fy=j;
			}
			if(map[i][j]=='C'){
				cx=i;cy=j;
			}
		}
	mark[fx][fy][0][cx][cy][0]=1;
	fdic=cdic=0;i=0;
	while(1){
		move(&fx,&fy,&fdic);
		move(&cx,&cy,&cdic);
		i++;
		if(fx==cx&&fy==cy){
			out<<i<<endl;
			return ;
		}
		if(mark[fx][fy][fdic][cx][cy][cdic]){
			out<<0<<endl;
			return ;
		}
		mark[fx][fy][fdic][cx][cy][cdic]=1;
	}
}
int main(){
	int i;
	while(in>>map[0]){
		for(i=1;i<10;i++)
			in>>map[i];
		run();
	}
	return 0;
}