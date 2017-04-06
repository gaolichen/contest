#include<iostream>
#include<cstring>
using namespace std;

class  MultiSum{
public:
	int getCount(int b,int x,int y){
		int i,j,count=0;
		char mark[2000];
		memset(mark,0,sizeof(mark));
		for(i=1;i*x<b;i++)
			for(j=1;j*y+i*x<=b;j++)
				mark[i*x+j*y]=1;
		for(i=1;i<=b;i++)
			if(mark[i])count++;
		return count;
	}
};