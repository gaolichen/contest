/*
ID:  mygali1
PROG: stall4
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 3456793
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("stall4.in");
ofstream out("stall4.out");
#endif


//二分图最大匹配,hungary算法,邻接阵形式,复杂度O(m*m*n)
//返回最大匹配数,传入二分图大小m,n和邻接阵mat,非零元素表示有边
//match1,match2返回一个最大匹配,未匹配顶点match值为-1
#define MAXN 310
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int mat[MAXN][MAXN],mat1[MAXN],mat2[MAXN],num[MAXN];
int n,m;

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

int main(){
	int i,j,k;
	in>>n>>m;
	memset(mat,0,sizeof(mat));
	for(i=0;i<n;i++){
		in>>num[i];
		for(j=0;j<num[i];j++){
			in>>k;
			mat[i][k-1]=1;
		}
	}
	out<<hungary(n,m,mat,mat1,mat2)<<endl;
	return 0;
}