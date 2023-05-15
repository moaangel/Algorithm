#include <iostream>

using namespace std;

int adj[51][51];
int visited[51][51];
int t, m, n, k,x,y, cnt,ny,nx;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
		if (adj[ny][nx] == 1 && !visited[ny][nx])
			dfs(ny, nx);
		
	}

}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--) {
		fill(&adj[0][0], &adj[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			adj[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (adj[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}