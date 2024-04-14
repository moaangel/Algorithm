#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];

void go(int num) {
	if (num < 1) return;
	cout << num << " ";
	if (num % 3 == 0 && dp[num / 3] + 1 == dp[num]) go(num / 3);
	else if (num % 2 == 0 && dp[num / 2] + 1 == dp[num]) go(num / 2);
	else if (dp[num - 1]+1 == dp[num])go(num - 1);
}

int main() {
	cin >> n;
	fill(dp, dp + 1000001, 987654321);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0)dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0)dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i - 1]+1, dp[i]);
	}
	cout << dp[n] << '\n';
	go(n);
}