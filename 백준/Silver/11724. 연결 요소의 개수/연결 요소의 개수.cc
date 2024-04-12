#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<int> v[1002];
int visited[1002];

void dfs(int num) {
	visited[num] = 1;

	for (int a : v[num]) {
		if (visited[a])continue;
		dfs(a);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
}