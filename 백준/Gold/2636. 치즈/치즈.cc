#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int n,m,ret,cnt;
int a[102][102];
int visited[102][102];
queue<pair<int, int>> clist;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	clist.push({ 0,0 });
	while (1) {
		ret++;
		vector<pair<int, int>> lostlist;
		fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
		while (clist.size()) {
			int y = clist.front().first;
			int x = clist.front().second;
			clist.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])continue;
				visited[ny][nx] = 1;
				if (a[ny][nx] == 0) {
					clist.push({ ny,nx });
				}
				else lostlist.push_back({ ny,nx });
			}
		}
		if (lostlist.size()) {
			for (pair<int, int> num : lostlist) {
				a[num.first][num.second] = 0;
			}
			cnt = lostlist.size();
			clist.push({ 0,0 });
		}
		else break;
	}
	cout << ret-1 << '\n' << cnt << '\n';
}