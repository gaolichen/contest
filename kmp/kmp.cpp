#include<iostream.h>
#include<string.h>
#define MAXN 1000
#define T char
#define match(a,b) ((a)==(b))

//kmpÄ£Ê½Æ¥ÅäËã·¨
int kmp(T *s,int ls,T *p,int lp){
	int i,j;
	int nxt[MAXN];
	for(nxt[i=0]=j=-1;i<lp;){
//		if(j==-1||match(s[i],p[j]))
//			nxt[++i]=++j;
//		else j=nxt[j];
		j==-1||match(s[i],p[j])?(nxt[++i]=++j):(j=nxt[j]);
	}
	for(i=j=0;i<ls&&j<lp;){
//		if(j==-1||match(s[i],p[j]))
//			i++,j++;
//		else j=nxt[j];
		j==-1||match(s[i],p[j])?(++i,++j):(j=nxt[j]);
	}
	return j==lp?i-lp:-1;
}

int main(){
	char buf1[MAXN],buf2[MAXN];
	for(;cin>>buf1>>buf2;cout<<kmp(buf1,strlen(buf1),buf2,strlen(buf2))<<endl);
	return 0;
}