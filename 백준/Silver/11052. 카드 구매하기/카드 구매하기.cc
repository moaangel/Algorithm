#include <iostream>
#include <algorithm>

using namespace std;

int dp[1002];
int a[1002];
int n,ret;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int temp = a[i];
		for (int j = i; j <= n; j++) {
			dp[j] = max(dp[j - i] + temp, dp[j]);
		}
	}
	cout << dp[n] << '\n';
}