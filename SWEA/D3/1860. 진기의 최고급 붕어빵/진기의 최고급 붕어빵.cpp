#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[11114];
vector<int> v;
int T, n, m, k;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		v.clear();
		fill(a, a + 11114, 0);
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		bool flag = 0;
		int j = 0;
		for (int i = 0; i <= v[v.size()-1]; i++) {
			if (i == 0)a[i] = 0;
			else a[i] = a[i - 1];
			if (i != 0 && i % m == 0)a[i] += k;
			if (i == v[j]) {
				if (a[i] != 0) {
					a[i]--;
					j++;
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag) cout << "#" << tc << " Impossible" << '\n';
		else cout << "#" << tc << " Possible" << '\n';
	}
}