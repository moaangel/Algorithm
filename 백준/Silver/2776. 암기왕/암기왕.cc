#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, n, m;
vector<int>v;

int check(int num) {
	int l = 0, r = v.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (v[mid] < num)l = mid + 1;
		else if (v[mid] == num) return 1;
		else r = mid - 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (v.size())v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			cout << check(num) << '\n';			
		}
	}
}