/*
ID:  mygali1
PROG: sort3
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("sort3.in");
ofstream out("sort3.out");
#endif

int a[2000],b[2000],n;
char mark[2000];
int cmp(const void *t1,const void *t2){
	return *(int*)t1-*(int*)t2;
}
void run(){
	int i,j,k,count;
	qsort(b,n,sizeof(int),cmp);
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		if(a[i]==b[i])mark[i]=1;
	for(i=j=0;i<n;i++)
		if(!mark[i]){
			a[j]=a[i];
			b[j++]=b[i];
		}
	n=j;	
	memset(mark,0,sizeof(mark));
	count=0;
	for(i=0;i<n;i++)
		if(!mark[i]){
			for(j=i+1;j<n;j++)
				if(!mark[j]&&a[j]==b[i]&&b[j]==a[i]){
					mark[j]=1;
					count++;break;
				}
			if(j<n)mark[i]=1;
		}
	for(i=j=0;i<n;i++)
		if(!mark[i]){
			a[j]=a[i];
			b[j++]=b[i];
		}
	n=j;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		if(!mark[i])
			for(j=i+1;j<n;j++)
				if(!mark[j]&&a[j]==b[i]){
					for(k=0;k<n;k++)
						if(!mark[k]&&a[k]==b[j]){
							mark[i]=mark[j]=mark[k]=1;
							count+=2;
							break;
						}
						if(k<n)break;
				}
	out<<count<<endl;
}

int main(){
	int i;
	while(in>>n){
		for(i=0;i<n;i++){
			in>>a[i];
			b[i]=a[i];
		}
		run();
	}
	return 0;
}

