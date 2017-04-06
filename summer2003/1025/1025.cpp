#pragma warning(disable:4786)
#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<string>

using namespace std;
map<string,int> m;
map<int,int> mi;

struct NODE{
	string c;
	int s,e;
};
vector<NODE> vn;
int total;

void run(){
	int i,j;
	mi.clear();
	for(i=0;i<vn.size();i++){
		j=m[vn[i].c];
		mi[vn[i].s]+=j;
		mi[vn[i].e]-=j;
	}
	int ret=0;
	i=0;
	for(map<int,int>::iterator it=mi.begin();it!=mi.end();++it){
		i+=it->second;
		if(i>ret){
			ret=i;
			if(ret>total){
				cout<<"The power will be out at time "<<it->first<<" because the power is ";
				cout<<ret;
				cout<<(" Watts")<<" and overloaded."<<endl;
				return ;
			}
		}
	}
	cout<<"The maximum power needed is "<<ret;
	cout<<(" Watts.")<<endl;
}

int main(){
	int i,t,v,j;
	string s;
	char buf[100];
	cin>>t;
	cin.getline(buf,80);
	m.clear();
	for(i=0;i<t;i++){
		cin.getline(buf,99);
		j=strlen(buf);
		while(buf[j]!=']')j--;
		buf[j]=0;
		s=buf;
		sscanf(buf+j+1,"%d",&v);
		m[s]=v;
	}
	int k;
	while(cin>>k>>total){
		vn.resize(k);
		mi.clear();
		cin.getline(buf,80);
		for(i=0;i<k;i++){
			cin.getline(buf,99);
			j=strlen(buf);
			while(buf[j]!=']')j--;
			buf[j]=0;
			vn[i].c=buf;
			sscanf(buf+j+1,"%d %d",&vn[i].s,&vn[i].e);
		}
		run();
	}
	return 0;
}