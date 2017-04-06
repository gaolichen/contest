#include<iostream.h>
#include<string.h>
#define MAXN 310
//ͼ�ñؾ��㣬�������Ӿ���mat��mat[i][j]=1��ʾ��i��j
//�û���nΪ��ĸ�����sΪ��㣬eΪ�յ㣬pΪ����㣬����1
//Ϊ�ؾ��㣬0Ϊ�Ǳؾ��㣬�����յ�Ϊ�ؾ��㣬mark����
//ɾȥp��s���Ե���ĵ�
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
//����ͼ�ķ��ѵ㣬˵��ͬ��
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