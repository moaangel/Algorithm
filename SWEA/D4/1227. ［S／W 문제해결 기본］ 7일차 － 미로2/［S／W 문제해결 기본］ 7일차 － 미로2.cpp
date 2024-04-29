#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int dy[4] = { 1,0,0,-1 };
int dx[4] = { 0,1,-1,0 };

int a[102][102];
int visited[102][102];
int ret, sy,sx;

void dfs(int y, int x) {
	if (a[y][x] == 3) {
		ret = 1;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100)continue;
		if (a[ny][nx] == 1 || visited[ny][nx])continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;
	}
}
   
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
		ret = 0;
		int n;
		cin >> n;
		for (int i = 0; i < 100; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 100; j++) {
				a[i][j] = s[j] - '0';
				if (a[i][j] == 2) {
					sy = i;
					sx = j;
				}
			}
		}
		visited[sy][sx] = 1;
		dfs(sy, sx);
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}
