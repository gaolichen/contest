#include<iostream.h>

//����ͼ��С������,prim�㷨,�ڽ�����ʽ,���Ӷ�O(n^2)
//������С�������ĳ���,����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩinf
//�ɸ��ı�Ȩ������,pre[]�������Ĺ���,�ø�����ʾ,���ڵ�(��һ��)preֵΪ-1
//���뱣֤ͼ����ͨ��!
#define MAXN 1100
#define inf 1000000000
typedef int elem_t;

elem_t prim(int n,elem_t mat[][MAXN],int* pre){
	elem_t min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}
	return ret;
}

int n,a[MAXN][MAXN],b[MAXN];

void run(){
	cout<<prim(n,a,b)<<endl;
}
int main(){
	int i,j,t,k;
	for(i=0,cin>>t;i<t;i++){
		cin>>n;
		for(j=0;j<n;j++)
			cin>>b[j];
		for(j=0;j<n;j++)
			for(k=0;k<n;k++){
				cin>>a[j][k];
				if(j!=k)a[j][k]+=b[j]+b[k];
			}
		run();
	}
	return 0;
}