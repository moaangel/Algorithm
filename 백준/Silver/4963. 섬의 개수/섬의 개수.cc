#include <iostream>

using namespace std;

const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };

int a[51][51];
int visited[51][51];
int m, n;
void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (!a[ny][nx] || visited[ny][nx])continue;
		dfs(ny, nx);
	}
}

int main() {
	while (1) {
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		int ret = 0;		
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] && !visited[i][j]) {
					ret++;
					dfs(i, j);
				}
			}
		}
		cout << ret << '\n';
	}
}