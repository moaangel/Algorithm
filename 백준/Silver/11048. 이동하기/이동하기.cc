#include <iostream>
#include <algorithm>
using namespace std;

int a[1002][1002];
int dp[1002][1002];
int n, m;


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j] + a[i][j], dp[i][j]);
			dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j]);
			dp[i][j] = max(dp[i][j - 1] + a[i][j], dp[i][j]);
		}
	}
	cout << dp[n][m] << '\n';

}