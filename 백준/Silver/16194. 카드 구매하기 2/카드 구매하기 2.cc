#include <iostream>
#include <algorithm>

using namespace std;

int dp[1002];
int n;
int a[1002];
int main() {
	fill(dp, dp + 1002, 1000000000);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = min(dp[j - i] + a[i], dp[j]);
		}
	}
	cout << dp[n] << '\n';
}