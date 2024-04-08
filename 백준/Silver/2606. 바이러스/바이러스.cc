#include <iostream>
#include <vector>

using namespace std;

vector<int> v[102];
int visited[102];
int n, m;

int dfs(int here) {
	visited[here] = 1;
	int ret = 1;
	for (int a : v[here]) {
		if (visited[a])continue;
		ret = ret + dfs(a);
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << dfs(1)-1 << '\n';
}