#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 0, 1, 0,-1 };
int dx[4] = { 1, 0, -1, 0 };
int a[102][102], visited[102][102], ja[102][102], jvisited[102][102];
int n, ret, jret;

void dfs(int y, int x, int num) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (a[ny][nx] != a[y][x] || visited[ny][nx])continue;
		dfs(ny, nx, a[ny][nx]);
	}
}

void jdfs(int y, int x, int num) {
	jvisited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (ja[ny][nx] != ja[y][x] || jvisited[ny][nx])continue;
		jdfs(ny, nx, ja[ny][nx]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char co;
			cin >> co;
			if (co == 'R') {
				a[i][j] = 1;
				ja[i][j] = 1;
			}
			else if (co == 'G') {
				a[i][j] = 2;
				ja[i][j] = 1;
			}
			else if (co == 'B') {
				a[i][j] = 3;
				ja[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && a[i][j]) {
				ret++;
				dfs(i,j,a[i][j]);
			}
			if (!jvisited[i][j] && ja[i][j]) {
				jret++;
				jdfs(i, j, ja[i][j]);
			}
		}
	}
	cout << ret << " " << jret << '\n';
}