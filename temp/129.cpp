#include<stdio.h>
#define N 100
int a[N],pop;
int check()
{
	int i,j;
	for(i=pop-1;i>=pop/2;i--)
		if(a[i]==a[pop])
		{
		  for(j=pop-1;j>i;j--)
			  if(a[j]!=a[i-pop+j])
				  break;
		     if(j==i)
				 return 0;
		}
	return 1;
}
void main()
{
	int i,n,m,count;
	scanf("%d%d",&n,&m);
	while(n!=0&&m!=0)
	{
		for(i=0;i<n;i++)
			a[i]=0;
		pop=0;
		count=1;
		i=0;
		while(count<n)
		{
			if(i==m)
			{
				i=a[pop]+1;
				pop--;
			}
			else 
			{
				a[++pop]=i;
				if(!check())
				{
					pop--;
					i++;
				}
				else
				{
					count++;
					i=0;
				}
			}
		}
		count=1;
		for(i=0;i<pop+1;i++)
		{
			if(i&&i%4==0)
			{
				if(count==16)
				printf("\n");
				else printf(" ");
				count++;	
			}
			printf("%c",a[i]+'A');
		}
		printf("\n%d\n",pop+1);
		scanf("%d%d",&n,&m);
	}
}
