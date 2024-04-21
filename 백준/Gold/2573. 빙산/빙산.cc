#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

vector<pair<int, int>> vlist;
int a[302][302];
int visited[302][302];
int cvisited[302][302];
int temp[302][302];
int n, m,ret;

void check(int y, int x) {
	cvisited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (!a[ny][nx] || cvisited[ny][nx])continue;
		check(ny, nx);
	}
}

void bfs(int y, int x) {
	
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.size()) {
		int qy = q.front().first;
		int qx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = qy + dy[i];
			int nx = qx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
			if (a[ny][nx] == 0) {
				temp[qy][qx]++;
				continue;
			}
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				vlist.push_back({ i,j });
			}
		}
	}

	while (1) {
		fill(&visited[0][0], &visited[0][0] + 302 * 302, 0);
		fill(&temp[0][0], &temp[0][0] + 302 * 302, 0);
		if (vlist.size()) {
			visited[vlist[0].first][vlist[0].second] = 1;
			bfs(vlist[0].first, vlist[0].second);
		}
		if (vlist.size())vlist.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] -= temp[i][j];
				if (a[i][j] > 0)vlist.push_back({ i,j });
				else a[i][j] = 0;
			}
		}
		ret++;
		if (!vlist.size()) {
			ret = 0;
			break;
		}
		else {
			fill(&cvisited[0][0], &cvisited[0][0] + 302 * 302, 0);
			check(vlist[0].first, vlist[0].second);
			bool flag = 0;
			for (int i = 0; i < n; i++) {				
				for (int j = 0; j < m; j++) {
					if (a[i][j] && !cvisited[i][j]) {
						flag = 1;
						break;
					}
				}
				if (flag)break;
			}
			if (flag) break;
			else continue;
		}
	}
	cout << ret << '\n';
}

