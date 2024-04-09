#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;


int a[300003];
int n, m, r;
ll ret = 1000000000;

bool check(int mid) {
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		sum += a[i] / mid;
		if (a[i] % mid)
			sum++;
	}
	return n >= sum;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		r = max(a[i], r);
	}
	int l = 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if(check(mid)){
			ret = min(ret, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << '\n';
}