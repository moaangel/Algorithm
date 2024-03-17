#include <iostream>
#include <vector>

using namespace std;


int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int a[101][101];
int visited[101][101];

vector<pair<int, int>> v;

int n, m, t, lastsize;

void dfs(int y, int x) {
	visited[y][x] = 1;

	if (a[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (1) {
		bool flag = 0;
		v.clear();
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		dfs(0, 0);
		for (pair<int, int> b : v) {
			a[b.first][b.second] = 0;
		}
		lastsize = v.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) flag = 1;
			}
		}
		t++;
		if (!flag)break;
		
	}
	cout << t << "\n" << lastsize << endl;
}