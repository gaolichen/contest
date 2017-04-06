#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TicTacToe3D{
public:
	int howMany(int n){
		if(n==1)return 1;
		return 3*n*n+6*n+4;
	}
};

int main(){
	int n;
	TicTacToe3D a;
	while(cin>>n){
		cout<<a.howMany(n)<<endl;
	}
	return 0;
}