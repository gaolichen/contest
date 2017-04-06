#include<iostream>
#include<string>
#include<vector>
using namespace std;

class LarvaRace{
public:
	int calc(string move,int dis){
		int i,len,t,ret=0;
		int dist,temp;
		len=strlen(move.c_str());
		temp=dist=0;t=256;
		dis*=256;
		for(i=0;;i++){
			if(dist>=dis)break;
			if(i==len){
				if(dist==0)return 2100000000;
				i=0;
			}
			{
			if(move.c_str()[i]=='1')
				temp=dist;
			else if(move.c_str()[i]=='2'){
				temp=dist;
				t/=2;
			}
			else {
				temp=dist+(256-t);
				t=256;
			}
			}
			dist=temp;
			ret++;
		}
/*		if(dist[len]==0)return 2100000000;
		ret=len*(dis/dist[len]);
		dis%=dist[len];
		for(i=0;i<len;i++)
			if(dist[i]>=dis)break;
//		cout<<ret+i<<endl;*/
//		cout<<ret<<endl;
		return ret;
	}
	int getWinner(vector<string> moves,int dis){
		int i,ret=0,min=2100000000,time;
		for(i=0;i<moves.size();i++){
			time=calc(moves[i],dis);
			if(time<min){
				ret=i;
				min=time;
			}
		}
		return ret;
	}
};

int main(){
	int n,i,dis;
	char buf[100];
	vector<string> a;
	LarvaRace b;
	while(cin>>n>>dis){
		a.clear();
		for(i=0;i<n;i++){
			cin>>buf;
			a.push_back(buf);
		}
		cout<<b.getWinner(a,dis)<<endl;
	}
	return 0;
}