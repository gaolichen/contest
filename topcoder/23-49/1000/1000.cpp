#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class SuperQueen{
public:
	int ans,row[20],qu[20],total;
	int check(int queen,int r){
		int i;
		for(i=0;i<queen;i++){
			if(i+qu[i]==r+queen)return 0;
			if(i-qu[i]==queen-r)return 0;
			if(abs(i-queen)==2&&abs(qu[i]-r)==1)return 0;
			if(abs(i-queen)==1&&abs(qu[i]-r)==2)return 0;
		}
		return 1;
	}
	void dfs(int queen){
		if(queen==total){
			ans++;return ;
		}
		for(int i=0;i<total;i++)
			if(!row[i]&&check(queen,i)){
				row[i]=1;
				qu[queen]=i;
				dfs(queen+1);
				row[i]=0;
			}
	}
	int getCount(int n){
		memset(row,0,sizeof(row));
		total=n;
		ans=0;
		dfs(0);
		return ans;
	}
};

int main(){
	SuperQueen a;
	int n;
	while(cin>>n){
		cout<<a.getCount(n)<<endl;
	}
	return 0;
}