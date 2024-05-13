#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int a[102][102];
int visited[102][102];
int n,ret=1,mn=101,mx;

void dfs(int y, int x, int high) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (a[ny][nx] <= high || visited[ny][nx])continue;
		dfs(ny, nx, high);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			mn = min(mn, a[i][j]);
			mx = max(mx, a[i][j]);
		}
	}

	for (int h = mn; h < mx; h++) {
		fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > h && !visited[i][j]) {
					temp++;
					dfs(i, j, h);
				}
			}
		}
		ret = max(ret, temp);
	}

	cout << ret << '\n';
}