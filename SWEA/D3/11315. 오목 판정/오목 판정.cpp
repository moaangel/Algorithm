#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

char a[22][22];
int visited[22][22];
int n;
bool flag;

void dfs(int y, int x, int dir, int cnt) {
	if (cnt == 5) {
		flag = 1;
		return;
	}

	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny < 0 || nx < 0 || ny >= n || nx >= n) return;
	if (a[ny][nx] == 'o')dfs(ny, nx, dir, cnt + 1);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		flag = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				a[i][j] = s[j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'o') {
					for (int k = 0; k < 8; k++) {
						dfs(i, j, k, 1);
					}
				}
			}
		}

		if (flag) cout << "#" << test_case << " YES" << '\n';
		else cout << "#" << test_case << " NO" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}