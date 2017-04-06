#include<iostream.h>
#include<string.h>
#define MAXN 100

//判断字符串a和b是否同构
int samestring(char *a,char *b){
	unsigned int len;
	if((len=strlen(a))!=strlen(b))return 0;
	unsigned i,j,k;
	char aa[MAXN*2],bb[MAXN*2];
	strcpy(aa,a);
	strcpy(aa+len,a);
	strcpy(bb,b);
	strcpy(bb+len,b);
	for(i=j=k=0;i<len&&j<len;){
		while(k<len&&aa[i+k]==bb[j+k])k++;
		if(k==len)return 1;
		if(aa[i+k]>bb[j+k])i+=k+1;
		else j+=k+1;
		k=0;
	}
	return 0;
}

int main(){
	char buf1[MAXN],buf2[MAXN];
	while(cin>>buf1>>buf2)
		cout<<samestring(buf1,buf2)<<endl;
	return 0;
}