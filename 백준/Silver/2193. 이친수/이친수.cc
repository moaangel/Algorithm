#include <iostream>

using namespace std;

long long dp[92][2];
int n;
int main() {
	cin >> n;

	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 1; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
		}
	}

	cout << dp[n][0] + dp[n][1] << '\n';
}