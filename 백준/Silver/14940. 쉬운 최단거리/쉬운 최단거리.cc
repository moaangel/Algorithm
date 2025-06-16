#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, targetY, targetX;
int arr[1002][1002];
int visited[1002][1002];

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				targetY = i;
				targetX = j;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({ targetY,targetX });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (arr[ny][nx] == 0) visited[ny][nx] = 99999999;
			if (arr[ny][nx] == 1 && visited[ny][nx] == 0) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 99999999) {
				cout << 0 << " ";
			}
			else {
				if (arr[i][j] == 1 && visited[i][j] == 0)
					cout << -1 << " ";
				else
	 				cout << visited[i][j] << " ";
			}
		}
		cout << '\n';
	}
}