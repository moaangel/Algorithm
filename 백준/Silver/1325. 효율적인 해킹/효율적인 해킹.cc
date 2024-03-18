#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m,go, best,bestnum;
vector<int> com[10001];
int visited[10001];
vector<int> ret;

int dfs(int i) {
	visited[i] = 1;
	int cnt = 1;
	for (int a : com[i]) {
		if (!visited[a])
			cnt += dfs(a);
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int here, there;
		cin >> there >> here;
		com[here].push_back(there);
	}

	for (int i = 0; i <= n; i++) {
		fill(&visited[0], &visited[0] + 10001, 0);
		if (com[i].size() && !visited[i]) {
			go = dfs(i);
			if (go > best) {
				best = go;
				if (ret.size()) {
					ret.clear();
					ret.push_back(i);
				}
				else
					ret.push_back(i);
			}
			else if (go == best)
				ret.push_back(i);
		}
	}

	sort(ret.begin(), ret.end());

	for (int a : ret) {
		cout << a << " ";
	}
}