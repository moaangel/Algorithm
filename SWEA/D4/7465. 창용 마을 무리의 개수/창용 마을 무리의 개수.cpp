#include <iostream>
#include <vector>
using namespace std;
   
vector<int> v[102];
int visited[102];
int n, m, ret;

void dfs(int here) {
	visited[here] = 1;

	for (int a : v[here]) {
		if (!visited[a])
			dfs(a);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 102; i++) {
			if (v[i].size())v[i].clear();
		}
		ret = 0;
		fill(visited, visited + 102, 0);
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				ret++;
				dfs(i);
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}
