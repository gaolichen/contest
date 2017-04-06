#include<stdio.h>
char url[100];
void run()
{
	int i,j;
	char ch,tempch='\0';
	i=0;
	while(url[i]!=':')i++;
	url[i]='\0';
	printf("Protocol = %s\n",url);
	while(!(url[i]>='a'&&url[i]<='z'||url[i]>'A'&&url[i]<='Z'))i++;
	j=i;
	while(url[i]!=':'&&url[i]!='/'&&url[i]!='\0')i++;
		ch=url[i];
		url[i]='\0';
	printf("Host     = %s\n",url+j);
	j=++i;
	if(ch==':')
	{
		while(url[i]>='0'&&url[i]<='9')i++;
	tempch=url[i];
	url[i]='\0';
	printf("Port     = %s\n",url+j);
	j=++i;
	}
	else printf("Port     = <default>\n");
	if(ch=='/'||tempch=='/')
		printf("Path     = %s\n",url+j);
	else printf("Path     = <default>\n");

}
void main()
{
	int i,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",url);
		printf("URL #%d\n",i+1);
		run();
		putchar('\n');
	}
}