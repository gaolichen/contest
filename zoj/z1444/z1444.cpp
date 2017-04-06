#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int n,ttime,pro,pt[10000][101],cnt,sol[10000],tot[10000],r[10000];
char buf[40],rep[10],name[10000][31];
/*
int mybsearch(){
	int top,mid,low,t1;
	top=cnt-1;low=0;
	if(strcmp(buf,name[0])<=0)return 0;
	if(strcmp(buf,name[cnt-1])>=0)return cnt;
	mid=(top+low)/2;
	while(mid>low){
		t1=strcmp(buf,name[mid]);
		if(t1==0)return mid;
		else if(t1<0)top=mid;
		else low=mid;
		mid=(top+low)/2;
	}
	if(strcmp(name[mid],buf)==0)return mid;
	if(strcmp(name[top],buf)==0)return top;
	return mid;
}*/
map <string,int> a;
void init(){
	string s;
	s=buf;
	if(a.find(s)==a.end()){
		a[s]=a.size();
//		printf("%d\n",a[s]);
		strcpy(name[a[s]],buf);
	}
//	for(i=0;i<cnt;i++)
//		if(strcmp(buf,name[i])==0)break;
/*	if(!cnt)strcpy(name[cnt++],buf);
	i=mybsearch();
	j=strcmp(buf,name[i]);
	if(j){
		if(j>0)i++;
		for(j=cnt;j>i;j--)
			strcpy(name[j],name[j-1]);
		strcpy(name[j],buf);
	}*/
	if(rep[0]=='A'){
		if(pt[a[s]][pro]<=0)
			pt[a[s]][pro]=abs(pt[a[s]][pro])+ttime;
		else;
	}
	else if(pt[a[s]][pro]<=0)
		pt[a[s]][pro]-=20;
}



int cmp(int i,int j){
//	int i,j;
//	i=*(int*)a;j=*(int*)b;
	if(sol[i]!=sol[j])return sol[i]>sol[j];
	if(tot[i]!=tot[j])return tot[i]<tot[j];
	int k;
	char ch1,ch2;
	for(k=0;name[i][k]&&name[j][k];k++){
		ch1=name[i][k];
		ch2=name[j][k];
		if(ch1<'a')ch1=ch1+'a'-'A';
		if(ch2<'a')ch2=ch2+'a'-'A';
		if(ch1!=ch2)return ch2>ch1;
	}
	return name[i][k]==0;
}
void run(){
	int i,j;
	cnt=a.size();
	for(i=0;i<a.size();i++){
		sol[i]=0;tot[i]=0;
		for(j=1;j<=n;j++)
			if(pt[i][j]>0){
				sol[i]++;
				tot[i]+=pt[i][j];
			}
		r[i]=i;
	}
//	qsort(r,a.size(),sizeof(int),cmp);
	sort(r,r+cnt,cmp);
	for(i=0;i<cnt;i++){
		if(!sol[r[i]])break;
		if(i&&sol[r[i]]==sol[r[i-1]]&&tot[r[i]]==tot[r[i-1]])
			printf("          ");
		else printf("%-10d",i+1);
		printf("%-30s%-10d%d",name[r[i]],sol[r[i]],tot[r[i]]);
		printf("\n");
	}
}
int main(){
	cnt=0;
//	cout<<'a'-'A'<<endl;
	scanf("%d",&n);
	memset(pt,0,sizeof(pt));
	while(scanf("%d%s%d%s",&ttime,buf,&pro,rep)==4)
		init();
	run();
	return 0;
}