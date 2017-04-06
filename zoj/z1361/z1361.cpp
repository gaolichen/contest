
#ifdef WIN32
#	pragma warning(disable:4786)
#endif
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
int mx[8]={0,1,0,-1,1,1,-1,-1};
int my[8]={1,0,-1,0,1,-1,-1,1};


char mat[21][21],mark[401*(1<<14)];
int p[20],sk[401*(1<<14)];
short step[401*(1<<14)];
int nx[410],ny[410];
int n,m,l,s,tmp,ttx,tty,ii;


int check(){
	s=tmp;
	ttx=tty=0;
	for(ii=l-1;ii>=0;ii--){
		ttx+=mx[s/p[ii]];
		tty+=my[s/p[ii]];
		if(!ttx&&!tty)return 0;
		s%=p[ii];
	}
	return 1;
}
void bfs(){
	int opn,cls,i,tx,ty,xx,yy;
	opn=cls=0;
	while(opn<=cls){
		tx=sk[opn]%400;
		ty=tx%m;
		tx/=m;
		for(i=0;i<4;i++)
			if(inmat(tx+mx[i],ty+my[i],n,m)){
				xx=tx+mx[i];
				yy=ty+my[i];
				if(mat[xx][yy])continue;
				tmp=(sk[opn]/400)+((i+2)%4)*p[l-1];
				if(!check())continue;
				tmp/=4;
				tmp=tmp*400+xx*m+yy;
				if(mark[tmp])continue;
				if(!xx&&!yy){
					cout<<step[opn]+1<<endl;
					return ;
				}
				sk[++cls]=tmp;
				step[cls]=step[opn]+1;
				mark[sk[cls]]=1;
			}
		opn++;
	}
	cout<<-1<<endl;
	return ;
}
void run(){
	int i,k,j;
	cls(mark);
	for(i=k=0;i<l-1;i++){
		for(j=0;j<4;j++)
			if(nx[i]+mx[j]==nx[i+1]&&ny[i]+my[j]==ny[i+1])break;
		k=k*4+j;
	}
	if(!nx[0]&&!ny[0]){
		cout<<0<<endl;
		return ;
	}
	k=k*400+nx[0]*m+ny[0];
	mark[k]=1;
	sk[0]=k;
	step[0]=0;
	bfs();
}


int main(){
	int i,k,t,s,cnt=0;
	for(p[0]=i=1;i<10;i++)
		p[i]=p[i-1]*4;
	while(cin>>n>>m>>l){
		if(!n&&!m&&!l)break;
		cls(mat);
		for(i=0;i<l;i++){
			cin>>nx[i]>>ny[i];
			nx[i]--;ny[i]--;
		}
		cin>>k;
		for(i=0;i<k;i++){
			cin>>t>>s;
			mat[--t][--s]=1;
		}
		cout<<"Case "<<++cnt<<": ";
		run();
	}
	return 0;
}