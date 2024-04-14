#include <iostream>

using namespace std;

long long dp[102];
int t;
int main() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 3;
	dp[6] = 4;
	dp[7] = 5;
	for (int i = 8; i < 102; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int num;
		cin >> num;
		cout << dp[num - 1] << '\n';
	}
}