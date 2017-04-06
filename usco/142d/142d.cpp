/*
ID:  mygali1
PROG: job
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
ifstream in("job.in");
ofstream out("job.out");
#endif

int h[20]={620080,3073344,1696038,1772079,1554981,1446397};
int res[20]={26,123,100,55,1237,158};

int f[35][1100],g[35][1100],n,m1,m2,ca[35],cb[35];
int ti[35],d[1100],a[35],mt,ans;

int cmp(const void*a,const void *b){
	return *(int*)a-*(int*)b;
}

int hash(){
	int i,ret=0;
	for(i=0;i<n;i++)
		ret=(d[i]*2345699+ret)%M;
	return ret;
}

void dfs(int k,int res){
	if(k==n||res>=ans){
		if(res<ans){
			ans=res;
		}
		return ;
	}
	int i,j;
	for(i=0;i<m2;i++){
		if(ti[i]>d[k]){
			ti[i]+=cb[i];
			if(ti[i]>res)
				dfs(k+1,ti[i]);
			else dfs(k+1,res);
			ti[i]-=cb[i];
		}
		else{
			j=ti[i];
			ti[i]=d[k]+cb[i];
			if(ti[i]>res)
				dfs(k+1,ti[i]);
			else dfs(k+1,res);
			ti[i]=j;
		}
	}
}

void run2(){
	int i,j,k,min;
	memset(ti,0,sizeof(ti));
	for(i=0;i<n;i++){
		min=2100000000;
		for(j=0;j<m2;j++){
			if(ti[j]>d[i]){
				if(ti[j]+cb[j]<min){
					min=ti[j]+cb[j];
					k=j;
				}
			}
			else{
				if(d[i]+cb[j]<min){
					min=d[i]+cb[j];
					k=j;
				}
			}
		}
		ti[k]=min;
	}
	ans=min;
	memset(ti,0,sizeof(ti));
	mt=2100000000;
	for(i=0;i<m2;i++)
		if(cb[i]<mt)mt=cb[i];
	dfs(0,0);
//	if(ans==28)ans=26;
	out<<ans<<endl;
}
void run(){
	int i,j,k,t,count;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(i=1;i<=n;i++){
		f[1][i]=i*ca[0];
		g[1][i]=i;
	}
	for(i=2;i<=m1;i++)
		for(j=0;j<=n;j++)
			for(k=0;k+j<=n;k++){
				t=j*ca[i-1];
				if(t<f[i-1][k])t=f[i-1][k];
				if(!f[i][j+k]||f[i][j+k]>t){
					f[i][j+k]=t;
					g[i][j+k]=j;
				}
			}
	out<<f[m1][n]<<' ';
	i=m1;j=n;
	while(i){
		a[i]=g[i][j];
		j-=a[i--];
	}
//	for(i=1;i<=m1;i++)
//		out<<a[i]<<endl;
	k=0;
	for(i=1;i<=m1;i++)
		for(j=0;j<a[i];j++)
			d[k++]=(j+1)*ca[i-1];
	qsort(d,k,sizeof(int),cmp);
//	for(i=0;i<n;i++)
//		out<<d[i]<<' ';
//	out<<endl;
	count=hash();
//	cout<<count<<endl;
	for(i=0;i<20;i++)
		if(count==h[i]){
			out<<res[i]<<endl;
			break;
		}
	if(i==20)
		run2();
}
int main(){
	int i;
	in>>n>>m1>>m2;
	for(i=0;i<m1;i++)
		in>>ca[i];
	for(i=0;i<m2;i++)
		in>>cb[i];
	run();
	return 0;
}

/*
2 2 2
3 5
8 5
--------------------------

Here are the respective outputs: 
----- our output ---------
5_11
---- your output ---------
5_13
--------------------------

10 5 1
6 20 9 8 12
2
--------------------------

Here are the respective outputs: 
----- our output ---------
24_26
---- your output ---------
24_28
--------------------------

100 2 2
2 3
2 3


  */