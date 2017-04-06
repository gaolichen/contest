#include<stdio.h>
#include<string.h>
int n,piz[17];
char ned[1000][500];
int check()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;ned[i][j]!=';';j+=2)
		{
			if(ned[i][j]=='+'&&piz[ned[i][j+1]-'A'])
					break;
			if(ned[i][j]=='-'&&!piz[ned[i][j+1]-'A'])
				break;
		}
		if(ned[i][j]==';')
			return 0;
	}
	return 1;
}
void print()
{
	int i;
	printf("Toppings: ");
	for(i=0;i<16;i++)
		if(piz[i])
			printf("%c",i+'A');
	putchar('\n');
}
void run()
{
	int i;
	memset(piz,0,sizeof(piz));
	if(check())
	{
		printf("Toppings:\n");
		return;
	}
	while(!piz[16])
	{
		i=0;while(piz[i])
		{piz[i]=0;i++;}
		piz[i]=1;
		if(check())
		{
			print();
			return;
		}
	}
	printf("No pizza can satisfy these requests.\n");
}
void main()
{
	while(scanf("%s",ned[0])==1)
	{
	n=0;
	while(ned[n][0]!='.')
		scanf("%s",ned[++n]);
	run();
	}
}