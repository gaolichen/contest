#include <iostream>
using namespace std;

const int MAX=200;

//joseph模拟,传入人数n,每次数的人数k,返回最后一个人的序号1..n

int joseph(int n,int k){
	int ret=-1,i;
	for (i=1;i<=n;i++)
		ret=(ret+k)%i;
	return ret+1;
}
/*
int main(){
	int n,i;
	while(cin>>n){
		if(!n)break;
		if(n>150)cout<<"wuwu"<<endl;
		for(i=1;;i++)
			if(joseph(n-1,i)==1)break;
		cout<<i<<endl;
	}
	return 0;
}*/


int main(){
    int use[MAX],n,m,i,j,k;
	int flag;
    bool check[MAX];
	n=1;
    do{
		cin>>n;
//		if(++n>150)break;
        if(!n) break;
		if(n>150){
			cout<<use[MAX+10]<<endl;
			return 1;
		}
		for(flag=1;;flag++)
			if(joseph(n-1,flag)==1)break;
//			cout<<flag<<' ';
        m=1;
        while(1){
            for(i=1;i<=n;i++){
                use[i]=0;
                check[i]=false;
            }
            use[1]=1;
            check[1]=true;
            for(k=2;k<=n;k++){
                j=use[k-1]+1;
//				if(j>n)j-=n;
                for(i=1;i<m;i++){
                    if(check[j]) i--;
                    j++;
                    if(j>n) j-=n;
                }
                while(check[j]){
                    j++;
                    if(j>n) j-=n;
                }
                use[k]=j;
                check[j]=true;
                if(j==2)break;
            }
            if(k==n)break;
            m++;
        }
		if(m!=flag){
			while(1);
			break;
		}
        cout<<m<<endl;
		
    }while(1);
	return 0;
}
