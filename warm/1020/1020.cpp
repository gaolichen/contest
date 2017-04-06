//bu hui zuo le -.-

#pragma warning(disable : 4786)
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

string cap="DLRU";

vector<string> mat,tvs;
map< vector<string> ,bool > m;
vector< vector<string> > sk;
vector<char> dir,step;
vector<int> pre;

bool ok(vector<string> & vs){
	int i,j;
	for(i=0;i<vs.size();i++)
		for(j=0;j<vs[i].length();j++)
			if(vs[i][j]=='1'||vs[i][j]=='2'||vs[i][j]=='3')return false;
	return true;
}

void move(int k,vector<string> &vs,vector<string> &ret){
//	int i,j;
	tvs.clear();
	switch(k){
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}
int bfs(){
	int i,opn=0;
	vector<string> tmp;
	sk.clear();
	step.clear();
	step.push_back(0);
	dir.clear();
	dir.push_back(0);
	pre.clear();
	pre.push_back(-1);
	m.clear();
	sk.push_back(mat);
	if(ok(sk[0])){
		cout<<endl;
		return -1;
	}
	while(opn<sk.size()){
		if(step[opn]>=18)return -1;
		for(i=0;i<4;i++){
			move(i,sk[opn],tmp);
			if(m.find(tmp)!=m.end())continue;
			m[tmp]=true;
			sk.push_back(tmp);
			pre.push_back(opn);
			step.push_back(step[opn]+1);
			dir.push_back(i);
			if(ok(*(sk.rbegin()))){
				break;
			}
		}
		opn++;
	}
	if(opn==sk.size())
		return -1;
	string s;
	for(i=sk.size()-1;i>0;i=pre[i]){
		s=cap[dir[i]]+s;
	}
	cout<<s<<endl;
	return 1;
}

void run(){
	if(!bfs()){
		cout<<-1<<endl;
		return ;
	}
}
int main(){
	int t,n,m,i;
	cin>>t;
	while(t--){
		cin>>n>>m;
		mat.clear();
		mat.resize(n);
		getline(cin,mat[0]);
		for(i=0;i<m;i++)
			getline(cin,mat[i]);
		run();
	}
	return 0;
}