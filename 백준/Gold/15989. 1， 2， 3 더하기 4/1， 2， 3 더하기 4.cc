#include <iostream>

using namespace std;

int dp[10002];
int t;
int main() {
	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (j >= i)dp[j] += dp[j - i];
		}
	}
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}