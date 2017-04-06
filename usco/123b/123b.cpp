/*
ID:  mygali1
PROG: comehome
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
ifstream in("comehome.in");
ofstream out("comehome.out");
#endif

int map[60][60],nearest[60],mark[60],dis[60];

void run(){
	int i,j,ti,min;	
	for(i=0;i<52;i++)
		nearest[i]=51;
	memset(dis,0,sizeof(dis));
	memset(mark,0,sizeof(mark));
	mark[51]=1;
	/*
	for(;;){
		min=M;
		for(j=0;j<52;j++)
			if(!mark[j]&&map[j][nearest[j]]){
				if(dis[j]==0||dis[j]>dis[nearest[j]]+map[j][nearest[j]])
					dis[j]=dis[nearest[j]]+map[j][nearest[j]];
				if(dis[j]<min){
					min=dis[j];
					ti=j;
				}
			}
		if(min==M)break;
		mark[ti]=1;
		for(j=0;j<52;j++)
			if(!mark[j]&&map[j][ti]&&(map[j][nearest[j]]==0||map[j][nearest[j]]>map[j][ti]))
				nearest[j]=ti;
	}*/
	while(1){
		min=M;
		for(i=0;i<52;i++)
			if(mark[i])
				for(j=0;j<52;j++)
					if(!mark[j]&&map[j][i]){
						if(dis[j]==0||dis[j]>dis[i]+map[j][i])
							dis[j]=dis[i]+map[j][i];
						if(dis[j]<min){
							min=dis[j];
							ti=j;
						}
					}
		if(min==M)break;
		mark[ti]=1;
	}
	min=M;
	for(i=26;i<51;i++)
		if(dis[i]&&dis[i]<min){
			min=dis[i];
			ti=i;
		}
	out<<char(ti-26+'A');
	out<<' '<<min<<endl;
}

int main(){
	int n,t,t1,t2,i;
	char buf1[10],buf2[10];
	while(in>>n){
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++){
			in>>buf1>>buf2>>t;
			if(buf1[0]>='a'&&buf1[0]<='z')
				t1=buf1[0]-'a';
			else t1=buf1[0]-'A'+26;
			if(buf2[0]>='a'&&buf2[0]<='z')
				t2=buf2[0]-'a';
			else t2=buf2[0]-'A'+26;
			if(!map[t1][t2]||map[t1][t2]>t)
			map[t1][t2]=map[t2][t1]=t;
		}
		run();
	}
	return 0;
}