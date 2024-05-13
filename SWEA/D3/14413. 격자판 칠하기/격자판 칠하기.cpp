#include<iostream>
#include <queue>
#include <string>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

char a[52][52];
int n, m;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		queue<pair<int,int>> q;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j];
				if (a[i][j] != '?')q.push({ i,j });
			}
		}
		if (q.empty()) {
			cout << "#" << test_case << " possible" << '\n';
			continue;
		}
		bool flag = 0;
		while (q.size()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;

				if (a[ny][nx] != '?') {
					if (a[ny][nx] != a[y][x])continue;
					else {
						flag = 1;
						break;
					}
				}
				else {
					if (a[y][x] == '#') a[ny][nx] = '.';
					else a[ny][nx] = '#';
					q.push({ ny,nx });
				}
			}
			if (flag)break;
		}
		if (flag) cout << "#" << test_case << " impossible" << '\n';
		else cout << "#" << test_case << " possible" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}