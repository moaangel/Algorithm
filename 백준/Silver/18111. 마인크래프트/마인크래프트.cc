#include <iostream>
#include <algorithm>

using namespace std;

int n, m, b, mn = 257, mx = -1,ret = 1000000000, reth;
int a[502][502];
void go(int h, int cnt) {
	int temp = cnt;
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == h)continue;
			else if (a[i][j] > h){
				temp += (a[i][j] - h);
				t += (a[i][j] - h) * 2;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == h)continue;
			else if (a[i][j] < h) {
				if (temp < (h - a[i][j])) {
					return;
				}
				else {
					temp -= (h - a[i][j]);
					t += (h - a[i][j]);
				}
			}
		}
	}
	if (ret > t) {
		ret = t;
		reth = h;
	}
	else if (ret == t) {
		if (reth <= h) reth = h;
	}
}

int main() {
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			mn = min(mn, a[i][j]);
			mx = max(mx, a[i][j]);
		}
	}
	reth = mn;
	if (mx > 256) mx = 256;
	for (int i = mn; i <= mx; i++) {
		go(i, b);
	}
	if (mn == mx) {
		ret = 0;
	}
	cout << ret << " " << reth << '\n';
}