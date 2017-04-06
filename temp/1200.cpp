#include<iostream.h>
#include<math.h>
#include<stdio.h>
double a,b;
int k;
void run()
{
	int i,j;
	i=(int)(a*0.5);
	j=(int)(b*0.5);
	if((i+1)*a-(i+1)*(i+1)>i*a-i*i)i++;
	if((j+1)*b-(j+1)*(j+1)>j*b-j*j)j++;
	if(a<0)i=0;
	if(b<0)j=0;
	if(k>i+j)k=i+j;
	if(k==i+j)
	{
		printf("%.2lf\n",i*a+j*b-i*i-j*j);
		printf("%d %d\n",i,j);
		return ;
	}
	if(i==0)
	{
		printf("%.2lf\n",k*b-k*k);
		printf("%d %d\n",0,k);
		return ;
	}
	if(j==0)
	{
		printf("%.2lf\n",k*a-k*k);
		printf("%d %d\n",k,0);
		return ;
	}
	if(2*k-b+a<=0)i=0;
	else i=(int)((2*k-b+a)*0.25);
	j=k-i;
	if(j<0)
	{
		j=0;
		i=k;
	}
	if(j>0)
		if((i+1)*a+(j-1)*b-(i+1)*(i+1)-(j-1)*(j-1)>i*a+j*b-i*i-j*j)
		{
			i++;j--;
		}
	printf("%.2lf\n",i*a+b*j-i*i-j*j);
	printf("%d %d\n",i,j);
}
int main()
{
	while(cin>>a>>b>>k)
		run();
	return 0;
}