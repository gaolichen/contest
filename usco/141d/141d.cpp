/*
ID:  mygali1
PROG: cryptcow
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#define M 100000000
#define DEBUG
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("cryptcow.in");
ofstream out("cryptcow.out");
#endif

char buf[100];
char s[100]={"Begin the Escape execution at the Break of Dawn"};
char s1[100]={"BeCOgC"};
int cap[30],nt[30],nb,ne,nd,tnb,tne,tnd,length,count;
int pl[140][20],num[140];
int check(char *buf){
	int i,j;
	j=strlen(buf);
	for(i=0;i<j;i++){
		if(buf[i]=='O'||buf[i]=='W')return 0;
		if(buf[i]=='C')break;
	}
	for(i=j-1;i>=0;i--){
		if(buf[i]=='C'||buf[i]=='O')return 0;
		if(buf[i]=='W')break;
	}
	int st=0,h;
	char ch1,ch2;
	i=0;
	while(i<j&&!(buf[i]=='C'||buf[i]=='O'||buf[i]=='W')){
		if(buf[i]!=s[i])return 0;
		i++;
	}
	while(i<j&&(buf[i]=='C'||buf[i]=='O'||buf[i]=='W'))i++;
	st=i++;
	for(;i<=j;i++)
		if(buf[i]=='C'||buf[i]=='O'||buf[i]=='W'||buf[i]=='\0'){
			if(i==st){
				st++;continue;
			}
			if(i==st+1){
				st+=2;continue;
			}
			ch1=buf[i];
			buf[i]='\0';
			for(h=0;h<num[buf[st]];h++){
					ch2=s[pl[buf[st]][h]+i-st];
					s[pl[buf[st]][h]+i-st]='\0';
					if(strcmp(buf+st,s+pl[buf[st]][h])==0){
						s[pl[buf[st]][h]+i-st]=ch2;
						break;
					}
					s[pl[buf[st]][h]+i-st]=ch2;
				}
			if(h==num[buf[st]])return 0;
			st=i+1;
			buf[i]=ch1;
		}
	i=1;
	while(i<=j&&(buf[j-i]=='C'||buf[j-i]=='O'||buf[j-i]=='W')){
		if(buf[j-i]!=s[length-i])return 0;
		i++;
	}
	return 1;
}
int change(char *buf,char *temp,int c,int o,int w){
	buf[c]=buf[o]=buf[w]='\0';
	strcpy(temp,buf);
	strcpy(temp+c,buf+o+1);
	strcpy(temp+c+w-o-1,buf+c+1);
	strcpy(temp+w-2,buf+w+1);
	buf[c]='C';buf[o]='O';buf[w]='W';
	return check(temp);
}

int dfs(char *buf,int k){
	int i,j,h;
	if(k==0){
		if(!strcmp(buf,s))return 1;
		return 0;
	}
	char temp[100];
	for(i=0;i<length+3*k;i++)
		if(buf[i]=='C')
			for(j=i+1;j<length+3*k;j++)
				if(buf[j]=='O')
					for(h=j+1;h<length+3*k;h++)
						if(buf[h]=='W'&&change(buf,temp,i,j,h)){
							if(dfs(temp,k-1))return 1;
						}
	return 0;
}
void run(){
	int i,len,nc,no,nw; 
	char temp[100],ch;
	len=strlen(buf);
	nc=no=nw=0;
	for(i=0;i<len;i++){
		if(buf[i]=='O')no++;
		if(buf[i]=='C')nc++;
		if(buf[i]=='W')nw++;
	}
	if(no!=nc||nc!=nw){
		out<<0<<' '<<0<<endl;
		return ;
	}
	memset(nt,0,sizeof(nt));
	tnb=tne=tnd=0;
	for(i=0;i<len;i++){
		if(buf[i]==' ')nt[26]++;
		else if(buf[i]>='a'&&buf[i]<='z')nt[buf[i]-'a']++;
		else if(buf[i]=='B')tnb++;
		else if(buf[i]=='E')tne++;
		else if(buf[i]=='D')tnd++;
	}
	if(tnb!=nb||tne!=ne||tnd!=nd){
		out<<0<<' '<<0<<endl;
		return ;
	}
	for(i=0;i<27;i++)
		if(nt[i]!=cap[i]){
			out<<0<<' '<<0<<endl;
			return;
		}
	count=no;
	if(!check(buf)){
		out<<0<<' '<<0<<endl;
		return;
	}
	ch=buf[6];
	buf[6]='\0';
	strcpy(temp,buf);buf[6]=ch;
	if(strcmp(temp,s1)==0){
		out<<1<<' '<<count<<endl;
		return ;
	}
	if(dfs(buf,count))
		out<<1<<' '<<count<<endl;
	else out<<0<<' '<<0<<endl;
}
int main(){
	int i;
	length=strlen(s);
	memset(cap,0,sizeof(cap));
	for(i=0;i<length;i++)
		if(s[i]!='C'&&s[i]!='O'&&s[i]!='W'){
			if(s[i]==' ')cap[26]++;
			else if(s[i]>='a'&&s[i]<='z')cap[s[i]-'a']++;
		}
	nb=2;ne=1;nd=1;
	memset(num,0,sizeof(num));
	for(i=0;i<length;i++)
		pl[s[i]][num[s[i]]++]=i;
	while(in.getline(buf,100))run();
	return 0;
}