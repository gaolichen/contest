/*
ID:  mygali1
PROG: contact
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
ifstream in("contact.in");
ofstream out("contact.out");
#endif
int a,b,n,tot[13][1<<12],count;
char seq[2100000];
struct node{
	int val,times,len;
};
node cha[13*(1<<12)];

int calc(int s,int e){
	int ret=0;
	for(int i=s;i<e;i++){
		ret<<=1;
		if(seq[i]=='1')
			ret++;
	}
	return ret;
}
int cmp(const void *t1,const void *t2){
	if(((node*)t1)->times!=((node*)t2)->times)
		return ((node*)t2)->times-((node*)t1)->times;
	else if(((node*)t1)->len!=((node*)t2)->len)
		return ((node*)t1)->len-((node*)t2)->len;
	return ((node*)t1)->val-((node*)t2)->val;
}
void output(int val,int len){
	char temp[20];
	temp[len]=0;
	while(len-->=0){
		temp[len]=val%2+'0';
		val>>=1;
	}
	out<<temp;
}
void run(){
	int i,j,k,t;
	memset(tot,0,sizeof(tot));
	for(i=0;i<count;i++)
		for(j=a;j<=b&&i+j<=count;j++){
			k=calc(i,i+j);
			tot[j][k]++;
		}
	count=0;
	for(i=a;i<=b;i++)
		for(j=0;j<(1<<i);j++)
		if(tot[i][j]){
			cha[count].val=j;
			cha[count].times=tot[i][j];
			cha[count++].len=i;
		}
	qsort(cha,count,sizeof(node),cmp);
	j=cha[0].times;t=0;k=1;
	out<<j<<endl;
	for(i=0;i<count;i++){
		if(cha[i].times!=j){
			k++;
			if(k>n)break;
			out<<endl;
			j=cha[i].times;
			out<<j<<endl;
			output(cha[i].val,cha[i].len);
			t=1;
		}
		else{
			if(t==6){
				t=0;
				out<<endl;
			}
				if(t)out<<' ';
				output(cha[i].val,cha[i].len);
				t++;
		}
	}
	out<<endl;
}
int main(){
	char buf[100];
	int len;
	while(in>>a>>b>>n){
		count=0;
		while(1){
			in>>buf;
			len=strlen(buf);
			strcpy(seq+count,buf);
			count+=len;
			if(len<80)break;
		}
		run();
	}
	return 0;
}