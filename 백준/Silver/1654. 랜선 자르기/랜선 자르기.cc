#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[10002];
ll n, k, l,r,ret;

bool check(ll mid) {
	ll temp = 0;
	for (int i = 0; i < n; i++) {
		temp += a[i] / mid;
	}
	return k <= temp;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		r += a[i];
	}
	l = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;

		if (check(mid)) {
			ret = max(ret, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ret << '\n';
}