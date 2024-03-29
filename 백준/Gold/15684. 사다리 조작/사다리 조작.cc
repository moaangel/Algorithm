#include <iostream>
#include <algorithm>

using namespace std;

int n, m, h, ret = 50000;
int visited[35][35];

bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start])start++;
			else if (visited[j][start - 1])start--;
		}
		if (start != i)return false;
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (cnt > 3 || cnt >= ret) {
		return;
	}
	if (check()) {
		ret = min(ret, cnt);
		return;
	}

	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (visited[i][j] || visited[i][j + 1] || visited[i][j - 1])continue;
			visited[i][j] = 1;
			dfs(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}
	dfs(1, 0);
	if (ret == 50000)
		cout << "-1" << endl;
	else
		cout << ret << endl;
}