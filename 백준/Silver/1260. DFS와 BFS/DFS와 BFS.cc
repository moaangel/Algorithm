#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[1001];
int visited[1001];
int n, m, s;

void bfs(int here) {
	queue<int> q;
	visited[here] = 1;
	q.push(here);
	while (q.size()) {
		int to = q.front();
		cout << to << " ";
		q.pop();
		for (int a : v[to]) {
			if (visited[a])continue;
			visited[a] = 1;
			q.push(a);
		}
	}
}

void dfs(int here){
	visited[here] = 1;
	cout << here << " ";
	for (int a : v[here]){
		if (!visited[a])
			dfs(a);
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(s);
	cout << '\n';
	fill(visited, visited + 1001, 0);
	bfs(s);
}