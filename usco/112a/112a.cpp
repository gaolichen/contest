/*
ID:  mygali1
PROG: beads
*/

#include<iostream.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("beads.in");
ofstream out("beads.out");
#endif

int n;
char buf[10000],temp[10000];
void run(){
	int i,j,len,max=1,get[2],tk[2],t1,t2,k;
	char ch[2];
	len=strlen(buf);
	strcpy(temp,buf);
	strcpy(buf+len,temp);
//	out<<buf<<endl;
	for(i=0;i<len;i++){
		if(buf[i]=='w'){
			ch[0]='r';
			ch[1]='b';
		}
		else ch[0]=ch[1]=buf[i];
		get[0]=get[1]=0;
		for(j=0;j<2;j++){
			for(k=i;k<i+len;k++){
				if(buf[k]!='w'&&buf[k]!=ch[j])break;
				get[j]++;
			}
			tk[j]=k;
		}
		t1=get[0];t2=tk[0];
		if(t1<get[1]){
			t1=get[1];
			t2=tk[1];
		}
		if(buf[i+len-1]=='w'){
			ch[0]='r';
			ch[1]='b';
		}
		else ch[0]=ch[1]=buf[i+len-1];
		get[0]=get[1]=0;
		for(j=0;j<2;j++){
			for(k=i+len-1;k>=t2;k--){
				if(buf[k]!='w'&&buf[k]!=ch[j])break;
				get[j]++;
			}
		}
		if(get[0]>=get[1])t1+=get[0];
		else t1+=get[1];
		if(t1>max)max=t1;
	}
	out<<max<<endl;
}
int main(){
	while(in>>n){
		in>>buf;
		run();
	}
	return 0;
}