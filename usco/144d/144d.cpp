/*
ID:  mygali1
PROG: msquare
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 2100000000
#define MAXN 110
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("msquare.in");
ofstream out("msquare.out");
#endif

int cls,opn,sk[50000][2],a[8],gol[2],op[50000],pre[50000];
int rec[1000],tmp[8];
int p[9]={1,1,2,6,24,120,720,5040,40320};
char mark[387839+1];

//p[]是1到n的一个排列，返回此排列是第几个排列，1到n的顺序排列为第1排列
//调用 nfactor
int ranknum(int n,int *a){
	int i,j,mark[10],k,ans;
	memset(mark,0,sizeof(int)*(n+1));
	for(i=0,ans=0;i<n;i++)
	{
		for(j=1,k=0;j<a[i];j++)
			if(!mark[j])k++;
		ans+=p[n-i-1]*k;
		mark[a[i]]=1;
	}
	return ans+1;
}

int hash(int a,int b){
	int i;
	for(i=0;i<4;i++){
		tmp[i]=a%10;
		a/=10;
	}
	for(i=4;i<8;i++){
		tmp[i]=b%10;
		b/=10;
	}
	return ranknum(8,tmp);
}
int check(int a,int b,int k){
	int i;
	if(k==0){
		i=hash(b,a);
		if(mark[i])return 0;
		mark[i]=1;
		sk[++cls][0]=b;
		sk[cls][1]=a;
		op[cls]=k;
		pre[cls]=opn;
		return gol[0]==b&&gol[1]==a?1:0;
	}
	if(k==1){
		a=a/10+(a%10)*1000;
		b=b/10+(b%10)*1000;
		i=hash(a,b);
		if(mark[i])return 0;
		mark[i]=1;
		sk[++cls][0]=a;
		sk[cls][1]=b;
		op[cls]=k;
		pre[cls]=opn;
		return gol[0]==a&&gol[1]==b?1:0;
	}
	if(k==2){
		i=a;
		a=a-i%1000+i%10+((b/100)%10)*100+((a/100)%10)*10;
		b=b-b%1000+b%10+((b/10)%10)*100+((i/10)%10)*10;
		i=hash(a,b);
		if(mark[i])return 0;
		mark[i]=1;
		sk[++cls][0]=a;
		sk[cls][1]=b;
		op[cls]=k;
		pre[cls]=opn;
		return gol[0]==a&&gol[1]==b?1:0;
	}
	return 0;
}

void run(){
	int i;
	sk[opn=cls=0][0]=1234;
	sk[0][1]=8765;
	if(gol[0]==sk[0][0]&&gol[1]==sk[0][1]){
		out<<0<<endl;
		out<<endl;
		return ;
	}
//	out<<gol[0]<<' '<<gol[1]<<endl;
	memset(mark,0,sizeof(mark));
	mark[hash(sk[0][0],sk[0][1])]=1;
	op[0]=-1;
	pre[0]=-1;
	while(opn<=cls){
		for(i=0;i<3;i++){
			if(check(sk[opn][0],sk[opn][1],i))
				break;
		}
		if(i<3)break;
		opn++;
	}
	i=0;
	while(pre[cls]!=-1){
		rec[i++]=op[cls];
		cls=pre[cls];
	}
	out<<i<<endl;
	int j;
	for(j=0;j<i;j++){
		if(j&&j%60==0)out<<endl;
		out<<char(rec[i-j-1]+'A');
	}
	out<<endl;
}

int main(){
	int i,j=1;
	gol[0]=gol[1]=0;
	for(i=0;i<4;i++){
		in>>a[i];
		gol[0]=gol[0]*10+a[i];
	}
	for(;i<8;i++){
		in>>a[i];
		gol[1]+=a[i]*j;
		j*=10;
	}
	run();
	return 0;
}