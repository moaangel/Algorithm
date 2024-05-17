#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int a[102][102];
int visited[102][102];
int T, n;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		fill(&visited[0][0], &visited[0][0] + 102 * 102, 987654321);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				a[i][j] = s[j] - '0';
			}
		}
		visited[0][0] = 0;
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		while (q.size()) {
			int y = q.front().first;
			int x = q.front().second;

			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (visited[ny][nx] <= visited[y][x] + a[ny][nx])continue;
				visited[ny][nx] = visited[y][x] + a[ny][nx];
				if (visited[ny][nx] > visited[n - 1][n - 1])continue;
				q.push({ ny,nx });
			}
		}

		cout << "#" << tc << " " << visited[n - 1][n - 1] << '\n';
	}
}