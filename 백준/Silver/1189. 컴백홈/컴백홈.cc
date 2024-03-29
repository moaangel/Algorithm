#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int visited[6][6];
char a[6][6];
vector<pair<int, int>>v;
int n, m, k, sx,sy,ex,ey,ret;

void dfs(int y, int x, int d) {
	if (d > k)
		return;
	if (y == ey && x == ex && d == k) {
		ret++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == 'T')continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, d + 1);
		visited[ny][nx] = 0;
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	sy = n - 1;
	sx = 0;
	ey = 0;
	ex = m - 1;

	visited[sy][sx] = 1;
	dfs(sy, sx, 1);
	cout << ret << endl;
}