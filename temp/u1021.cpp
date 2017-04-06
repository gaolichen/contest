#include<stdio.h>
void main()
{
	int i,n1,n2,a[80000],b[80000],f;
	while(scanf("%d",&n1)==1)
	{
		for(i=-32768;i<=32767;i++)
			a[i+40000]=b[i+40000]=0;
		for(i=0;i<n1;i++)
		{
			scanf("%d",&f);
			a[f+40000]=1;
		}
		scanf("%d",&n2);
		for(i=0;i<n2;i++)
		{
			scanf("%d",&f);
			b[f+40000]=1;
		}
		for(i=-22768;i<=32767;i++)
			if(a[40000+i]&&b[50000-i])
			{printf("YES\n");break;}
		if(i==32768)
			printf("NO\n");
	}
}
