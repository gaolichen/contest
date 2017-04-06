#include <stdio.h>

char line[1000],firstline[1000];
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int main()
{
	int i,j,n;
	bool ans;
	do{
		fscanf(in,"%d",&n);
		if(n==0) break;
		fscanf(in,"%s",firstline);
		ans=true;
		for(i=2;i<=n;i++){
			fscanf(in,"%s",line);
			int t=0;
			for(j=0;j<n;j++){
				if(line[j]!=firstline[j])t++;
			}
			if(0<t&&t<n) ans=false;
		}
		if(ans)fprintf(out,"yes\n");
		else fprintf(out,"no\n");
	}while(1);
	fclose(in);
	fclose(out);
	return 0;
}
