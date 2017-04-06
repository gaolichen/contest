#include<iostream.h>
#include<string.h>

int a[4000];
int mark[4000],pre[4000],n,ans,cnt;


void run(){
	int i,j,tmp;
	memset(mark,0,sizeof(mark));
	for(i=0;i<n;i++)
		if(pre[i]&&!a[i]){
			if(mark[i]==pre[i])continue;
			else{
				if(!mark[i]){
					j=0;while(i+j<n&&!a[i+j])mark[i+j++]=pre[i];
					j=0;while(i-j>=0&&!a[i-j])mark[i-j++]=pre[i];
				}
				else {
					tmp=pre[i];
					for(j=0;j<n;j++){
						if(mark[j]==tmp)mark[j]=mark[i];
						if(pre[j]==tmp)pre[j]=mark[i];
					}
					ans--;
				}
			}
		}
	for(i=0;i<n;i++){
		if(!a[i]&&!mark[i]){
			cnt++;
			for(j=0;i+j<n&&!a[i+j];j++)
				mark[i+j]=cnt;
			ans++;
		}
		pre[i]=mark[i];
	}	
}
int main(){
	int i,j;
	while(cin>>n){
		memset(pre,0,sizeof(pre));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				cin>>a[j];
			if(i==0){
				for(j=0,cnt=0;j<n;j++)
					if(!a[j]){
						if(!j||a[j-1])
							pre[j]=++cnt;
						else pre[j]=cnt; 
					}
				ans=cnt;
			}
			else run();
		}
		cout<<ans<<endl;
	}
	return 0;
}