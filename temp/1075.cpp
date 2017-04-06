#include<stdio.h>
char card[20][10];
int check(int a,int b,int c)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(card[a][i]==card[b][i]&&card[a][i]==card[c][i])
			continue;
		else 
			if(card[a][i]!=card[b][i]&&card[a][i]!=card[c][i]&&
				card[c][i]!=card[b][i])
				continue;
		else return 0;
	}
	return 1;
}
void run()
{
	int i,j,k,tot=0;
	printf("CARDS: ");
	for(i=0;i<12;i++)
		printf(" %s",card[i]);
	printf("\nSETS:   ");
	for(i=0;i<12;i++)
		for(j=i+1;j<12;j++)
			for(k=j+1;k<12;k++)
				if(check(i,j,k))
				{
				tot++;
				if(tot!=1)
					printf("        ");
				printf("%d.  ",tot);
				printf("%s %s %s\n",card[i],card[j],card[k]);
				}
	if(!tot)
		printf("*** None Found ***\n");
}
void main()
{
	int i,tot=0;
	while(scanf("%s",card[0])==1)
	{
		if(tot)putchar('\n');
		else tot=1;
		for(i=1;i<12;i++)
			scanf("%s",card[i]);
		run();
	}
}