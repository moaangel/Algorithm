#include <iostream>
#include <algorithm>
using namespace std;

int dp[10002];
int n, k;
int main() {
	fill(dp, dp + 10002, 200000);
	dp[0] = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		for (int j = temp; j <= k; j++) {
			dp[j] = min(dp[j - temp] + 1, dp[j]);
		}
	}
	if (dp[k] == 200000)
		cout << -1 << '\n';
	else
		cout << dp[k] << '\n';
}