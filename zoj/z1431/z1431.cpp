#include<iostream.h>
#include<string.h>
#include<stdlib.h>

int r[30],w[30],n;
char name[30][30];

int cmp(const void *a,const void *b){
	return w[*(int*)b]-w[*(int*)a];
}
void run(){
	int i;
	for(i=0;i<n;i++)
		r[i]=i;
	qsort(r,n,sizeof(int),cmp);
	for(i=0;i<n;i++)
		cout<<name[r[i]]<<endl;

}

int main(){
	char buf[100];
	int i,j,cnt=0;
	while(cin>>buf){
		n=0;
		while(1){
			cin>>name[n];
			if(strcmp(name[n],"END")==0)break;
			cin>>i>>j;
			w[n]=j-i;
			n++;
		}
		if(cnt++)cout<<endl;
		run();
	}
	return 0;
}