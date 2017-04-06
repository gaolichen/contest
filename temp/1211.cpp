#include<stdio.h>
#include<string.h>
char rq[10000][50],cmd[50],sub[50];
int count,cuur,pre[10000],mark[6000];
void run()
{
	int i,j,tot,t;
	printf("Command: ");
	if(cmd[0]=='m'||cmd[0]=='c')
		printf("%-8s",cmd);
	else printf("%s",cmd);
	if(cmd[0]=='c'||cmd[0]=='m')
	{
		scanf("%s",sub);
		printf("%s",sub);
	}
	printf("\n");
	if(cmd[0]=='d')
	{

		printf("Directory of root");
		tot=0;j=cuur;
		while(pre[j]!=-1)
		{
			mark[tot++]=j;
			j=pre[j];
		}
		for(j=tot-1;j>=0;j--)
			printf("\\%s",rq[mark[j]]);
		printf(":\n");
		tot=0;
		for(j=0;j<count;j++)
			if(pre[j]==cuur)
				mark[tot++]=j;
		for(i=1;i<tot;i++)
			for(j=0;j<tot-i;j++)
				if(strcmp(rq[mark[j]],rq[mark[j+1]])>0)
				{
					t=mark[j];mark[j]=mark[j+1];
					mark[j+1]=t;
				}
		if(tot==0)
			printf("No subdirectories");
		for(i=0;i<tot;i++)
		{
			if(i!=tot-1)
			printf("%-8s",rq[mark[i]]);
			else printf("%s",rq[mark[i]]);
		}
		printf("\n");
	}
	if(cmd[0]=='c')
	{
		for(j=0;j<count;j++)
			if(pre[j]==cuur&&strcmp(rq[j],sub)==0)
				break;
		if(j==count)
			printf("Subdirectory does not exist\n");
		else cuur=j;
	}
	if(cmd[0]=='u')
	{
		if(pre[cuur]==-1)
			printf("Cannot move up from root directory\n");
		else cuur=pre[cuur];
		return ;
	}
	if(cmd[0]=='m')
	{
		for(i=0;i<count;i++)
			if(pre[i]==cuur&&strcmp(rq[i],sub)==0)
				break;
		if(i!=count)
			printf("Subdirectory already exists\n");
		else
		{
		strcpy(rq[count++],sub);
		pre[count-1]=cuur;
		}
	}
}
int main()
{
	int tot=0;
	count=1;
	strcpy(rq[0],"root");
	cuur=0;pre[0]=-1;
	while(scanf("%s",cmd)==1)
	{
		if(!tot++)
			printf("Problem 5 by team x\n");
		run();
	}
	printf("End of problem 5 by team x\n");
	return 0;
}