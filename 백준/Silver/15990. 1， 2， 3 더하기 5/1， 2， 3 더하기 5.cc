#include <iostream>

using namespace std;

long long dp[100002][4];
long long dpsum[100002];
int t;
int main() {
	cin >> t;
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	dpsum[1] = 1;
	dpsum[2] = 1;
	dpsum[3] = 3;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
		dpsum[i] = (dp[i][1] + dp[i][2] + dp[i][3]) % 1000000009;
	}
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;

		cout << dpsum[n] << '\n';
	}
}