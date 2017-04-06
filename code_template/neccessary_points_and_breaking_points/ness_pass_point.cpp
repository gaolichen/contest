#include<iostream.h>
#include<string.h>
#define MAXN 310
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

int main(){
	return 0;
}