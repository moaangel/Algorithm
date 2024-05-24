#include <iostream>
#include <algorithm>

using namespace std;

long long dp[102][102];
int a[102][102];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!a[i][j])continue;
			if (i + a[i][j] < n && dp[i][j]) {
				dp[i + a[i][j]][j] += dp[i][j];
			}
			if (j + a[i][j] < n && dp[i][j]) {
				dp[i][j + a[i][j]] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1] << '\n';
}