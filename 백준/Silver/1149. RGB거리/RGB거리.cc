#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002][3];
int n;
int main() {
	cin >> n;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;

		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + b;
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}