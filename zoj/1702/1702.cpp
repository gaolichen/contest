#pragma warning (disable:4786)
#define for if(0);else for
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string dir;
vector<string> vs;
vector< vector<string> > mat;

void init(char ch,int k){
	int maxlen=0;
	for(int i=0;i<mat.size();i++)
		if(maxlen<mat[i][k].length())maxlen=mat[i][k].length();
	for(int i=0;i<mat.size();i++)if(mat[i][k].length()<maxlen){
		if(ch=='<'){
			for(int j=mat[i][k].length();j<maxlen;j++)mat[i][k]+=" ";
		}
		else if(ch=='>'){
			for(int j=mat[i][k].length();j<maxlen;j++)mat[i][k]=" "+mat[i][k];
		}
		else {
			int left=(maxlen-mat[i][k].length())/2;
			int right=maxlen-mat[i][k].length()-left;
			for(int j=0;j<left;j++)mat[i][k]=" "+mat[i][k];
			for(int j=0;j<right;j++)mat[i][k]+=" ";
		}
	}
}

void printmid(int maxlen){
		cout<<"|-";
		for(int i=0;i<mat[0].size()-1;i++){
			for(int j=0;j<mat[0][i].length();j++)
				cout<<"-";
			cout<<"-+-";
		}
		for(int j=0;j<mat[0][mat[0].size()-1].length();j++)
			cout<<"-";
		cout<<"-|";
		cout<<endl;
}
void printhead(int maxlen){
	cout<<"@-";
	for(int i=0;i<maxlen+(mat[0].size()-1)*3;i++)cout<<"-";
	cout<<"-@";
	cout<<endl;
}
void run(){
	mat.clear();
	mat.resize(vs.size());
	for(int i=0;i<mat.size();i++)mat[i].resize(dir.length());
//	cout<<"a"<<endl;
	for(int i=0;i<vs.size();i++){
		int pre=0,j=0,cnt=0;
		while(pre<vs[i].length()){
			while(j<vs[i].length()&&vs[i][j]!='&')j++;
			string tmp=vs[i].substr(pre,j-pre);
			mat[i][cnt++]=tmp;
			pre=++j;
		}
	}
//	for(int i=0;i<mat.size();i++,cout<<endl)
//		for(int j=0;j<mat[i].size();j++)
//			cout<<mat[i][j]<<' ';
//	cout<<"b"<<endl;
	for(int i=0;i<dir.length();i++){
		init(dir[i],i);
	}
	int mlen=0;
	for(int i=0;i<mat[0].size();i++)mlen+=mat[0][i].length();
	printhead(mlen);
	cout<<"|";
	for(int i=0;i<mat[0].size();i++){
		cout<<" "<<mat[0][i]<<" |";
	}
	cout<<endl;
	printmid(mlen);
//	cout<<"c"<<endl;
	for(int i=1;i<mat.size();i++){
		cout<<"|";
		for(int j=0;j<mat[i].size();j++)
			cout<<" "<<mat[i][j]<<" |";
		cout<<endl;
	}
	printhead(mlen);
}
int main(){
	getline(cin,dir);
	while(1){
		if(dir=="*")break;
		vs.clear();
		string tmp;
		while(getline(cin,tmp)){
			if(tmp=="*"||tmp[0]=='<'||tmp[0]=='>'||tmp[0]=='=')break;
			vs.push_back(tmp);
		}
		run();
		dir=tmp;
	}
	return 0;
}