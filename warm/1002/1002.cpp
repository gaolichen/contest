#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

map<int ,int> m;
int mcnt;
struct NODE{
	int x,y;
	vector<int> c;
};
vector<NODE> vp;

int getmap(int i){
	if(m.find(i)!=m.end())
		return m[i];
	return m[i]=mcnt++;
}

void run(){
}

int main(){
	int i,j,k,t,h,d;
	cin>>t;
	while(t--){
		cin>>n;
		m.clear();
		vp.resize(n);
		for(i=mcnt=0;i<n;i++){
			cin>>j;
			j=getmap(j);
			cin>>vp[j].x>>vp[j].y;
			cin>>d;
			vp[j].c.resize(d);
			for(k=0;k<d;k++){
				cin>>h;
				h=getmap(h);
				vp[j].c.push_back(h);
			}
		}
		run();
	}
	return 0;
}