#include<stdio.h>
#include<string.h>
int def[26],n;
char va[5000][2][2];
void run()
{
	int i,j=0;
	memset(def,0,sizeof(def));
	def[0]=1;
	for(i=0;i<n;i++)
		def[va[i][0][0]-'a']=def[va[i][1][0]-'a'];
	for(i=0;i<26;i++)
		if(def[i])
		{
			printf("%c ",'a'+i);
			j++;
		}
	if(j==0)
		printf("none");
		putchar('\n');
}
void main()
{
	int i,count=0;
	char buf[2];
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%s%s%s",va[i][0],buf,va[i][1]);
		printf("Program #%d\n",++count);
		run();
		putchar('\n');
		scanf("%d",&n);
	}
}