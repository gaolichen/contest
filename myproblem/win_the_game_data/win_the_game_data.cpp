#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;

int main(){
	int i,j,k;
	ofstream cout("test.in");
	srand(time(NULL));
	for(i=4;i<=4;i++){
		for(j=2;j<=250;j++){
			cout<<i*j<<endl;
			for(k=0;k<i*j;k++)
				cout<<rand()%i<<' ';
			cout<<endl;
		}
	}
	return 0;
}