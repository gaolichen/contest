#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define esp 1e-8

vector<double> a;
vector<int> len;
vector<double> dv;
int n;

double calc(int p,int &length){
	double ret=a[p];
	length=1;
	p++;
	while(p<a.size()&&dv[p]<ret+esp){
		ret=(ret*length+dv[p]*len[p])/(length+len[p]);
		length+=len[p];
		p+=len[p];
	}
	return ret;
}

void run(){
	dv.clear();
	len.clear();
	dv.resize(n);
	len.resize(n);
	double best,tmp;
	int length;
	best=(*dv.rbegin())=(*a.rbegin());
	(*len.rbegin())=1;
	int i;
	for(i=dv.size()-2;i>=0;i--){
		tmp=calc(i,length);
		dv[i]=tmp;
		len[i]=length;
		if(tmp>best)best=tmp;
	}
	printf("%.6lf\n",best);
}
int main(){
	int i;
	while(cin>>n){
		a.clear();
		a.resize(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		run();
	}
	return 0;
}