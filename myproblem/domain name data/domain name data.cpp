#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int n,i;
	ofstream cout("output.txt");
	srand(time(NULL));
	for(n=0;n<=100;n++){
		cout<<10<<endl;
		for(i=0;i<10;i++){
			if(i)cout<<' ';
			cout<<rand()%6+1;
		}
		cout<<endl;
	}
	return 0;
}