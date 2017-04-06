/*
ID:  mygali1
PROG: camelot
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("camelot.in");
ofstream out("camelot.out");
#endif

int kmx[9]={0,1,1,1,-1,-1,-1,0,0};
int kmy[9]={0,1,0,-1,1,0,-1,1,-1};
int mx[8]={-2,-2,-1,-1,1,1,2,2};
int my[8]={1,-1,2,-2,2,-2,1,-1};
int col,row,count,sx,sy,kco,kro;
int dis[41][30][41][30],nico[30*40],niro[30*40];
int x[30*40],y[30*40];
char mark[41][30];

int check1(int x,int y,int k){
	if(x+kmx[k]<0||x+kmx[k]>=col||y+kmy[k]<0||y+kmy[k]>=row)
		return 0;
	return 1;
}
inline int check2(int x,int y,int k){
	if(x+mx[k]<0||x+mx[k]>=col||y+my[k]<0||y+my[k]>=row)
		return 0;
	if(mark[x+mx[k]][y+my[k]])return 0;
	return 1;
}
void bfs(){
	int i,open,close,tx,ty;
	open=close=0;
	x[0]=sx;y[0]=sy;
	while(open<=close){
		tx=x[open];ty=y[open];
		for(i=0;i<8;i++)
			if(check2(tx,ty,i)){
				x[++close]=tx+mx[i];
				y[close]=ty+my[i];
				mark[x[close]][y[close]]=1;
				if(dis[x[close]][y[close]][sx][sy]>dis[tx][ty][sx][sy]+1)
					dis[x[close]][y[close]][sx][sy]=dis[sx][sy][x[close]][y[close]]=dis[tx][ty][sx][sy]+1;
			}
		open++;
	}
}
void run(){
	int i,j,best=M,k,h,min,ti,temp,t;
	if(count==0){
		out<<0<<endl;
		return ;
	}
	for(i=0;i<col;i++)
		for(j=0;j<row;j++)
			for(k=0;k<col;k++)
				for(h=0;h<row;h++){
					if(k==i&&h==j)dis[i][j][k][h]=0;
					else dis[i][j][k][h]=M;
				}
	for(i=0;i<col;i++)
		for(j=0;j<row;j++){
			sx=i;sy=j;
			memset(mark,0,sizeof(mark));
			mark[i][j]=1;
			bfs();
		}
	for(i=0;i<9;i++)
		if(check1(kco,kro,i)){
			nico[count]=kco+kmx[i];
			niro[count]=kro+kmy[i];
			if(i)temp=1;else temp=0;
			min=M;
			for(j=0;j<col;j++)
				for(k=0;k<row;k++){
					t=-M;
					for(h=0;h<count;h++)
						if(dis[j][k][nico[h]][niro[h]]-dis[nico[count]][niro[count]][nico[h]][niro[h]]>t){
							t=dis[j][k][nico[h]][niro[h]]-dis[nico[count]][niro[count]][nico[h]][niro[h]];
							ti=h;
						}
					t=dis[nico[ti]][niro[ti]][nico[count]][niro[count]];
					for(h=0;h<=count;h++)
						if(h!=ti){
							t+=dis[j][k][nico[h]][niro[h]];
							if(t>=min||t>=best)break;
						}
					if(h<=count)continue;
					if(t<min)min=t;
				}
			temp+=min;
			if(temp<best)best=temp;
		}
	out<<best<<endl;
}

int main(){
	char ch;
	int i;
	while(in>>col>>row){
		in>>ch>>kco;
		kro=ch-'A';kco--;
		i=0;
		while(in>>ch>>nico[i]){
			niro[i]=ch-'A';
			nico[i++]--;
		}
		count=i;
		run();
	}
	return 0;
}