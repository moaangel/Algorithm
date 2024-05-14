#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

queue<pair<int, int>> q;
vector<pair<int, int>> v;
char a[52][52];
int visited[52][52];
int n, m, ret;

void bfs(int sy, int sx) {
	visited[sy][sx] = 1;
	q.push({ sy, sx });

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (a[ny][nx] == 'L' && !visited[ny][nx]) {
				visited[ny][nx] = visited[y][x] + 1;
				ret = max(ret, visited[ny][nx] - 1);
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (s[j] == 'L')v.push_back({ i,j });
		}
	}

	for (pair<int, int> i : v) {
		fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
		bfs(i.first, i.second);
	}

	cout << ret << '\n';
}