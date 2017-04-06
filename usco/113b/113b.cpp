/*
ID:  mygali1
PROG: barn1
*/

#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("barn1.in");
ofstream out("barn1.out");
#endif
int f[100][300];
char mark[100][300];
int m,s,c,a[300];
int cmp(const void *t1,const void *t2){
	return *(int*)t1-*(int*)t2;
}
void run(){
	int i,count=0,ans=0,j,k;
	memset(f,0,sizeof(f));
	memset(mark,0,sizeof(mark));
	qsort(a+1,c,sizeof(int),cmp);
	mark[0][0]=1;
	for(i=0;i<m;i++){
		for(j=0;j<c;j++)
			if(mark[i][j])
				for(k=j+1;k<=c;k++)
					if(!mark[i+1][k]||f[i+1][k]>f[i][j]+a[k]-a[j+1]+1){
						f[i+1][k]=f[i][j]+a[k]-a[j+1]+1;
						mark[i+1][k]=1;
					}
	}
	int min=f[1][c];
	for(i=1;i<=m;i++)
		if(mark[i][c]&&f[i][c]<min)min=f[i][c];
	out<<min<<endl;
}
int main(){
	int i;
	while(in>>m>>s>>c){
		for(i=1;i<=c;i++)
			in>>a[i];
		run();
	}
	return 0;
}