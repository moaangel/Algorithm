#include <iostream>

using namespace std;

long long dp[1000002];
int n, t;
int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int i = 5; i < 1000001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}