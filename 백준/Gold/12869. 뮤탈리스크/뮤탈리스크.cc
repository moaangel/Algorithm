#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int _a[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,9,3},
	{1,3,9}
};

int visited[61][61][61];
int dp[61][61][61];
struct SCV
{
	int a,b,c;
};

int n;
int a[3];

int bfs(int a, int b, int c) {
	queue<SCV> q;
	visited[a][b][c] = 1;

	q.push({ a,b,c });
	while (q.size()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (visited[0][0][0])break;
		for (int i = 0; i < 6; i++) {
			int na = max(0,a - _a[i][0]);
			int nb = max(0,b - _a[i][1]);
			int nc = max(0,c - _a[i][2]);

			if (visited[na][nb][nc])continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	}
	return visited[0][0][0] - 1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << bfs(a[0], a[1], a[2]) << endl;
}