#include <iostream>

using namespace std;

int t;
int dp[41];
int main() {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 41; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int num;
		cin >> num;
		if (num == 0) {
			cout << 1 << " " << 0 << '\n';
		}
		else if (num == 1) {
			cout << 0 << " " << 1 << '\n';
		}
		else
			cout << dp[num - 1] << " " << dp[num] << '\n';
	}
}