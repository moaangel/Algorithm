#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

char a[21][21];
int visited[21][21];
int alphabet[200];

int n, m, cnt;

int dfs(int y, int x) {
	if (visited[y][x] > cnt)
		cnt = visited[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (alphabet[a[ny][nx]] == 1)continue;
		visited[ny][nx] = visited[y][x] + 1;
		alphabet[a[ny][nx]] = 1;
		
		dfs(ny, nx);
		alphabet[a[ny][nx]] = 0;
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	visited[0][0] = 1;
	alphabet[a[0][0]] = 1;

	cout << dfs(0, 0) << endl;
}