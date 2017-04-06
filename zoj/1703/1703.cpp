#pragma warning (disable:4786)
#define for if(0);else for
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
#define get(a) (a==0?'x':'o');

/*

typedef vector<string> VS;
vector<string> vs;
int fx,fy;

map<vector<string>,bool> win[2];

int check(int x,int y,VS &vs){
	int i ;
	for(i=0;i<4;i++)if(vs[i][y]!=vs[x][y])break;
	if(i==4)return 1;
	for(i=0;i<4;i++)if(vs[x][i]!=vs[x][y])break;
	if(i==4)return 1;
	if(x==y){
		for(i=0;i<4;i++)if(vs[i][i]!=vs[x][y])break;
		if(i==4)return 1;
	}
	if(x+y==3){
		for(i=0;i<4;i++)if(vs[i][3-i]!=vs[x][y])break;
		if(i==4)return 1;
	}
	return 0;
}

int dfs(int depth,int who,VS &vs){
	if(win[who].find(vs)!=win[who].end())return win[who][vs];
	VS tmp=vs;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)if(tmp[i][j]=='.'){
			tmp[i][j]=get(who);
			if(check(i,j,tmp)){
				win[who][vs]=true;
				return 1;
			}
			if(!dfs(depth+1,!who,tmp)){
				win[who][tmp]=true;
				if(depth==0){
					fx=i;fy=j;
				}
				return 1;
			}
			tmp[i][j]='.';
		}
	win[who][vs]=false;
	return 0;
}

void run(){
	win[0].clear();win[1].clear();
	if(!dfs(0,0,vs)){
		cout<<"####"<<endl;
	}
	else cout<<"("<<fx<<","<<fy<<")"<<endl;
}
*/

int fx,fy;
char mat[4][5];

int check(int x,int y,char vs[][5]){
	int i ;
	for(i=0;i<4;i++)if(vs[i][y]!=vs[x][y])break;
	if(i==4)return 1;
	for(i=0;i<4;i++)if(vs[x][i]!=vs[x][y])break;
	if(i==4)return 1;
	if(x==y){
		for(i=0;i<4;i++)if(vs[i][i]!=vs[x][y])break;
		if(i==4)return 1;
	}
	if(x+y==3){
		for(i=0;i<4;i++)if(vs[i][3-i]!=vs[x][y])break;
		if(i==4)return 1;
	}
	return 0;
}
int dfs(int depth,int who,char mat[][5]){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)if(mat[i][j]=='.'){
//			if(depth==0){
//				cout<<i<<' '<<j<<endl;
//			}
			mat[i][j]=get(who);
			if(check(i,j,mat)){
				mat[i][j]='.';
				if(depth==0){
					fx=i;fy=j;
				}
				return 1;
			}
			else{
				int t=dfs(depth+1,!who,mat);
				mat[i][j]='.';
				if(!t){
					if(!depth){
						fx=i;fy=j;
					}
					return 1;
				}
			}
		}
	return 0;
}

void run(){
	if(!dfs(0,0,mat)){
		cout<<"#####"<<endl;
	}
	else cout<<"("<<fx<<","<<fy<<")"<<endl;
}
int main(){
	string tmp;
	while(1){
		cin>>tmp;
		if(tmp=="$")break;
		for(int i=0;i<4;i++){
			cin>>mat[i];
		}
		run();
	}
	return 0;
}