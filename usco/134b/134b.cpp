/*
ID:  mygali1
PROG: cowtour
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("cowtour.in");
ofstream out("cowtour.out");
#endif

double mat[200][200],f[200],x[200],y[200];
char map[200][200],mark[200];
int n,num[200],tot[200][200];
inline double dis(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void run(){
	int i,j,k,count,h;
	double min,best;
	char buf[100];
	if(n==1){
		out<<"0.000000"<<endl;
		return ;
	}
	memset(mat,0,sizeof(mat));
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(map[i][j]=='1')
				mat[i][j]=mat[j][i]=dis(i,j);
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			if(i!=k&&mat[i][k])
			for(j=0;j<n;j++)
				if(j!=i&&j!=k&&mat[k][j]&&(mat[i][j]==0||mat[i][j]>mat[i][k]+mat[k][j]))
					mat[i][j]=mat[j][i]=mat[i][k]+mat[j][k];
	memset(mark,0,sizeof(mark));
	count=0;
	for(i=0;i<n;i++)
		if(!mark[i]){
			count++;mark[i]=count;
			num[count]=1;
			tot[count][0]=i;
			for(j=i+1;j<n;j++)
			if(mat[i][j]>1e-6){
				mark[j]=count;
				tot[count][num[count]]=j;
				num[count]++;
			}
//			out<<count<<' '<<num[count]<<endl;
		}
	best=0;
	for(i=0;i<n;i++){
		min=0;
		for(j=0;j<n;j++)
			if(mat[i][j]>min)
				min=mat[i][j];
		f[i]=min;
		if(f[i]>best)best=f[i];
//		if(mark[i])printf("%d\n",i);
//		printf("%lf\n",f[i]);
	}
	min=M;
	for(i=1;i<=count;i++)
		for(j=i+1;j<=count;j++)
			for(k=0;k<num[i];k++)
				for(h=0;h<num[j];h++)
					if(f[tot[i][k]]+f[tot[j][h]]+dis(tot[i][k],tot[j][h])<min)
						min=f[tot[i][k]]+f[tot[j][h]]+dis(tot[i][k],tot[j][h]);
	if(min>best)best=min;
	sprintf(buf,"%.6lf",best);
	out<<buf<<endl;
}
int main(){
	int i;
	while(in>>n){
		for(i=0;i<n;i++)
			in>>x[i]>>y[i];
		for(i=0;i<n;i++)
			in>>map[i];
		run();
	}
	return 0;
}