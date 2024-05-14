#include <iostream>
#include <algorithm>
using namespace std;

int a[100002];
int dp[100002][2][2];
int n,ret;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1][0][0] = a[1];
	dp[2][1][0] = a[1] + a[2] / 2;
	dp[2][0][0] = a[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0][0] = a[i] + max(dp[i - 3][0][0], max(dp[i - 3][1][0], dp[i - 3][0][1]));
		dp[i][1][0] = a[i]/2 + max(dp[i - 1][0][0],  dp[i - 1][0][1]);
		dp[i][0][1] = a[i] + max(dp[i - 2][0][0], max(dp[i - 2][1][0], dp[i - 2][0][1]));
	}
	ret = max(dp[n][0][0], max(dp[n][1][0], dp[n][0][1]));
	cout << ret << '\n';
}