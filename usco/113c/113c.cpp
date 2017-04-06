/*
ID:  mygali1
PROG: clock
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
ifstream in("clock.in");
ofstream out("clock.out");
#endif
char num[20][20]={"twelve","one","two","three","four","five","six","seven",
"eight","nine","ten","eleven","twelve","thirteen","fourteen",
"fifteen","sixteen","seventeen","eighteen","nineteen"};
char tennum[6][20]={"zero","ten","twenty","thirty","forty","fifty"};
int h,min;

void output(int k,int t){
	char buf[30];
	int len;
	if(k<20)strcpy(buf,num[k]);
	else{
		if(k%10==0)
			strcpy(buf,tennum[k/10]);
		else{
			strcpy(buf,tennum[k/10]);
			len=strlen(buf);
			buf[len]='-';
			strcpy(buf+len+1,num[k%10]);
		}
	}
	if(t)buf[0]=buf[0]+'A'-'a';
	out<<buf;
}
void run(){
	char temp[20];
	if(min==0){
		strcpy(temp,num[h]);
		temp[0]=temp[0]+'A'-'a';
		out<<temp<<' '<<"o'clock"<<endl;
		return ;
	}
	if(min==15){
		strcpy(temp,num[h]);
		out<<"Quarter past "<<temp<<endl;
		return ;
	}
	if(min==30){
		strcpy(temp,num[h]);
		temp[0]=temp[0]+'A'-'a';
		out<<temp<<' '<<"thirty"<<endl;
		return ;
	}
	if(min==45){
		strcpy(temp,num[(h+1)%12]);
		out<<"Quarter to "<<temp<<endl;
		return ;
	}
	if(min<45){
		strcpy(temp,num[h]);
		temp[0]=temp[0]+'A'-'a';
		out<<temp<<' ';
		output(min,0);
		out<<endl;
		return;
	}
	if(min>45){
		strcpy(temp,num[(h+1)%12]);
		output(60-min,1);
		out<<" to "<<temp<<endl;
	}
}
int main(){
	char ch;
	while(in>>h>>ch>>min){
		run();
	}
	return 0;
}