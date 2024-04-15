#include <iostream>
#include <algorithm>
using namespace std;

int dp[100];
int l[21], j[21];
int n;
int main() {
	dp[0] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> j[i];
	}
	for (int i = 0; i < n; i++) {
		for (int k = 99; k >= l[i]; k--) {
			dp[k] = max(dp[k - l[i]] + j[i], dp[k]);
		}
	}
	cout << dp[99] << '\n';
}