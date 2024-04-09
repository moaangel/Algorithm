#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>po;
vector<int>pi;
int T,n,m,ret;

int check(int posize) {
	int ret = 0;
	int l = 0, r = pi.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (posize > pi[mid]) {
			ret = mid + 1;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ret;
}

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		ret = 0;
		if (po.size())po.clear();
		if (pi.size())pi.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			po.push_back(num);
		}
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			pi.push_back(num);
		}
		sort(pi.begin(), pi.end());
		for (int a : po) {
			ret += check(a);
		}
		cout << ret << '\n';
	}
}