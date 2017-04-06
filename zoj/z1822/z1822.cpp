#include<iostream>
using namespace std;

char mark[30];
vector< vector< int > > vvi;

int atoi( char ch ) {
	if ( ch >= 'A' && ch <= 'Z' ) ch = ch - 'A' + 'a';	
	return ch - 'a';
}
void init( string tmp ) {
	tmp.replace( ":,"," " );
	istringstream in( tmp );
	char ch, t;
	in >> ch;
	mark[ atoi( ch ) ] = 1;
	int i;
	while ( cin >> t >> i ) {
		vvi[ atoi( ch ) ][ atoi( t ) ] += i;
	}
}
int main(){
	string tmp;
	while( cin>>s ) {
		vvi.clear();
		vvi.resize( 26, vector( 26, 0 ) );
		memset( mark, 0, sizeof(mark));
		cin>>n;
		getline( cin, tmp );
		for ( int i = 0; i < n; i++ ){
			getline( cin, tmp );
			paser( tmp );
		}
		run();
	}
	return 0;
}