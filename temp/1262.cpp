#include<stdio.h>
#include<string.h>
int p[17]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,
8192,16384,32768,65534};
int next[40000],n,s,rul[10];
char word[40],cha[10][10];
void print(int k)
{
	int i=1,j=n-1;
	for(i=0;;i++)
	{
		if(j<0)break;
		printf("%c",k/p[j]+'a');
		k-=(k/p[j])*p[j];
		j--;
	}
	putchar('\n');
}
int change(char *a)
{
	int i,j=0,t=0;
	char temp[20];
	for(i=0;i<n;i++)
	{
		j=0;
		j=(a[(i+n-2)%n]-'a');
		j=j*2+(a[i]-'a');
		j=j*2+(a[(i+1)%n]-'a');
		t=t*2+rul[j];
		temp[i]=rul[j]+'a';
	}
	temp[i]='\0';
	strcpy(a,temp);
	return t;
}
void run()
{
	int i,mark[40000],curr=0,t,j;
	char temp[20],small[20],ch;
	memset(mark,0,sizeof(mark));
	for(i=0;i<8;i++)
	{
		for(j=0,t=0;j<3;j++)
			t=t*2+cha[i][j]-'a';
		rul[t]=cha[i][3]-'a';
	}
	for(i=0;i<n;i++)
		curr=2*curr+word[i]-'a';
	for(i=1;i<=s;i++)
	{
		if(mark[curr])break;
		mark[curr]=i;
		curr=change(word);
	}
	if(i<=s)
	{
		t=i-mark[curr];
		s=(s-i+1)%t;
		for(i=0;i<s;i++)
			curr=change(word);
	}
	strcpy(temp,word);
	strcpy(word+n,temp);
	strcpy(small,temp);
	for(i=0;i<n;i++)
	{
		ch=word[i+n];
		word[i+n]='\0';
		strcpy(temp,word+i);
		if(strcmp(temp,small)<0)
			strcpy(small,temp);
		word[i+n]=ch;
	}
	puts(small);
}
void main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		scanf("%s",word);
		for(i=0;i<8;i++)
			scanf("%s",cha[i]);
		scanf("%d",&s);
		run();
	}
}