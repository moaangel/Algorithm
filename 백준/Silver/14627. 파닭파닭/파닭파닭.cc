#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll n, m, mx, tt, ret;
vector<ll>pa;

int check(int pasize) {
	int sum = 0;
	for (int i = 0; i < pa.size(); i++) {
		sum += (pa[i] / pasize);
	}
	return sum;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		pa.push_back(num);
		mx = max(mx, num);
		tt += num;
	}
	ll l = 1, r = mx, ret = tt;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid) >= m) {
			ret = tt - (mid * m);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ret << '\n';
}