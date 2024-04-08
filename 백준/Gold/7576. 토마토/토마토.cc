#include <iostream>
#include <queue>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int a[1002][1002];
int visited[1002][1002];
int n,m,sy,sx, ret,y,x;
queue<pair<int, int>> q;
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	while (q.size()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
			if (a[ny][nx] == -1)continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j] != -1) {
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}
	if (flag)cout << -1 << '\n';
	else cout << visited[y][x]-1 << '\n';
;}