#include<stdio.h>
#include<string.h>
char en[200][100];
int tot[200],m,n;
void run()
{
	int i,j,k;
	char str[100];
	for(i=0;i<m;i++)
	{
		tot[i]=0;
		for(j=0;j<n;j++)
			for(k=j+1;k<n;k++)
				if(en[i][j]>en[i][k])
					tot[i]++;
	}
	for(i=1;i<m;i++)
		for(j=0;j<m-i;j++)
			if(tot[j]>tot[j+1])
			{
				k=tot[j];
				tot[j]=tot[j+1];
				tot[j+1]=k;
				strcpy(str,en[j]);
				strcpy(en[j],en[j+1]);
				strcpy(en[j+1],str);
			}
	for(i=0;i<m;i++)
		puts(en[i]);
}
void main()
{
	int now,i,t;
	scanf("%d",&t);
	for(now=0;now<t;now++)
	{
		if(now)putchar('\n');
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		scanf("%s",en[i]);
		run();
		
	}
}