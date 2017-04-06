#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<cstdlib>
#define MAXN 100
#define MAXN_HASH 500000

using namespace std;

//#define TEST

#ifdef TEST
#define cin in
#define cout out
ifstream in("input.txt");
ifstream in1("output1.txt");
ofstream out("output.txt");
#endif


struct NODE{
	int checkvalue;
	int flag;
};

NODE hash[MAXN_HASH];
int n,m,data[110];
int vi[60][200];
int a[110];

int gethash(int k,int s,int e,int &tot){
	int i,ret=0;
	for(i=s,tot=0;i<e;i++){
		ret+=data[vi[k][i]-m];
		tot+=data[vi[k][i]-m+50];
	}
	ret%=MAXN_HASH;
	return abs(ret);
}

int dfs(int k,int s,int e){
	if(s==e)return 0;
	int hashnum,tot;
	hashnum=gethash(k,s,e,tot);
	if(hash[hashnum].checkvalue==tot)return hash[hashnum].flag;
	memcpy(vi+k+1,vi[k]+s,sizeof(int)*(e-s));
	int i,j,en=e-s;
	for(i=0;i<e-s;i++){
		for(j=0;j+j+m<=vi[k][i+s];j++){
			if(j>=m)vi[k+1][en++]=j;
			if(vi[k][i+s]-m-j>=m)vi[k+1][en++]=(vi[k][i+s]-m-j);
			if(!dfs(k+1,i+1,en)){
				hash[hashnum].checkvalue=tot;
				return hash[hashnum].flag=1;
			}
			if(j>=m)en--;
			if(vi[k][i+s]-m-j>=m)en--;
		}
		vi[k+1][en++]=vi[k][i+s];
	}
	hash[hashnum].checkvalue=tot;
	return hash[hashnum].flag=0;
}

void mysearch(){
	int i=0,j;
	for(j=0;j<n;j++)
		if(a[j]>=m)
			vi[0][i++]=a[j];
//	char tmp[100];
//	in1>>tmp;
	j=dfs(0,0,i);
//	if(j&&tmp[0]!='Y'||!j&&tmp[0]=='Y'){
//		cout<<n<<' '<<tmp<<endl;
//		for(i=0;i<n;i++)cout<<a[i]<<' ';
//		cout<<endl;
//	}
//	else 
	cout<<(j?"Yes":"No")<<endl;
};


void inithash(){
	int i;
	srand(time(NULL));
	for(i=0;i<100;i++)
		data[i]=abs(rand());
}

int main(){
	int i ;
	inithash() ;
	m = 2;
	memset(hash , 0 , sizeof(hash));
	while(cin>>n){
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		mysearch();
	}
	return 0;
}
