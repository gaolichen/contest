#include<iostream.h>
#include<math.h>
#include<fstream.h>
#define esp 1e-2

//ifstream in("circle.in");
//ofstream out("circle.out");

double a,b,r[2];

void run1(){
	double ret;
	ret=sqrt((a-r[1]-r[0])*(a-r[1]-r[0])+(b-r[1]-r[0])*(b-r[1]-r[0]));
	if(r[0]+r[1]<ret+esp)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main(){
	while(cin>>a>>b>>r[0]>>r[1]){
		run1();
	}
	return 0;
}
