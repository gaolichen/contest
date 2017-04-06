#include<stdio.h>
#include<math.h>
void main(){
	long k,n;
	int i,j;
	while(scanf("%ld",&k)==1){
	n=sqrt(2*k);
	while(n*(n+1)>=2*k)n--;
	i=(int)n;
	if(i%2==0)
		j=(i+1)*(i+2)/2-(int)k+1;
	else j=(int)k-(i+1)*i/2;
	printf("\nTERM %ld IS %d/%d",k,j,i+2-j);
	}
}
