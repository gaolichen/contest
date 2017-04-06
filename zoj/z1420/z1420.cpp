#ifdef WIN32
#	pragma warning(disable:4786)
#define for if(0);else for
#endif
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

int n,num[40],r[40];
int mat[40][40];
int curr[30],best[30],pre[30];

inline int max(int a,int b){
	return a>b?a:b;
}

int haha=0;

void output(){
/*	cout<<++haha<<":"<<endl;
	for(int i=0;i<=32;i++,cout<<endl)
		for(int j=0;j<=32;j++)cout<<mat[i][j]<<' ';*/
}

void run(){
	for(int i=0;i<=32;i++)
		for(int j=0;j<=32;j++)if(i==j)mat[i][j]=0;
		else mat[i][j]=100;
	for(int i=25;i<=32;i++){num[i]=num[i-24];r[i]=r[i-24];}
	for(int i=1;i<=32;i++)mat[i-1][i]=num[i];
	
	for(int i=1;i<=32;i++)cout<<r[i]<<' '<<num[i]<<endl;
	for(int i=8;i<=32;i++){
		mat[i][i-8]=-r[i];
		cout<<i<<' '<<i-8<<' '<<-r[i]<<endl;
	}
	output();
	while(1){
		int change=0;
		for(int k=0;k<=32;k++)
		for(int i=0;i<=32;i++)
			for(int j=0;j<=32;j++)
				if(mat[i][j]>mat[i][k]+mat[k][j]){
					change=1;
					mat[i][j]=mat[i][k]+mat[k][j];
					if(i-j==24){
						for(int h=24;h<=32;h++)mat[h][h-24]=mat[i][j];
					}
					else if(j-i==24){
						for(int h=0;h<=8;h++)mat[h][h+24]=mat[i][j];
					}
				}
				output();
		for(int i=0;i<=32;i++)if(mat[i][i]<0){
			cout<<i<<' '<<mat[i][i]<<endl;
			cout<<"No Solution"<<endl;
			return ;
		}
//		int min=-1000;
/*		for(int i=24;i<=32;i++)if(mat[i-24][i]>min)min=mat[i-24][i];
		for(int i=24;i<=32;i++)if(mat[i-24][i]!=min||
		mat[i][i-24]!=-min){
			change=1;
			mat[i][i-24]=-min;
			mat[i-24][i]=min;
		}*/
		if(!change)break;
	}
	cout<<mat[0][24]<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<24;i++)
			cin>>r[i+1];
		cin>>n;
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			int a;
			cin>>a; num[a+1]++;
		}
		run();
	}
	return 0;
}