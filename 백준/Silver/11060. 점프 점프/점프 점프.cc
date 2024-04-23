#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int a[1002];
int dp[1111];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fill(dp, dp + 1111, INF);
	dp[1] = 0;
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		for (int j = 1; j <= temp; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n] == INF)cout << -1 << '\n';
	else cout << dp[n] << '\n';
}