#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <tuple>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n, m, ret, cnt;
int a[8][8];
int visited[8][8];
vector<pair<int, int>> walllist;
vector<pair<int, int>> virlist;

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n || a[ny][nx] == 1 || visited[ny][nx] == 1 || a[ny][nx] == 1)continue;
		dfs(ny, nx);
	}
}

int solve() {
	fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2 && !visited[i][j])
				dfs(i, j);
		}
	}
	/*
	for (pair<int, int> b : virlist) {
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}*/

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)walllist.push_back({ i,j });
			if (a[i][j] == 2)virlist.push_back({ i,j });
		}
	}

	for (int i = 0; i < walllist.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[walllist[i].first][walllist[i].second] = 1;
				a[walllist[j].first][walllist[j].second] = 1;
				a[walllist[k].first][walllist[k].second] = 1;
				ret = max(ret, solve());
				a[walllist[i].first][walllist[i].second] = 0;
				a[walllist[j].first][walllist[j].second] = 0;
				a[walllist[k].first][walllist[k].second] = 0;
			}
		}
	}

	cout << ret << endl;
} 