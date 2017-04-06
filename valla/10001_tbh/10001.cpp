#define for if (0); else for

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int mat[8];
string state;

char calc ( char a, char b, char c) {
	return '0' + mat[(a - '0') * 4 + (b - '0')*2 + (c - '0')];	
}
bool dfs (string &s, int len) {
	if (len == s.length()) {
		if ( calc ( s[len - 2], s[len - 1], s[0] ) == state [len - 1] && calc ( s[len - 1], s[0], s[1] ) == state [0] )
			return true;
		return false;	
	}	
	if ( calc (s[len - 2], s[len - 1], '0') == state[len - 1] ){
		s [len] = '0';
		if (dfs (s, len + 1) ) return true;	
	}
	if ( calc (s[len - 2], s[len - 1], '1') == state[len - 1] ) {
		s [len] = '1';
		if (dfs (s, len + 1) ) return true;
	}
	return false;
}
bool check (string s) {
	string res = s;
	for (int i = 0; i < 4; i++) {
		res[0] = (i & 1)? '1' : '0';
		res[1] = (i & 2)? '1': '0';	
		if (dfs (res, 2) )return false;
	}	
	return true;
}

void run (string s) {
	istringstream myin (s);
	int id, n;
	myin >> id >> n >> state;
	memset (mat, 0, sizeof (mat));
	for ( int i = 0; i < 8; i++)
		if ( (1<<i) & id) mat[i] = 1;
		else mat[i] = 0;
	if (check (state))
		cout << "GARDEN OF EDEN" << endl;
	else cout << "REACHABLE" << endl;	
}
int main() {
	string s;
	while(getline(cin, s) )run (s);
	return 0;	
}