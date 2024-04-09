#include <iostream>
#include <algorithm>

using namespace std;

int a[100002];
int n, m, topday;
long long ret = 1000000001;

bool check(int money) {
	if (topday > money)return false;
	int sum = 1;
	int i = 0;
	int havemoney = money;
	while (i != n) {
		if (havemoney < a[i]) {
			sum++;
			havemoney = money;
		}
		havemoney -= a[i];
		i++;
	}
	return m >= sum;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		topday = max(topday, a[i]);
	}
	int l = topday;
	int r = 1000000000;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << '\n';
}
