#include<stdio.h>
#include<string.h>
int right[7][7],t,f,r,left,low,b;
void run(char *str)
{
	int i,len,x=0,y=0,t1,t2,temp,t3;
	len=strlen(str);
	t=str[0]-'0';
	i=1;
	while(str[i]==' ')i++;
	f=str[i]-'0';
	b=7-f;low=7-t;
	r=right[t][f];
	left=7-r;
	t1=t;t2=f;
	if(!r)
	{
		printf("\nInvalid initial orientation:     ");
		printf("top = %d  front = %d\n",t,f);
		return;
	}
	i++;
	if(str[i]==' ')i++;
	t3=i;
	for(i=3;i<len;i++)
		if(str[i]!=' ')
		{
			if(str[i]=='N')
			{
				temp=t;t=f;
				f=low;low=b;b=temp;
				y++;
			}
			if(str[i]=='W')
			{
				temp=t;t=r;
				r=low;low=left;
				left=temp;
				x--;
			}
			if(str[i]=='E')
			{
				temp=t;t=left;
				left=low;low=r;
				r=temp;
				x++;
			}
			if(str[i]=='S')
			{
				temp=t;t=b;b=low;
				low=f;f=temp;
				y--;
			}
		}
	printf("\nInitial orientation:             ");
	printf("top = %d  front = %d\n",t1,t2);
	printf("Moves: %s\n",str+t3);
	printf("Final orientation and position:  ");
	printf("top = %d  front = %d  ",t,f);
	printf("x =%4d  y =%4d\n",x,y);
}
void init()
{
	int i,j;
	t=1;f=2;
	r=3;low=6;
	b=5;left=4;
	for(i=1;i<7;i++)
		for(j=1;j<7;j++)
			right[i][j]=0;
	for(i=0;i<4;i++)
	{
		right[t][f]=r;
		right[t][r]=b;
		right[t][b]=left;
		right[t][left]=f;
		j=t;t=f;f=low;
		low=b;b=j;
	}
	right[3][1]=2;right[3][2]=6;
	right[3][6]=5;right[3][5]=1;
	right[4][1]=5;right[4][5]=6;
	right[4][6]=2;right[4][2]=1;
}
void main()
{
	int count=0;
	char str[200];
	init();
	while(gets(str))
	{
		if(!count)
		{
			printf("Problem 2 by team x\n");
			count=1;
		}
		run(str);
	}
	printf("End of problem 2 by team x\n");
}