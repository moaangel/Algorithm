#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10002];
int visited[10002];
vector<int> ret;
int n, m, mx, temp;

void dfs(int here) {
	temp++;
	visited[here] = 1;

	for (int a : v[here]) {
		if (visited[a]) continue;
		dfs(a);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int b, a;
		cin >> b >> a;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		temp = 0;
		fill(visited, visited + 10002, 0);
		dfs(i);
		if (mx < temp) {
			if (ret.size())ret.clear();
			ret.push_back(i);
			mx = temp;
		}
		else if (mx == temp) ret.push_back(i);
	}
	sort(ret.begin(), ret.end());

	for (int a : ret) {
		cout << a << " ";
	}
	cout << '\n';
	return 0;
}