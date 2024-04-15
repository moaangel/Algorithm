#include <iostream>

typedef long long ll;
using namespace std;

int n;
ll dp[21][102];
int a[102];
ll ret;
ll go(int num, int idx) {
	if (num < 0 || num > 20) return 0;
	ll &ret = dp[num][idx];
	if (ret) return ret;
	if (idx == n - 2) {
		if (num == a[n - 1]) return 1;
		return 0;
	}
	ret += go(num + a[idx+1], idx+1);
	ret += go(num - a[idx+1], idx+1);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << go(a[0], 0) << '\n';
}