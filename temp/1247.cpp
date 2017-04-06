#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
	int i,j,len,count=0,t;
	char ch,buf[500],dir[5];
	double x=0,y=0;
	scanf("%s",buf);
	while(strcmp(buf,"END")!=0)
	{
		x=y=0;
		len=strlen(buf);
		while(1)
		{
			t=0;j=0;
			for(i=0;i<len;i++)
				if(buf[i]==','||buf[i]=='.')
				{
					ch=buf[i];
					buf[i]='\0';
					sscanf(buf+j,"%d%s",&t,dir);
					if(strcmp(dir,"E")==0)
						x+=t;
					else if(strcmp(dir,"S")==0)
						y-=t;
					else if(strcmp(dir,"W")==0)
						x-=t;
					else if(strcmp(dir,"N")==0)
						y+=t;
					else if(strcmp(dir,"SE")==0)
					{
						x+=t*sqrt(2)*0.5;
						y-=t*sqrt(2)*0.5;
					}
					else if(strcmp(dir,"SW")==0)
					{
						x-=t*sqrt(2)*0.5;
						y-=t*sqrt(2)*0.5;
					}
					else if(strcmp(dir,"NW")==0)
					{
						x-=t*sqrt(2)*0.5;
						y+=t*sqrt(2)*0.5;
					}
					else if(strcmp(dir,"NE")==0)
					{
						x+=t*sqrt(2)*0.5;
						y+=t*sqrt(2)*0.5;
					}
					buf[i]=ch;
					j=i+1;
				}
				break;
/*			if(buf[len-1]=='.')break;
			scanf("%s",buf);*/
		}
		printf("Map #%d\n",++count);
		if(fabs(x)<0.5*1e-3)x=0;
		if(fabs(y)<0.5*1e-3)y=0;
printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
printf("The distance to the treasure is %.3lf.\n",sqrt(x*x+y*y));
putchar('\n');
		scanf("%s",buf);
	}
}