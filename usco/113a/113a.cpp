
/*
ID:  mygali1
PROG: milk
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
ifstream in("milk.in");
ofstream out("milk.out");
#endif

struct node{
	int p,a;
}farm[5001];
int n,m;
int cmp(const void *t1,const void *t2){
	return ((node*)t1)->p-((node*)t2)->p;
}
void run(){
	qsort(farm,n,sizeof(int)*2,cmp);
	int i,ans=0,tot=0;
	for(i=0;i<n;i++){
		if(tot+farm[i].a<m){
			ans+=farm[i].p*farm[i].a;
			tot+=farm[i].a;
		}
		else {
			ans+=farm[i].p*(m-tot);
			tot=m;
			break;
		}
	}
	out<<ans<<endl;
}
int main(){
	int i;
	while(in>>m>>n){
		for(i=0;i<n;i++)
			in>>farm[i].p>>farm[i].a;
		run();
	}
	return 0;
}