#include<iostream>

using namespace std;

int dy[3] = { -1,0,0 };
int dx[3] = { 0,-1,1 };

int a[102][102];
int visited[102][102];
int ret;

int check(int y, int x) {
	if (x < 99 && a[y][x + 1] && !visited[y][x + 1]) return 2;
	else if (x >= 1 && a[y][x - 1] && !visited[y][x - 1]) return 1;
	return 0;
}

int dfs(int y, int x) {
	if (y == 0) {
		return x;
	}
	visited[y][x] = 1;

	int dir = check(y, x);
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	dfs(ny, nx);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int t;
		cin >> t;
		fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
		fill(&a[0][0], &a[0][0] + 102 * 102, 0);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < 100; i++) {
			if (a[99][i] == 2) {
				ret = dfs(99, i);
				break;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}