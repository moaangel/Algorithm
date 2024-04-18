#include <iostream>
#include <vector>
using namespace std;

vector<int> v[102];
int visited[102];
int n, ps1,ps2, m;

void dfs(int person) {
	if (person == ps2)
		return;

	for (int a : v[person]) {
		if (visited[a])continue;
		visited[a] = visited[person] + 1;
		dfs(a);
	}
}

int main() {
	cin >> n;
	cin >> ps1 >> ps2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int parent, son;
		cin >> parent >> son;
		v[parent].push_back(son);
		v[son].push_back(parent);
	}
	visited[ps1] = 1;
	dfs(ps1);

	if (visited[ps2])cout << visited[ps2] - 1 << '\n';
	else cout << -1 << '\n';
}