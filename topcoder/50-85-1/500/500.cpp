#include<iostream>
#include<vector>
#include<string>
using namespace std;

class RPSVari{
public:
	vector<int> ret;
	int buf[1000],point[1000];
	void calc(int n){
		int i,j;
		int mark[6];
		memset(mark,0,sizeof(mark));
		for(i=0;i<n;i++)
			mark[buf[i]]++;
		for(i=0;i<n;i++){
			if(mark[buf[i]]==1)point[i]=n;
			else point[i]=1;
			if(mark[(buf[i]+1)%6])
				ret[i]+=point[i]*mark[(buf[i]+1)%6];
			if(mark[(buf[i]+5)%6])
				ret[i]--;
			else ret[i]++;
		}
		for(i=0;i<=5;i++)
			if(mark[i])break;
		if(!mark[(i+5)%6])
		for(j=0;j<n;j++)
			if(buf[j]==i)ret[j]+=10;
		for(i=0;i<n;i++)
			if(ret[i]<0)ret[i]=0;
		for(i=0;i<n;i++)
			cout<<ret[i]<<' ';
		cout<<endl;
	}
	vector<int> finalScore(vector<string> fing){
		int i,j,len;	
		for(i=0;i<fing.size();i++)
			ret.push_back(0);
		len=strlen(fing[0].c_str());
		for(i=0;i<len;i++){
			for(j=0;j<fing.size();j++)
				buf[j]=fing[j].c_str()[i]-'0';
			calc(j);
		}
		return ret;
	}
};

int main ()
{
	int i,n;
	char buf[100];
	RPSVari res;
	vector<string> a;
	vector<int> out;
	while(cin>>n){
		a.clear();
		for(i=0;i<n;i++){
			cin>>buf;
			a.push_back(buf);
		}
		out=res.finalScore(a);
		for(i=0;i<n;i++)
			cout<<out[i]<<endl;
	}
	return 0;
}