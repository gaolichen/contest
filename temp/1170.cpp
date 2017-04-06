#include<stdio.h>
#include<string.h>
char w[2][1000];
int gc(int a,int b)
{
	int temp;
	if(a<b)
	{
		temp=a,a=b;b=temp;
	}
	while(b)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
void run()
{
	int i,j,len1,len2,len,tot,max=0;
	len1=strlen(w[0]);
	len2=strlen(w[1]);
	for(i=0;i<len1;i++)
	{
		tot=0;
		for(j=0;j<len1-i&&j<len2;j++)
			if(w[0][i+j]==w[1][j])tot++;
		if(tot>max)
			max=tot;
	}
	for(i=0;i<len2;i++)
	{
		tot=0;
		for(j=0;j<len2-i&&j<len1;j++)
			if(w[1][i+j]==w[0][j])
				tot++;
		if(tot>max)
			max=tot;
	}
	printf("appx(%s,%s) = ",w[0],w[1]);
	len=len1+len2;
	max*=2;
	if(max)
	{
		i=gc(len,max);
		max/=i;
		len/=i;
	if(max!=len)
		printf("%d/%d\n",max,len);
	else printf("1\n");
	}
	else printf("0\n");
}
void main()
{
	scanf("%s",w[0]);
	while(w[0][0]!='-')
	{
		scanf("%s",w[1]);
		run();
		scanf("%s",w[0]);
	}
}