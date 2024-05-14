#include <iostream>
#include <vector>
using namespace std;

int n,ret,k,rootnode;
vector<int> v[52];

void dfs(int here) {
	if (!v[here].size())ret++;
	else {
		for (int a : v[here]) {
			if (a == k) {
				if (v[here].size() == 1) ret++;
				continue;
			}
			else dfs(a);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			rootnode = i;
			continue;
		}
		v[num].push_back(i);
	}
	cin >> k;
	if (k == rootnode) {
		cout << 0 << '\n';
		return 0;
	}

	dfs(rootnode);

	cout << ret << '\n';
}