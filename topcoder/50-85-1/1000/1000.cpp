#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//typedef long long T;
typedef int T;
class PrizeAward{
public:
	int p,total,sk[20];
	T ret,c[20][20];
	void calc(int k){
		int i,j=total;
		T ans=1;
		for(i=0;i<k;i++){
//			cout<<sk[i]<<' ';
			ans*=c[j][sk[i]];
			j-=sk[i];
		}
//		cout<<endl;
		ret+=ans;
	}
	void cc(){
		int i,j;
		for(i=0;i<=15;i++){
			c[0][i]=0;
			c[i][0]=1;
		}
		for(i=1;i<=15;i++)
			for(j=1;j<=15;j++){
				if(j>i)c[i][j]=0;
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
	}
	void dfs(int prize,int n){
		if(n==total||prize==p||n>=p){
			calc(prize);
			return ;
		}
		for(int i=1;i+n<=total;i++){
			sk[prize]=i;
			dfs(prize+1,n+i);
		}
	}
	T numWays(int prize,int n){
		ret=0;
		p=prize;
		total=n;
		cc();
		dfs(0,0);
		return ret;
	}
};

int main(){
	PrizeAward temp;
	int n,m;
//	n=1;m=2;
//	n <=? m;
//	cout<<n<<' '<<m;
	while(cin>>n>>m){
		cout<<temp.numWays(n,m)<<endl;
	}
	return 0;
}