
#define for if (0); else for
#include <iostream>
#include <string>
using namespace std;

int n;
int longest, dis;
int st;
char mat[110][110];

void dfs (int a, int len) {
	if (len > longest) {
		longest = len;
		dis = a;	
	}
	else if (len == longest && a < dis)dis = a;
	for ( int i = 0; i < n; i++) 
		if (mat[a][i]) dfs (i, len + 1);
}
void run() {
	longest = 0;
	dis = st;
	dfs(st, 0);
	cout << "The longest path from " << st << " has length " << longest <<", finishing at " << dis + 1 <<"." << endl;
}
int main () {
	int cnt = 0;
	while (1) {
		cin >> n;
		if (n <= 0) break;
		memset ( mat, 0, sizeof (mat));
		cin >> st;
		st--;
		while (1) {
			int a, b;
			cin >> a >> b;	
			if ( a== 0 && b == 0) break;
			mat[a - 1][b - 1] = 1;
		}
		cout << "Case " << ++cnt << ": " ;
		run();	
		cout << endl;
	}
	return 0;	
}