#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int dy[3] = { 1,0,0 };
int dx[3] = { 0,1,-1 };

int a[102][102];
int visited[102][102];
int retcnt,cnt,ret;

void dfs(int y, int x, int c) {
	visited[y][x] = 1;
	if (y == 99) {
		cnt = c;
		return;
	}

	if (x + 1 < 100 && a[y][x + 1] && !visited[y][x + 1])dfs(y, x + 1, c + 1);
	else if (x - 1 >= 0 && a[y][x - 1] && !visited[y][x - 1])dfs(y, x - 1, c + 1);
	else dfs(y + 1, x, c + 1);
}
         
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		retcnt = 100000;
		int n;
		cin >> n;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 100; i++) {
			if (a[0][i]) {
				fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
				cnt = 0;
				dfs(0,i,1);
				if (cnt <= retcnt) {
					retcnt = cnt;
					ret = i;
				}
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}
