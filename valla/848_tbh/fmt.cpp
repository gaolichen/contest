#define for if(0); else for
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector <string> vs;

bool canMerge( string a, string b) {
	return false;	
}

string merge (string a, string b) {
	return a + b;	
}

bool isEmpty ( char c ) {
	return c == ' ' || c == '\t';	
}
void init () {
	int cnt = 0;
	for ( int i = 1; i < vs.size(); i++) {
		if (canMerge(vs[i], vs[i - 1])) {
			string s = merge (vs[i], vs[ i - 1]) ;
			vs [cnt] = s;	
		}	
		else {
			vs [++cnt] = vs[ i ];	
		}
	}	
	vs.resize (cnt + 1);
}

void process (string s) {
	int i = 0; 
	while ( i < s.length() && s[ i ] == ' ' || s[ i ] == '\t' ) i++;	
	s = s.substr (i);
	s += " ";
	int st = 0;
	int pre = 0;
	for ( int i = 1; i < s.length(); i++) 
		if (isEmpty (s[i]) && !isEmpty (s[i - 1])){
			if (i - st > 70){
				if ( pre > st ){
					cout << s.substr (st, pre - st) << endl;	
				}	
				else {
					for (int j = st; j < i; j+= 70) {
						if ( j + 70 <= i ) cout << s.substr (j, 70) << endl;
						else cout << s.substr (j, i - j) << endl;	
					}	
				}
				st = i;
				while ( st < s.length() && isEmpty ( s[st] )) st++;
				pre = st;
			}
			else pre = i;
		}
}

void run () {
	init();
	for ( int i = 0; i < vs.size(); i++)
		process (vs[i]);	
}
int main() {
	string s;
	while (getline (cin, s) ) {
		vs.push_back (s);	
	}
	run();
	return 0;	
}