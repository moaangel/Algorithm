#include <iostream>

using namespace std;

int t, n, m;
int a[22];
int dp[10002];
int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		fill(dp, dp + 10002, 0);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= m; j++) {
				dp[j] += dp[j - a[i]];
			}
		}
		cout << dp[m] << '\n';
	}
}