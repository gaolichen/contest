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

int n,m;
int mat[110][110];

void run(){
//	for(int i=0;i<=n;i++,cout<<endl)
//		for(int j=0;j<=n;j++)cout<<mat[i][j]<<' ';
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				if(mat[i][j]>mat[i][k]+mat[k][j])mat[i][j]=mat[i][k]+mat[k][j];
	for(int i=0;i<=n;i++){if(mat[i][i]<0){
		cout<<"successful conspiracy"<<endl;
		return ;
	}
//	cout<<mat[i][i]<<endl;
	}
	cout<<"lamentable kingdom"<<endl;
}
int main(){
	int a,b,d;
	string c;
	while(1){
		cin>>n;if(!n)break;
		cin>>m;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)if(i==j)mat[i][j]=0;else mat[i][j]=210000000;
		for(int i=0;i<m;i++){
			cin>>a>>b>>c>>d;
			b+=a;
			if(c=="gt"){
				mat[b][a-1]=-(d+1);
			}
			else mat[a-1][b]=d-1;
		}
		run();
	}
	return 0;
}