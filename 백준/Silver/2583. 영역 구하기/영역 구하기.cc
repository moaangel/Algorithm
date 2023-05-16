#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int adj[101][101];
int visited[101][101];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int m, n, k,cnt, area;
vector<int> ret;

void dfs(int y, int x) {
	visited[y][x] = 1;
	area++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || ny >= m || nx >= n || !adj[ny][nx]) continue;
		if (!visited[ny][nx]) dfs(ny, nx);
	}
}
int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			adj[i][j] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = b; j < d; j++) {
			for (int k = a; k < c; k++) {
				visited[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j] && !visited[i][j]) {
				area = 0;
				cnt++;
				dfs(i, j);
				ret.push_back(area);
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << cnt << '\n';
	for (int i : ret) cout << i << " ";
}
