#include<stdio.h>
#define N 20
int chess[N][N],n;
int path(int i)
{
	int j,k;
	if(i==1)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
			temp[j][k]=chess[k][j];
	else 
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				temp[j][k]=chess[j][k];
	j=0;k=0;
	while(temp[0][j]!=i)j++;
	pop=0;
	sk[pop][0]=0;
	sk[pop][1]=j;
	while(pop>=0)
	{
		if(k==4)
		{
			pop--;
			mark[sk[pop][0]][sk[pop][1]];
			k=stack[pop]+1;
		}
		else if(place(k))
		{
			i
		}
	}
}
void main()
{
	int i,j,flag;
	char buf[80],ch;
    scanf("%d",&n);
	while(n)
	{
	   gets(buf);
	   gets(buf);
	   for(i=0;i<n;i++)
	   {
		   for(j=0;j<n;j++)
		   {
			   ch=getchar();
			   if(ch=='W')
				   chess[i][j]=1;
			   else if(ch=='B')
				   chess[i][j]=2;
			   else chess[i][j]=0;
		   }
		   ch=getchar();
	   }
	   if(path(1))
		   flag=1;
	   else if(path(2))
		   flag=2;
	   else if(path1(1))
		   flag=3;
	   else if(path1(2))
		   flag=4;
	   else flag=0;
	}
}