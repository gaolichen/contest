#include<stdio.h>
#include<string.h>
char map[100][100],mark[100][100];
int m;
void run()
{
	int i,j,len,xk,yk,xp,yp,t;
	len=strlen(map[m]);
	memset(mark,0,sizeof(mark));
	for(i=0;i<m;i++)
		for(j=0;map[i][j]!='\0';j++)
		{
			if(map[i][j]=='K')
			{
				xk=i;yk=j;
			}
			if(map[i][j]=='P')
			{
				xp=i;yp=j;
			}
		}
	mark[xk][yk]=2;
	for(i=0;i<len;i++)
	{
		if(map[m][i]=='^')
			xk--;
		if(map[m][i]=='v')
			xk++;
		if(map[m][i]=='<')
			yk--;
		if(map[m][i]=='>')
			yk++;
		if(xk==xp&&yk==yp)
		{
			printf("\nDay%3d: entered room          ",i+1);
			printf("(%2d,%3d); princess found\n",xk,yk);
			return;
		}
		if(mark[xk][yk]&&map[m][i]!='.')
		{
printf("\nDay%3d: attempt to enter room (%2d,%3d);",i+1,xk,yk);
printf(" previously entered on day%3d\n",mark[xk][yk]-1);
return;
		}
		if(map[xk][yk]=='#')
		{
printf("\nDay%3d: attempt to enter room ",i+1);
printf("(%2d,%3d); permanently blocked\n",xk,yk);
return;
		}
		if(map[xk][yk]>='0'&&map[xk][yk]<='9')
		{
			t=(map[xk][yk]-'0'+i*9)%10;
			if(t!=1)
			{
printf("\nDay%3d: entered room          ",i+1);
printf("(%2d,%3d); will be killed by dragons\n",xk,yk);
return;
			}
			else mark[xk][yk]=i+2;
		}
		if(map[xk][yk]=='.'&&!mark[xk][yk])
			mark[xk][yk]=i+2;
	}
printf("\nDay%3d: entered room          ",len);
printf("(%2d,%3d); actions performed, princess not found\n",xk,yk);
}
void main()
{
	int i=0,count=0;
	while(1)
	{
		if(!gets(map[i]))break;
		if(map[i][0]!='#')
		{
			m=i;
			if(!count)
			{
				printf("Problem 1 by team x\n");
				count=1;
			}
			run();
			i=-1;
		}
		i++;
	}
	printf("End of problem 1 by team x\n");
}