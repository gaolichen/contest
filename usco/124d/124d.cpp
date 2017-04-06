/*
ID:  mygali1
PROG: namenum
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 2100000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("namenum.in");
ofstream out("namenum.out");
#endif

char cap[25]={'2','2','2','3','3','3','4','4','4','5','5','5',
'6','6','6','7','a','7','7','8','8','8','9','9','9'};
char name[31000][30],num[31000][30],buf[30];
int nr[31000],r[31000],rec[31000],count;
int cmp(const void *t1,const void *t2){
	return strcmp((char*)t1,(char *)t2);
}
int mycmp(const void *t1,const void *t2){
	return cmp(num[*(int*)t1],num[*(int*)t2]);
}
/*
int mcmp(const void *t1,const void *t2){
	return strcmp((char*)t1,(char *)t2);
}*/
int mmcmp(const void *t1,const void *t2){
	return strcmp(name[*(int*)t1],name[*(int*)t2]);
}
void run(){
	int i,tot;
	char *p;
	p=(char*)bsearch(buf,num,count,sizeof(num[0]),cmp);
	if(p==NULL){
		out<<"NONE"<<endl;
		return ;
	}
	i=(p-num[0])/sizeof(num[0]);
	while(i>=0&&strcmp(num[i],buf)==0)i--;
	if(strcmp(num[i],buf))i++;
	tot=0;
	while(strcmp(num[i],buf)==0)
		rec[tot++]=nr[i++];
	qsort(rec,tot,sizeof(int),mmcmp);
	for(i=0;i<tot;i++)
		out<<name[rec[i]]<<endl;
}
int main(){
	int i,len,j;
	ifstream fin("dict.txt");
	i=0;
	while(fin>>name[i])
		i++;
//	out<<i<<endl;
	qsort(name,i,sizeof(name[0]),cmp);
	count=i;
	for(i=0;i<count;i++){
		len=strlen(name[i]);
		for(j=0;j<len;j++)
			num[i][j]=cap[name[i][j]-'A'];
		num[i][j]='\0';
	}
	for(i=0;i<count;i++)nr[i]=i;
	qsort(nr,count,sizeof(int),mycmp);
	for(i=0;i<count;i++)
		r[nr[i]]=i;
	qsort(num,count,sizeof(num[0]),cmp);
	while(in>>buf)run();
	return 0;
}
