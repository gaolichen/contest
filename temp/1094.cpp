#include<stdio.h>
#include<string.h>
int cap[26],r[3000],c[3000],n;
char cal[100];
void run()
{
	int i,len,sum=0,sk[50],pop=0,t1,t2,st=n;
	len=strlen(cal);
	if(len==1)
	{
		printf("0\n");
		return;
	}
	for(i=0;i<len;i++)
	{
		if(cal[i]>='A'&&cal[i]<='Z')
			sk[pop++]=cap[cal[i]-'A'];
		if(cal[i]==')')
		{
			pop--;
			t1=sk[pop-1];
			t2=sk[pop];
			if(c[t1]!=r[t2])
			{
				puts("error");
				return;
			}
			sum+=r[t1]*c[t1]*c[t2];
			sk[pop-1]=st;
			r[st]=r[t1];
			c[st++]=c[t2];
		}
	}
	printf("%d\n",sum);
}
void main()
{
	int i;
	char ch[3];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d",ch,&r[i],&c[i]);
		cap[ch[0]-'A']=i;
	}
	while(scanf("%s",cal)==1)
		run();
}