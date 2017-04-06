/*
ID:  mygali1
PROG: race3
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
#define MAXN 110
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("race3.in");
ofstream out("race3.out");
#endif

int n,mat[MAXN][MAXN];

//图得必经点，传入连接矩阵mat，mat[i][j]=1表示有i到j
//得弧，n为点的个数，s为起点，e为终点，p为待测点，返回1
//为必经点，0为非必经点，起点和终点为必经点，mark返回
//删去p后，s可以到达的点
int ness_pass_point(int mat[][MAXN],int n,int s,int e,int p,int *mark){
	if(p==s||p==e)return 1;
	int i,sk[MAXN],opn,cls;
	for(i=0;i<n;i++)mark[i]=0;
	mark[s]=mark[p]=1;
	sk[opn=cls=0]=s;
	while(opn<=cls){
		for(i=0;i<n;i++)
			if(!mark[i]&&mat[sk[opn]][i]){
				sk[++cls]=i;
				mark[i]=1;
			}
		opn++;
	}
//	out<<mark[e]<<' ';
	return mark[e]?0:1;
}
//有向图的分裂点，说明同上
int splitting_point(int mat[][MAXN],int n,int s,int e,int p){
	if(p==s||p==e)return 0;
	int mark[MAXN],i,j;
	if(!ness_pass_point(mat,n,s,e,p,mark))return 0;
	for(i=0;i<n;i++)
		if(!mark[i])
			for(j=0;j<n;j++)
				if(mark[j]&&j!=p&&mat[i][j])return 0;
	for(i=0;i<n;i++)
		if(i!=p&&mat[p][i]&&mark[i])return 0;
	return 1;
}

void run(){
	int i,ness[MAXN],spl[MAXN],mark[MAXN];
	int nn=0,ns=0;
	for(i=1;i<n-1;i++){
		if(!ness_pass_point(mat,n,0,n-1,i,mark))
			continue;
		ness[nn++]=i;
		if(splitting_point(mat,n,0,n-1,i))
			spl[ns++]=i;
	}
	out<<nn;
	for(i=0;i<nn;i++)
		out<<' '<<ness[i];
	out<<endl<<ns;
	for(i=0;i<ns;i++)
		out<<' '<<spl[i];
	out<<endl;
}
int main(){
	int flag=0,i;
	n=0;
	memset(mat,0,sizeof(mat));
	while(1){
		while(1){
			in>>i;
			if(i==-1){
				flag=1;break;
			}
			if(i==-2)break;
			mat[n][i]=1;
		}
		if(flag)break;
		n++;
	}
//	for(i=0;i<n;i++,out<<endl)
//		for(flag=0;flag<n;flag++)
//			out<<mat[i][flag]<<' ';
	run();
	return 0;
}

/*
1 -2
4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 -2
3 -2
48 49 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 -2
2 3 -2
-2
-1
--------------------------

Here are the respective outputs: 
----- our output ---------
2_1_3
1_1
---- your output ---------
2_1_3
2_1_3
--------------------------

  */