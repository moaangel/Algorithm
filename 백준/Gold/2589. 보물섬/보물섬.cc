#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int n, m, ret;
int a[51][51];
int visited[51][51];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs(int y, int x) {
	queue<pair<int,int>> q;
	visited[y][x] = 1;

	q.push({ y,x });
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || ny >= n || nx >= m || visited[ny][nx])continue;
			if (a[ny][nx] == 0)continue;

			visited[ny][nx] = visited[y][x] + 1;
			ret = max(ret, visited[ny][nx]);
			q.push({ ny, nx });
			
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'W')
				a[i][j] = 0;
			if (s[j] == 'L')
				a[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				bfs(i, j);
				fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
			}
		}
	}
	cout << ret-1 << endl;
}