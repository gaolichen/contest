#include<iostream.h>
#include<string.h>
#include<stdio.h>

char cap[26]={'V','W','X','Y','Z','A','B','C', 'D', 'E', 'F','G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};
char buf[1000];
void run(){
	int i,len;
	len=strlen(buf);
	for(i=0;i<len;i++)
	if(buf[i]>='A'&&buf[i]<='Z')
		buf[i]=cap[buf[i]-'A'];
	puts(buf);
}
int main(){
	while(1){
		gets(buf);
		if(strcmp(buf,"ENDOFINPUT")==0)break;
		gets(buf);
		run();
		gets(buf);
	}
	return 0;
}