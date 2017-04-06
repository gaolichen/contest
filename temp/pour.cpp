#include<stdio.h>
#define N 1000
int step[6][2]={0,1,0,2,1,0,1,2,2,0,2,1};
int stack[N],pop;
int c[3]={10,0,0};
int way[N][3];
int cmax[3]={10,7,3};
void pour(int k)
{
	int temp,i,j;
	i=step[k][0];
	j=step[k][1];
	if(c[i]==0)
		return;
	c[j]+=c[i];
	temp=c[j];
	if(c[j]>cmax[j])
		c[j]=cmax[j];
	c[i]=temp-c[j];
}
int same(int i)
{
	int k;
	for(k=0;k<3;k++)
		if(c[k]!=way[i][k])
			return 0;
	return 1;
}
void print()
{
	int i;
	printf("step 0: %d %d %d\n",10,0,0);
	for(i=1;i<pop;i++)
	{
		printf("Step %-4d: ",i);
		switch(stack[i])
		{
		case 0:printf("Pour C10 into C7 .  ");break;
		case 1:printf("Pour C10 into C3 .  ");break;
		case 2:printf("Pour C7  into C10.  ");break;
		case 3:printf("Pour C7  into C3 .  ");break;
		case 4:printf("Pour C3  into C10.  ");break;
		case 5:printf("Pour C3  into C7 .  ");break;
		}
		printf("%d %d %d\n",way[i][0],way[i][1],way[i][2]);
	}
}
void main()
{
	char ch;
	int i=0,k;
	pop=0;
	way[pop][0]=c[0];
	way[pop][1]=c[1];
	way[pop][2]=c[2];
	stack[pop]=-1;
	pop=1;
	while((c[0]!=5||c[1]!=5)&&pop!=0)
	{
		if(i==6)
		{
			pop--;
			for(k=0;k<3;k++)
			{
				c[k]=way[pop-1][k];
			}
			i=stack[pop]+1;
		}
		if(i!=6)
		{
		pour(i);
		for(k=pop-1;k>=0;k--)
			if(same(k))
			{
				i++;break;
			}
		if(k==-1)
		{
			stack[pop]=i;
			for(k=0;k<3;k++)
		        way[pop][k]=c[k];
			pop++;
			i=0;
		}
		else 
			for(k=0;k<3;k++)
				c[k]=way[pop-1][k];
		}
	}
	if(pop)
		print();
	else
		printf("No solution!\n");
	for(;(ch=getchar())!='e';);
}