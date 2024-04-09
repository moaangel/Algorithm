#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int a[27][27];
int visited[27][27];
vector<int>danji;
int n,dannum,cnt;

void dfs(int y, int x, int dang) {
	visited[y][x] = dang;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])continue;
		if (!a[ny][nx])continue;
		dfs(ny, nx, dang);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] && !visited[i][j]) {
				dannum++;
				cnt = 0;
				dfs(i,j,dannum);
				danji.push_back(cnt);
			}
		}
	}

	sort(danji.begin(), danji.end());
	cout << danji.size() << '\n';
	for (int tmp : danji) {
		cout << tmp << '\n';
	}
}