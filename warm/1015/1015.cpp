#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int con[20][2],n;
vector<int> p;
int f[(1<<18)];
int tri[18][2][2]=
{
	{{1,2},{18,18}},{{0,2},{18,18}},{{0,1},{4,5}},
	{{4,7},{18,18}},{{3,7},{2,5}},{{2,4},{6,8}},
	{{5,8},{18,18}},{{3,4},{10,11}},{{5,6},{12,13}},
	{{10,15},{18,18}},{{9,15},{7,11}},{{7,10},{12,16}},
	{{11,16},{8,13}},{{8,12},{14,17}},{{13,17},{18,18}},
	{{9,10},{18,18}},{{11,12},{18,18}},{{13,14},{18,18}}
};
int side[18][2]=
{
	{1,2},{1,3},{2,3},{2,4},{2,5},{3,5},
	{3,6},{4,5},{5,6},{4,7},{4,8},{5,8},
	{5,9},{6,9},{6,10},{7,8},{8,9},{9,10}
};


int calc(int n){
	int i,j,ret=0;
	for(i=0;i<18;i++)
		if(p[i]&n)for(j=0;j<2;j++)
			if((p[tri[i][j][0]]&n)&&(p[tri[i][j][1]]&n))
				ret++;
	return ret/3;
}
void init(){
	p.resize(20);
	int i;
	memset(f,0,sizeof(f));
	f[(1<<18)-1]=1;
	for(i=1,p[0]=1;i<18;i++)
		p[i]=p[i-1]<<1;
	p[18]=p[19]=0;
}

int dfs(int k){
	if(f[k])return f[k]-1;
	int i,tmp,h,j,t;
	tmp=calc(k);
	for(i=17;i>=0;i--)
		if(!(p[i]&k)){
			for(h=t=0;h<2;h++)
				if((p[tri[i][h][0]]&k)&&(p[tri[i][h][1]]&k))
					t++;
			j=dfs(p[i]+k);
			if(t){
				if(j+t>f[k])f[k]=j+t;
			}
			else {						
				if(9-tmp-j>f[k])
					f[k]=9-tmp-j;
			}
		}
	return f[k]++;
}

void run(){
	int i,j,k,tot=0,tnum[2],whoturn=0,flag;
	char mark[20];
	tnum[0]=tnum[1]=0;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++){
		for(j=0;j<18;j++)
			if(con[i][0]==side[j][0]&&con[i][1]==side[j][1])
				break;
		if(j==18)continue;
		tot+=p[j];
		for(k=flag=0;k<2;k++)
			if(mark[tri[j][k][0]]&&mark[tri[j][k][1]]){
				tnum[whoturn]++;
				flag=1;
			}
		if(!flag)whoturn=!whoturn;
		mark[j]=1;
	}
//	cout<<endl<<tnum[0]<<' '<<tnum[1]<<' '<<whoturn<<endl;
//	cout<<tot<<endl;
	i=tnum[whoturn]+dfs(tot);
	if(whoturn)i=9-i;
	if(i>4)cout<<"A wins."<<endl;
	else cout<<"B wins."<<endl;
//	cout<<i<<endl;
}

int main(){
	int t,tt,i,cnt,cntt=0;
	init();
	cin>>t;
	while(t--){
		if(cntt++)cout<<endl;
		cin>>tt;
		cnt=0;
		while(tt--){
			cin>>n;
			for(i=0;i<n;i++){
				cin>>con[i][0]>>con[i][1];
				if(con[i][0]>con[i][1])
					swap(con[i][0],con[i][1]);
			}
			cout<<"Game "<<++cnt<<": ";
			run();
		}
//		for(i=(1<<18)-1;i>=(1<<18)-100;i--)
//			if(f[i])cout<<(1<<18)-i<<' '<<f[i]-1<<endl;
	}
	return 0;
}