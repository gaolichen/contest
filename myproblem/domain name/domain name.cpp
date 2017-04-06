#include<iostream.h>
#include<string.h>
#include<fstream.h>
#define out cout
#define in cin

int n,cnt;
char dom[800][3],used[30],mark[30];
char mat[20][20],tmp[20][20],ret[20];
int sk[20];

int capnum(char ch){
	int i;
	for(i=0;i<cnt;i++)
		if(used[i]==ch)return i;
	return i;
}

int findcircle(int n){
	int i,j,flag,k;
	char ch;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++){
		flag=-1;ch='z'+1;
		for(j=0;j<n;j++)
			if(!mark[j]&&used[j]<ch){
				for(k=0;k<cnt;k++)
					if(tmp[k][j])break;
				if(k==cnt){
					flag=j;
					ch=used[j];
				}
			}
		if(flag==-1)return 1;
		mark[flag]=1;
		ret[i]=ch;
		for(j=0;j<n;j++)
			if(tmp[flag][j])tmp[flag][j]=0;
	}
	return ret[i]=0;
}

int check(int n){
	int i,j;
	memcpy(tmp,mat,sizeof(mat));
	for(i=0;i<n;i++){
		for(j=0;j<cnt;j++)
			if(tmp[j][sk[i]]){
				tmp[j][sk[i]]=0;
				tmp[j][cnt+i]=1;
				used[cnt+i]=used[sk[i]];
			}
	}
	if(findcircle(n+cnt))return 0;
	return 1;
}

int dfs(int k,int p,int n){
	if(p==n){
		if(check(p))return 1;
		return 0;
	}
	if(cnt-k+p<n)return 0;
	sk[p]=k;
	if(dfs(k+1,p+1,n))return 1;
	return dfs(k+1,p,n);
}


void run(){
	int i,j,k;
	for(i=cnt=0;i<26;i++)
		if(used[i]){
			used[cnt++]=i+'a';
		}
	if(cnt>12){
		out<<"impossible"<<endl;
		return ;
	}
	memset(mat,0,sizeof(mat));
	for(i=0;i<n;i++){
		j=capnum(dom[i][0]);
		k=capnum(dom[i][1]);
		mat[j][k]=1;
	}
	for(i=0;i<=12-cnt;i++)
		if(dfs(0,0,i)){
			out<<ret<<endl;
			return;
		}
	out<<"impossible"<<endl;
}

int main(){
	int i;
	for(;in>>n;run()){
		memset(used,0,sizeof(used));
		for(i=0;i<n;i++){
			in>>dom[i];
			used[dom[i][0]-'a']=1;
			used[dom[i][1]-'a']=1;
		}
		
	}
	return 0;
}
