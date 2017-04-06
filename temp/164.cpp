#include<stdio.h>
#define N 500
void main()
{
	char str[100];
	op[30][30][2];
	gets(str);
	while(str[0]!='#')
	{
		for(i=0;str[i]!=' ';i++)
			str1[i]=str[i];
		str1[i]='\0';
		for(i++;str[i]!='\0';i++)
			str2[i]=str[i];
		len1=strlen(str1);
		len2=strlen(str2);
		op[0][0][0]=0;op[0][0][0]=0;
		od[0][0]=' ';
		m[0][0]=0;
		for(i=1;i<=len2;i++)
		{
			m[0][i]=i;
			last[0][i][0]=0;
			last[0][i][1]=i;
			op[0][i][0]=2;op[0][i][1]=i;
			od[0][i]=str2[i-1];
		}
		for(i=1;i<=len1;i++)
		{
			m[i][0]=i;
			last[i][0]=
		}
	}
}