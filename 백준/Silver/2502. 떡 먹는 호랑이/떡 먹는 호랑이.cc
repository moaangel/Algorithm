#include <iostream>

using namespace std;

int dp[32][2];
int d, k, ret1, ret2;
int main() {
	cin >> d >> k;

	dp[1][0] = 1;
	dp[2][1] = 1;
	for (int i = 3; i <= d; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j++) {
			if ((dp[d][0] * i) + (dp[d][1] * j) == k) {
				ret1 = i;
				ret2 = j;
				break;
			}
		}
		if (ret1)break;
	}
	cout << ret1 << '\n' << ret2 << '\n';
}