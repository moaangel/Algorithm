#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

char a[52][52];
int visited[52][52];
int water[52][52];
int n, m,sy,sx,ey,ex;

queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	fill(&water[0][0], &water[0][0] + 52 * 52, 10000);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			if (a[i][j] == '*') {
				q.push({ i,j });
				water[i][j] = 1;
			}
			if (a[i][j] == 'D') {
				ey = i;
				ex = j;
			}
		}
	}
	
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (a[ny][nx] == 'D' || a[ny][nx] == 'X' || water[ny][nx] != 10000)continue;
			water[ny][nx] = water[y][x] + 1;
			q.push({ ny,nx });
		}
	}

	visited[sy][sx] = 1;
	queue<pair<int, int>> walk;
	walk.push({ sy,sx });
	while (walk.size()) {
		int y = walk.front().first;
		int x = walk.front().second;

		walk.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (a[ny][nx] == '*' || a[ny][nx] == 'X' || visited[y][x] + 1 >= water[ny][nx] || visited[ny][nx])continue;
			visited[ny][nx] = visited[y][x] + 1;
			walk.push({ ny,nx });
		}
	}

	if (!visited[ey][ex]) cout << "KAKTUS" << '\n';
	else cout << visited[ey][ex] - 1 << '\n';
}