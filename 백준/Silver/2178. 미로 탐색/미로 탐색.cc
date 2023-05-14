#include <iostream>
#include <stdio.h>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
int a[105][105];
int visited[105][105];

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
		
	}
	int x=0, y=0;
	queue<pair<int, int>> q;
	visited[x][y] = 1;
	q.push({ x,y });
	while (q.size()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
			if (a[nx][ny] == 1) {
				visited[nx][ny] += visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}

	}
	printf("%d", visited[n - 1][m - 1]);
}