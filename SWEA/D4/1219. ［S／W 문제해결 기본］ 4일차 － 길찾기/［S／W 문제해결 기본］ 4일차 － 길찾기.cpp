#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int T = 10;
int gbg, n, ret;
vector<int> v[102];

void dfs(int here) {
	if (ret) return;
	if (here == 99) {
		ret = 1;
		return;
	}

	for (int a : v[here]) {
		dfs(a);
	}
}

int main() {
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 102; i++) {
			if (v[i].size())v[i].clear();
		}
		ret = 0;
		cin >> gbg >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		dfs(0);
		cout << "#" << tc << " " << ret << '\n';
	}
}