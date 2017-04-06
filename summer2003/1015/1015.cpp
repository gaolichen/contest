
/*
//浮点几何函数库
#ifdef WIN32
#pragma warning(disable:4786)
#endif
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{
	double x,y;
};

vector < struct point > vp;
vector < double > vd;
double pi=acos(-1.0);
int n;

void run(){
	int i;
	for(i=0;i<vp.size();i++){
		vd.push_back(vp[i].x);
		vd.push_back(vp[i].y);
	}
	sort(vd.begin(),vd.end());
	vd.erase(unique(vd.begin(),vd.end()),vd.end());
	map<double,int> m;
	map<double,int>::iterator it;
	for(i=0;i<vd.size();i++){
		if(i==0||fabs(vd[i]-vd[i-1])>eps)
			m[vd[i]]=0;
		else vd[i]=vd[i-1];
	}
	for(i=0;i<vp.size();i++){
		it=m.upper_bound(vp[i].x-eps);
		if(it!=m.end()&&fabs(it->first-vp[i].x)<eps){
			it->second++;
		}
		else while(1);
		it=m.upper_bound(vp[i].y-eps);
		if(it!=m.end()&&fabs(it->first-vp[i].y)<eps){
			it->second--;
		}
		else while(1);
	}
	int ret=0;
	i=0;
	for(it=m.begin();it!=m.end();++it){
		i+=it->second;
		if(i>ret)ret=i;
	}
	cout<<ret<<endl;
}

void add(double pre,double curr){
	struct point tmp;
	if(fabs(pre-curr)<pi){
		if(pre>curr)swap(pre,curr);
		tmp.x=pre;tmp.y=curr;
		if(fabs(tmp.x-tmp.y)>eps)
		vp.push_back(tmp);	
	}
	else{
		if(pre<curr)swap(pre,curr);
		tmp.x=pre;
		tmp.y=2*pi;
		if(fabs(tmp.x-tmp.y)>eps)
		vp.push_back(tmp);
		tmp.x=0;tmp.y=curr;
		if(fabs(tmp.x-tmp.y)>eps)
		vp.push_back(tmp);
	}
}

int main(){
	int i;
	double x,y,pre,curr,start;
	while(cin>>n){
		vp.clear();
		vd.clear();
		for(i=0;i<n;i++){
			cin>>x>>y;
			curr=atan2(y,x);
			if(i==0){
				pre=start=atan2(y,x);
			}
			else add(pre,curr);
		}
		add(curr,start);
		run();
	}
	return 0;
}*/

int mark[N],n;
void run(){
	int i,j,k,ti;
	double s,min;
	point temp,t,tt;
	line tl,ttl;
	for(i=0;i<n;i++){
		l[i].p=fen[i];
		l[i].q=fen[i+1];
	}
/*	for(i=0;i<n;i++)
		for(j=(i+2)%n;(j+1)%n!=i;j++)
			if(judgeinter(l[i],l[j%n])){
				out<<"NOFENCE"<<endl;
				return ;
			}*/
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			temp.x=(fen[i].x+fen[j].x)*0.5;
			temp.y=(fen[i].y+fen[j].y)*0.5;
			min=M;
			tl.p=v;tl.q=temp;
			for(k=0;k<n;k++)
				if(judgeinter2(l[k],tl)){
					intersect(tl,l[k],&t);
					ttl.p=v;ttl.q=t;
					if(!betweenline(ttl,temp)&&!betweenline(tl,t))continue;
					s=pointdis(t,v);
					if(s<min){
						min=s;
						ti=k;
						tt=t;
					}
				}
			if(min==M)continue;
			if(!samepoint(tt,l[ti].p)&&!samepoint(tt,l[ti].q))
				mark[ti]=1;
		}
	for(i=j=0;i<n;i++)
		if(mark[i])j++;
	out<<j<<endl;
/*	setprecision(0);	
	for(i=0;i<n-2;i++)
		if(mark[i])
			out<<fen[i].x<<' '<<fen[i].y<<' '<<fen[i+1].x<<' '<<fen[i+1].y<<endl;
	if(mark[n-1])
		out<<fen[0].x<<' '<<fen[0].y<<' '<<fen[n-1].x<<' '<<fen[n-1].y<<endl;
	i=n-2;
	if(mark[n-2])
		out<<fen[i].x<<' '<<fen[i].y<<' '<<fen[i+1].x<<' '<<fen[i+1].y<<endl;*/
}
int main(){
	int i;
	while(in>>n){
		v.x=v.y=0;
//		cin>>v.x>>v.y;
		for(i=0;i<n;i++)
			in>>fen[i].x>>fen[i].y;
		fen[n]=fen[0];
		run();
	}
	return 0;
}