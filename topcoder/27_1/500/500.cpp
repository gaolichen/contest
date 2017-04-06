//program framework generated with WishingBone's parser :)-

//common header
#ifdef WIN32
#	pragma warning(disable:4786)
#endif
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

//64 bit integer definition
#ifdef WIN32
#define in_routine(type,spec) \
istream& operator>>(istream& s,type &d){char b[30];s>>b;sscanf(b,spec,&d);return s;}
#define out_routine(type,spec) \
ostream& operator<<(ostream& s,type d){char b[30];sprintf(b,spec,d);s<<b;return s;}
typedef signed __int64 i64; in_routine(i64,"%I64d") out_routine(i64,"%I64d")
typedef unsigned __int64 u64; in_routine(u64,"%I64u") out_routine(u64,"%I64u")
#else
typedef signed long long i64;
typedef unsigned long long u64;
#endif

//common routines
#ifdef WIN32
#define min(a,b) _cpp_min(a,b)
#define max(a,b) _cpp_max(a,b)
#endif
#define abs(a) ((a)>0?(a):-(a))
#define s2in(s,in) istringstream in(s)
#define inmat(i,j,m,n) ((i)>=0&&(i)<(m)&&(j)>=0&&(j)<(n))
#define cls(a) memset((a),0,sizeof(a))
#define VI vector<int>
#define V64 vector<i64>
#define VS vector<string>
#define VD vector<double>
int mx[8]={0,1,0,-1,1,1,-1,-1};
int my[8]={1,0,-1,0,1,-1,-1,1};


template <class T>
void remove(vector<T>&v,const T&e){
	v.resize(remove(v.begin(),v.end(),e)-v.begin());
}
template <class T>
void insert(vector<T>&v,int isnum,const T&e){
	v.resize(v.size()+1);
	for(int i=v.size()-1;i>isnum;v[i--]=v[i-1]);
	v[isnum]=e;
}
void insert(string &s,int isnum,const string&is){
string t=s;s.resize(isnum);s+=is+(t.c_str()+isnum);
}
//output routine
ostream& operator<<(ostream& s,string d){
	s<<'\"'<<d.c_str()<<'\"';
	return s;
}
template <class T>
ostream& operator<<(ostream& s,vector<T> d){
	s<<"{";
	for (typename vector<T>::iterator i=d.begin();i!=d.end();i++)
		s<<(i!=d.begin()?",":"")<<*i;
	s<<"}";
	return s;
}

//parsing routine
template <class T>
vector<basic_string<T> > parse(const basic_string<T> &s,const basic_string<T> &delim){
	vector<basic_string<T> > ret(0);
	for (int b,e=0;;ret.push_back(s.substr(b,e-b)))
		if ((b=s.find_first_not_of(delim,e))==(e=s.find_first_of(delim,b)))
			return ret;
}

typedef  i64 T;

T gcd(T a,T b){
	if(b==0)return abs(a);
	return gcd(b,a%b);
}

T lcm(T a,T b){
	return abs(a/gcd(a,b)*b);
}

class fct{
	
public:
	T a,b;
	friend inline int fctcmp(fct&,fct&);
	friend inline int intcmp(fct&,int);
	inline fct& init(T,T);
	inline int operator!=(fct&);
	inline int operator!=(int);
	inline int operator>(fct&);
	inline int operator>(T);
	inline int operator<(fct&);
	inline int operator<(T);
	inline int operator>=(fct&);
	inline int operator>=(T);
	inline int operator<=(T);
	inline int operator<=(fct&);
	inline int operator==(fct&);
	inline int operator==(T);
	inline fct& operator=(fct&);
	inline fct& operator=(int);
	inline fct& operator+=(int);
	inline fct& operator+=(fct&);
	inline fct& operator-=(int);
	inline fct& operator-=(fct&);
	inline fct& operator*=(int);
	inline fct& operator*=(fct&);
	inline fct& operator/=(int);
	inline fct& operator/=(fct&);
	friend inline istream& operator>>(istream&,fct&);
	friend inline ostream& operator<<(ostream&,fct&);
};

inline int fctcmp(fct& a,fct& b){
	return (int)(a.a*b.b-a.b*b.a);
}

inline int intcmp(fct& a,T b){
	return (int)(a.a-a.b*b);
}

inline int fct::operator != (fct& a){
	return fctcmp(*this,a)!=0;
}

inline int fct::operator !=(int a){
	return intcmp(*this,a)!=0;
}
inline fct& fct::init (T a,T b){
	T t;
	t=gcd(a,b);
	if(t>1){
		a/=t;b/=t;
	}
	if(b<0){
		b=-b;a=-a;
	}
	this->a=a;
	this->b=b;
	return *this;
}

/////////////////////////////////////
inline fct& fct::operator *=(fct& a){
	T t1,t2;
	t1=gcd(a.a,this->b);
	t2=gcd(a.b,this->a);
	this->a*=a.a/t1;
	this->b*=a.b/t2;
	t1=gcd(this->a,this->b);
	if(t1>1){
		this->a/=t1;this->b/=t1;
	}
	return *this;
}
inline fct& fct::operator *=(int a){
	T t;
	this->a*=a/gcd(this->b,a);
	this->b/=gcd(this->b,a);
	t=gcd(this->a,this->b);
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}

inline fct& fct::operator /= (int a){
	T t;
	this->b*=a/gcd(this->a,a);
	this->a/=gcd(this->a,a);
	t=gcd(this->a,this->b);
	if(t>1||t<-1){
		this->a/=t;
		this->b/=t;
	}
	if(this->b<0){
		this->b=-this->b;
		this->a=-this->a;
	}
	return *this;
}

inline fct& fct::operator /= (fct& a){
	T t1,t2;
	t1=gcd(this->a,a.a);
	t2=gcd(this->b,a.b);
	this->a*=a.b/t1;
	this->b*=a.a/t2;
	t1=gcd(this->a,this->b);
	if(t1>1||t1<-1){
		this->a/=t1;this->b/=t1;
	}
	if(this->b<0){
		this->b=-this->b;
		this->a=-this->a;
	}
	return *this;
}

inline fct& fct::operator += (int a){
	this->a+=a*this->b;
	return *this;
}

inline fct& fct::operator += (fct& a){
	T t;
//	t=this->b*a.b;
//	this->a=this->a*a.b+this->b*a.a;
	t=lcm(a.b,this->b);
	this->a=t/a.b*a.a+t/this->b*this->a;
	this->b=t;
	t=gcd(this->a,this->b);
	if(t>1){
		this->a/=t;this->b/=t;
	}
	return *this;
}

inline fct& fct::operator -=(fct& a){
	T t;
//	t=this->b*a.b;
	t=lcm(a.b,this->b);
	this->a=t/this->b*this->a-t/a.b*a.a;
	this->b=t;
	t=gcd(this->a,this->b);
	if(t<0)t=-t;
	if(t>1){
		this->a/=t;
		this->b/=t;
	}
	return *this;
}

inline fct& fct::operator -= (int a){
	this->a-=a*this->b;
	return *this;
}


inline int fct::operator < (fct& a){
	return fctcmp(*this,a)<0;
}

inline int fct::operator >(fct& a){
	return fctcmp(*this,a)>0;
}

inline int fct::operator ==(fct& a){
	return fctcmp(*this,a)==0;
}

inline int fct::operator >=(fct &a){
	return fctcmp(*this,a)>=0;
}

inline int fct::operator <=(fct &a){
	return fctcmp(*this,a)<=0;
}



inline int fct::operator<(T a){
	return intcmp(*this,a)<0;
}

inline int fct::operator>(T a){
	return intcmp(*this,a)>0;
}

inline int fct::operator<=(T a){
	return intcmp(*this,a)<=0;
}

inline int fct::operator>=(T a){
	return intcmp(*this,a)>=0;
}

inline int fct::operator==(T a){
	return intcmp(*this,a)==0;
}

inline ostream& operator<<(ostream& os,fct& a){
	os<<a.a;
	if(a.b>1)os<<'/'<<a.b;
	return os;
}

inline istream& operator>>(istream& is,fct& a){
	char ch;
	T t;
	if(!(is>>a.a))return is;
	is>>ch;
	is>>a.b;
	t=gcd(a.a,a.b);
	if(t>1){
		a.a/=t;a.b/=t;
	}
	if(a.b<0){
		a.a=-a.a;
		a.b=-a.b;
	}
	return is;
}

inline fct& fct::operator = (fct& a){
	this->a =a.a ;
	this->b =a.b ;
	return *this;
}
inline fct& fct::operator=(int a){
	this->a=a;
	this->b=1;
	return *this;
}


struct Fractions{
	string add(vector <string> vs){
		fct ret,tmp;
		int i;
		ret=0;
		for(i=0;i<vs.size();i++){
			s2in(vs[i],in);
			in>>tmp;
			ret+=tmp;
		}
		stringstream rs;
		rs<<ret.a<<'/'<<ret.b;
		return rs.str();
	}
};