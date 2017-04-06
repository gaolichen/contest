#include<stdio.h>
#include<string.h>
int w[20];
char left[4][12],right[4][12],res[4][10];
int check()
{
	int i,j,lw,rw,len1,len2;
	for(i=0;i<3;i++)
	{
		lw=rw=0;
		len1=strlen(left[i]);
		len2=strlen(right[i]);
		for(j=0;j<len1;j++)
			lw+=w[left[i][j]-'A'];
		for(j=0;j<len2;j++)
			rw+=w[right[i][j]-'A'];
		if(lw==rw&&res[i][0]!='e')
			return 0;
		if(lw>rw&&res[i][0]!='u')
			return 0;
		if(lw<rw&&res[i][0]!='d')
			return 0;
	}
	return 1;
}
void run()
{
	int i;
	memset(w,0,sizeof(w));
	for(i=0;i<12;i++)
	{
		w[i]=1;
		if(check())
		{
printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
			return;
		}
		w[i]=0;
	}
	for(i=0;i<12;i++)
	{
		w[i]=-1;
		if(check())
		{
printf("%c is the counterfeit coin and it is light.\n",i+'A');
             return;
		}
		w[i]=0;
	}
}
void main()
{
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s%s%s",left[0],right[0],res[0]);
		scanf("%s%s%s",left[1],right[1],res[1]);
		scanf("%s%s%s",left[2],right[2],res[2]);
		run();
	}
}