#include<iostream>
#include<string>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int a[18][18];
int visited[18][18];
int sy, sx, ey, ex, ret;

void dfs(int y, int x) {
	if (y == ey && x == ex) {
		ret = 1;
		return;
	}
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 16 || nx >= 16)continue;
		if (a[ny][nx] == 1 || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	T= 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 0;
		int t;
		cin >> t;
		fill(&a[0][0], &a[0][0] + 18 * 18, 0);
		fill(&visited[0][0], &visited[0][0] + 18 * 18, 0);

		for (int i = 0; i < 16; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < 16; j++) {
				a[i][j] = temp[j] - '0';
				if (a[i][j] == 2) {
					sy = i;
					sx = j;
				}
				if (a[i][j] == 3) {
					ey = i;
					ex = j;
				}
			}
		}
		dfs(sy, sx);

		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}