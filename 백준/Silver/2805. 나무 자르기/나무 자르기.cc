#include <iostream>
#include <algorithm>
using namespace std;

long long a[1000002];
long long n, m, l,r, ret;

bool check(int mid) {
	long long temp = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) temp += a[i] - mid;
	}
	return m <= temp;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r = max(r, a[i]);
	}
	l = 1;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ret = max(ret, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ret << '\n';
}