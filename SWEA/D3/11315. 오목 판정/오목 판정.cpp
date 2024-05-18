#include <iostream>

using namespace std;

int dy[4] = { 0,1,1,1 };
int dx[4] = { 1,1,0,-1 };

char a[22][22];
int T,n,p;
bool flag;
void check(int y, int x, int dir) {
	int temp = 1;
	int ny = y, nx = x;
	while (1) {
		if (temp == 5) {
			flag = 1;
			return;
		}
		
		ny += dy[dir];
		nx += dx[dir];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
		if (a[ny][nx] != 'o')break;
		else temp++;
	}
}

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (a[ny][nx] == 'o')check(y, x, i);
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		flag = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'o')
					dfs(i, j);
			}
		}
		cout << "#" << tc << " ";
		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}