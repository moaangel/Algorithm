#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];
int a[501][501];
int n,ret;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int num;
			cin >> num;
			a[i][j] = num;
		}
	}
	dp[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] += dp[i - 1][j] + a[i][j];
				continue;
			}
			dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[n - 1][i]);
	}
	cout << ret << '\n';
}