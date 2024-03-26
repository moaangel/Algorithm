#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, jx, bx, jy, by,flag,cnt;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int a[301][301];
int visited[301][301];
int main() {
	cin >> n >> m;
	cin >> jy >> jx;
	cin >> by >> bx;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (i == jy - 1 && j == jx - 1) {
				visited[jy - 1][jx - 1] = 1;
				continue;
			}
			if (i == by - 1 && j == bx - 1) {
				a[i][j] = 3;
				continue;
			}
			a[i][j] = s[j] - '0';
		}
	}

	queue<pair<int,int>> q;
	visited[jy - 1][jx - 1] = 1;
	q.push({ jy - 1,jx - 1 });
	while (flag != 1) {
		cnt++;
		queue<pair<int, int>> temp;
		while (q.size()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (flag == 1)
				break;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
				if (visited[ny][nx])continue;
				if (a[ny][nx] == 3) {
					flag = 1;
					break;
				}

				if (a[ny][nx] == 1) {
					temp.push({ ny,nx });
					a[ny][nx] = 0;
				}
				else
					q.push({ ny,nx });
				visited[ny][nx] = 1;				
			}
			
		}
		q = temp;
	}
	cout << cnt;
}
