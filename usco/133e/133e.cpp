/*
ID:  mygali1
PROG: concom
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("concom.in");
ofstream out("concom.out");
#endif

int map[110][110],mat[110][110],n,mark[110][110],count;
void run(){
	int i,j,flag,k;
	memset(mark,0,sizeof(mark));
	memcpy(mat,map,sizeof(map));
	while(1){
		flag=0;
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
				if(mat[i][j]>50&&!mark[i][j]){
					if(!flag)flag=1;
					mark[i][j]=1;
					for(k=1;k<=100;k++)
						mat[i][k]+=map[j][k];
				}
		if(!flag)break;
	}
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			if(i!=j&&mark[i][j])
				out<<i<<' '<<j<<endl;

}

int main(){
	int i,j,k,p;
	while(in>>n){
		count=0;
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++){
			in>>j>>k>>p;
			if(j==k)continue;
/*			t1=t2=-1;
			for(h=0;h<count;h++){
				if(j==node[h])t1=h;
				if(k==node[h])t2=h;
			}
			if(t1==-1){
				t1=count;
				node[count++]=j;
			}
			if(t2==-1){
				t2=count;
				node[count++]=k;
			}*/
			map[j][k]=p;
		}
		run();
	}
	return 0;
}