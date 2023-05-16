#include <iostream>

using namespace std;


int n,cnt,maxv=0;
int adj[101][101];
int visited[101][101];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
void dfs(int x, int y, int h) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || !adj[nx][ny]) continue;
		if (adj[nx][ny] > h && !visited[nx][ny]) dfs(nx, ny, h);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i = 0; i < 100; i++) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (adj[x][y] > i && !visited[x][y]) {
					dfs(x, y, i);
					cnt++;
				}
			}
		}
		if (cnt > maxv) maxv = cnt;
		cnt = 0;
	}
	cout << maxv;
}