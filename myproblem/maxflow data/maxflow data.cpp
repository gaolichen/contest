#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>

using namespace std;

#define cout out
ofstream out("output.txt");

double randdbl(){
	return (double)abs(rand())/RAND_MAX;
}

struct pa{
	int i,j;
};

int main(){
	int i,j,k;
	double t;
	pa tp;
	vector< pa > vp; 
	for(i=10;i<=30;i++){
		for(t=0.5;t<1.01;t+=0.1){
			vp.clear();
			for(j=0;j<i;j++)
				for(k=j+1;k<i;k++)
					if(randdbl()<=t){
						tp.i=j;
						tp.j=k;
						vp.push_back(tp);
					}
			cout<<i<<' '<<vp.size()<<endl;
			for(j=0;j<vp.size();j++)
				cout<<vp[j].i<<' '<<vp[j].j<<endl;
			cout<<endl;
		}
	}
	return 0;
}