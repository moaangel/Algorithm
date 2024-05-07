#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

char a[22][22];
int visited[26];
int n, m, ret;

void dfs(int y, int x, int cnt) {
	ret = max(ret, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (visited[a[ny][nx] - 'A'])continue;
		visited[a[ny][nx] - 'A'] = 1;
		dfs(ny, nx, cnt + 1);
		visited[a[ny][nx] - 'A'] = 0;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout.precision(6);
	cout << fixed;

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		ret = 0;
		fill(visited, visited + 26, 0);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j];
			}
		}
		visited[a[0][0] - 'A'] = 1;
		dfs(0, 0, 1);
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}