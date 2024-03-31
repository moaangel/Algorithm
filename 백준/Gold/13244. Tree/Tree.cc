#include <iostream>
#include <vector>

using namespace std;


vector<int>v[1001];
int visited[1001];
int t, n, m;


void dfs(int here) {
	visited[here] = 1;

	for (int a : v[here]) {
		if (visited[a])continue;
		dfs(a);
	}
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		bool flag = 0;
		for (int q = 0; q < 1002; q++) {
			v[q].clear();
		}
		fill(visited, visited + 1001, 0);
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				dfs(j);
				cnt++;
			}
		}
		if (cnt == 1 && n - 1 == m)flag = 1;
		if (flag)cout << "tree" << endl;
		else cout << "graph" << endl;
	}
}