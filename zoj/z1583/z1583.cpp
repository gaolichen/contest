#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

int output[600][600],mat[600][600],n;

int b[4][4]={{0,0,0,0},{0,1,2,1},{0,2,4,2},{0,1,2,1}};

void run(){
	int i,j,k,h;
	memcpy(output,mat,sizeof(mat));
	for(i=1;i<n-1;i++)
		for(j=1;j<n-1;j++){
			for(k=1,output[i][j]=0;k<=3;k++)
				for(h=1;h<=3;h++)
					output[i][j]+=mat[i+k-2][j+h-2]*b[k][h];
			output[i][j]/=16;
		}
	for(i=0;i<n;i++,cout<<endl)
		for(j=0;j<n;j++){
			if(j)cout<<' ';
			cout<<output[i][j];
		}
}

int main(){
	int i,j,cnt=0;
	while(cin>>n){
		if(!n)break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>mat[i][j];
		cout<<"Case "<<++cnt<<":"<<endl;
		run();
	}
	return 0;
}