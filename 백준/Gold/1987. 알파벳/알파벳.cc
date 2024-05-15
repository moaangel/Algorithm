#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int visited[26];
char a[22][22];
int n, m,ret;

void dfs(int y, int x, int cnt) {
	ret = max(ret, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (visited[a[ny][nx] - 'A']) continue;
		visited[a[ny][nx] - 'A'] = 1;
		dfs(ny, nx, cnt + 1);
		visited[a[ny][nx] - 'A'] = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	visited[a[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret << '\n';
}