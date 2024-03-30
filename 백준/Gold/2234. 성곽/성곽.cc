#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

int a[51][51];
int visited[51][51];
int n, m, cnt, bigroom, plusroom;
int roomsize[2505];

int dfs(int y, int x, int roomcnt) {
	if (visited[y][x]) return 0;
	visited[y][x] = roomcnt;

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		if (!(a[y][x] & (1 << i))) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			ret += dfs(ny, nx, roomcnt);
		}
	}
	return ret;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				cnt++;
				roomsize[cnt] = dfs(i, j, cnt);
				bigroom = max(bigroom, roomsize[cnt]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n) {
				if (visited[i][j] != visited[i + 1][j])
					plusroom = max(plusroom, roomsize[visited[i][j]] + roomsize[visited[i + 1][j]]);
			}
			if (j + 1 < m) {
				if (visited[i][j] != visited[i][j + 1])
					plusroom = max(plusroom, roomsize[visited[i][j]] + roomsize[visited[i][j + 1]]);
			}
		}
	}
	cout << cnt << '\n' << bigroom << '\n' << plusroom << endl;

}

