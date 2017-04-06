/*
ID:  mygali1
PROG: prime3
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 3456793
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("prime3.in");
ofstream out("prime3.out");
#endif

int ans[1000][5];
int a[5][5],sum,prime[100000],count,tot;
char mark[110000];

int check1(int k){
	int i,j=0;
	while(k){
		i=k%10;
		if(i%2==0)return 0;
		a[4-j][4]=i;
		j++;
		k/=10;
	}
	return 1;
}

int check2(int k){
	if(k%10!=a[4][4])return 0;
	int i,j=0;
//	int t=k;
	while(k){
		i=k%10;
		if(i%2==0)return 0;
		a[4][4-j]=i;
		j++;
		k/=10;
	}
//	out<<t<<endl;
//	out<<endl;
	return 1;
}

int check3(int k){
	if(k%10!=a[4][4]||k/10000!=a[0][0])return 0;
	int j=0;
	while(k){
		a[4-j][4-j]=k%10;
		k/=10;
		j++;
	}
	return 1;
}

int check4(int k){
	a[3][1]=k%10;
	a[1][3]=k/10;
	int i,s=0;
	for(i=0;i<5;i++)
		s=s*10+a[4-i][i];
	if(!mark[s])return 0;
	return 1;
}

int check5(int k){
	a[1][2]=k%10;
	a[1][0]=k/10;
	int i,s;
	for(i=s=0;i<5;i++)
		s=s*10+a[1][i];
	if(!mark[s])return 0;
	return 1;
}

int check6(int k){
	a[3][2]=k%10;
	a[3][0]=k/10;
	int i,s;
	for(i=s=0;i<5;i++)
		s=s*10+a[3][i];
	if(!mark[s])return 0;
	return 1;
}

int check7(){
	int i,s;
	a[2][0]=sum-(a[0][0]+a[1][0]+a[3][0]+a[4][0]);
	if(a[2][0]<0||a[2][0]>9)return 0;
	for(i=s=0;i<5;i++)
		s=s*10+a[i][0];
	return mark[s]?1:0;
}

int check8(){
	int i,s;
	a[0][2]=sum-(a[1][2]+a[2][2]+a[3][2]+a[4][2]);
	if(a[0][2]<0||a[0][2]>9)return 0;
	for(i=s=0;i<5;i++)
		s=s*10+a[i][2];
	return mark[s]?1:0;
}

int check9(int k){
	int i,s;
	a[2][3]=k%10;
	a[2][1]=k/10;
	for(i=s=0;i<5;i++)
		s=s*10+a[2][i];
	return mark[s]?1:0;
}

int check10(){
	a[0][1]=sum-(a[1][1]+a[2][1]+a[3][1]+a[4][1]);
	if(a[0][1]<0||a[0][1]>9)return 0;
	int i,s;
	for(i=s=0;i<5;i++)
		s=s*10+a[i][1];
	return mark[s]?1:0;
}

int check11(){
	a[0][3]=sum-(a[0][1]+a[0][2]+a[0][4]+a[0][0]);
	if(a[0][3]<0||a[0][3]>9)return 0;
	int i,s;
	for(i=s=0;i<5;i++)
		s=s*10+a[i][3];
	if(!mark[s])return 0;
	for(i=s=0;i<5;i++)
		s=s*10+a[0][i];
	return mark[s]?1:0;
}

void record(){
	int i,j,s;
	for(i=0;i<5;i++){
		for(j=s=0;j<5;j++)
			s=s*10+a[i][j];
		ans[tot][i]=s;
	}
	tot++;
}

int cmp(const void *a,const void *b){
	int i;
	for(i=0;i<5;i++)
		if(((int*)a)[i]!=((int*)b)[i])
			return ((int*)a)[i]-((int*)b)[i];
	return -1;
}
void run(){
	int i,j,k,h,l,m,n;
	tot=0;
	for(i=0;i<count;i++)
		if(check1(prime[i]))
			for(j=0;j<count;j++)
				if(check2(prime[j]))
					for(k=0;k<count;k++)
						if(check3(prime[k]))
							for(h=0;h<100;h++)
								if(check4(h))
									for(l=10;l<100;l++)
										if(check5(l))
											for(m=10;m<100;m++)
												if(check6(m))
													if(check7())
														if(check8())
															for(n=0;n<100;n++)
																if(check9(n))
																	if(check10())
																		if(check11())
																			record();
	qsort(ans,tot,sizeof(int)*5,cmp);
	if(tot==0)
		out<<"NONE"<<endl;
	else
//	out<<'\t'<<"tot["<<sum<<"]["<<a[0][0]<<"]="<<tot<<";"<<endl;
		for(i=0;i<tot;i++){
			if(i)out<<endl;
			for(j=0;j<5;j++)
//				out<<'\t'<<"ans["<<sum<<"]["<<a[0][0]<<"]["<<i<<"]["<<j<<"]="<<ans[i][j]<<";"<<endl;
				out<<ans[i][j]<<endl;
		}
}

int cut(int k){
	int ret=0;
	while(k){
		ret+=k%10;
		k/=10;
	}
	return ret;
}
void make_prime(){
	int i,j;
	memset(mark,0,sizeof(mark));
	count=0;
	for(i=2;i<=100000;i++)
		if(!mark[i]){
			if(i>10000&&cut(i)==sum)prime[count++]=i;
			for(j=i;j*i>0&&j*i<=100000;j++)
				mark[j*i]=1;
		}
	memset(mark,0,sizeof(mark));
	for(i=0;i<count;i++){
		mark[prime[i]]=1;
	}
}
int main(){
	in>>sum>>a[0][0];
//	for(sum=0;sum<=45;sum++)
//		for(a[0][0]=1;a[0][0]<=9;a[0][0]++){
//	while(cin>>sum>>a[0][0])
	{
	make_prime();
	run();
//	cout<<sum<<' '<<a[0][0]<<endl;
		}
	return 0;
}

/*
------- test 1 -------
11 2
------- test 2 -------
11 1
------- test 3 -------
17 7
------- test 4 -------
29 2
------- test 5 -------
19 8
------- test 6 -------
17 1
------- test 7 -------
19 5
------- test 8 -------
23 7
------- test 9 -------
23 1
------- test 10 -------
23 3
----------------------




*/