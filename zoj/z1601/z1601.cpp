#include<iostream.h>
#include<math.h>

double a;
int n;
void run(){
	int i,x1,y1,x2,y2,x,y;
	i=(int)floor(a);
	x1=i;x2=i+1;
	y1=y2=1;
	if(x2>n){
		cout<<n<<' '<<1<<endl;
		return ;
	}
	while(x1+x2<=n&&y1+y2<=n){
		x=x1+x2;y=y1+y2;
		if((double)x/y-a<0){
			x1+=x2;
			y1+=y2;
		}
		else {
			x2+=x1;
			y2+=y1;
		}
	}
	if(fabs((double)x1/y1-a)<fabs((double)x2/y2-a)){
		cout<<x1<<' '<<y1<<endl;
	}
	else cout<<x2<<' '<<y2<<endl;

}

int main(){
	while(cin>>a>>n)run();
	return 0;
}