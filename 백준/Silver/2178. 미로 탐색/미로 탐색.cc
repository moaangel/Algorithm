#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int a[102][102];
int visited[102][102];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	visited[0][0] = 1;
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (a[ny][nx] == 0 || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	cout << visited[n - 1][m - 1] << '\n';
}