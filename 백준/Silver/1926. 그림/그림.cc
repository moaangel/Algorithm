#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt, ret;
int a[502][502];
int visited[502][502];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int dfs(int y, int x) {
	visited[y][x] = 1;

	int r = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])continue;
		if (!a[ny][nx])continue;
		r += dfs(ny, nx);
	}

	return r;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j]) {
				cnt++;
				ret = max(ret, dfs(i, j));
			}
		}
	}

	cout << cnt << '\n' << ret << '\n';
}