/*
ID:  mygali1
PROG: heritage
*/
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
//#define DEBUG
#define M 1000000000
#ifdef DEBUG
#define in cin
#define out cout
#else 
ifstream in("heritage.in");
ofstream out("heritage.out");
#endif

struct node{
	int pre,left,right;
};
node tree[100];
char mid[100],pre[100];

void creattree(char *mid,char *pre,int len){
	int i;
	if(len==0)
		return ;
	for(i=0;i<len;i++)
		if(mid[i]==pre[0])break;
	if(mid[0]!=pre[0]){
		tree[pre[0]-'A'].left=pre[1]-'A';
		tree[pre[1]-'A'].pre=pre[0]-'A';
		creattree(mid,pre+1,i);
	}
	if(i!=len-1){
		tree[pre[0]-'A'].right=pre[i+1]-'A';
		tree[pre[i+1]-'A'].pre=pre[0]-'A';
		creattree(mid+i+1,pre+i+1,len-i-1);
	}
}
void dfs(int k){
	if(tree[k].left==-1&&tree[k].right==-1){
		out<<char(k+'A');
		return ;
	}
	if(tree[k].left!=-1)
		dfs(tree[k].left);
	if(tree[k].right!=-1)
		dfs(tree[k].right);
	out<<char(k+'A');
}
void run(){
	int len,i;
	len=strlen(mid);
	if(len==1){
		out<<mid<<endl;
		return ;
	}
	for(i=0;i<26;i++)
		tree[i].pre=tree[i].left =tree[i].right=-1;
	creattree(mid,pre,len);
	for(i=0;i<26;i++)
		if(tree[i].pre==-1&&(tree[i].right!=-1||tree[i].left!=-1))break;
	dfs(i);
	out<<endl;
}
int main(){
	while(in>>mid>>pre)run();
	return 0;
}