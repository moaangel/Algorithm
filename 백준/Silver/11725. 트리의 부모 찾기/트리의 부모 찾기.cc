#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[100002];
int visited[100002];
int parent[100002];
void dfs(int here, int p) {
	visited[here] = 1;
	parent[here] = p;

	for (int a : v[here]) {
		if (visited[a])continue;
		dfs(a, here);
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >>  b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}