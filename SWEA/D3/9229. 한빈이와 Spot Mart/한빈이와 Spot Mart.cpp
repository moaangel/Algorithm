#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a[1002];
vector<int> v;
int T, n, m,ret;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m;
		ret = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j < i; j++) {
				if (a[i] + a[j] > m)break;
				else if (a[i] + a[j] == m) {
					ret = m;
					break;
				}
				else ret = max(ret, a[i] + a[j]);
			}
			if (ret == m) break;
		}
		cout << "#" << tc << " " << ret << '\n';
	}
}