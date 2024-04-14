#include <iostream>
#include <algorithm>
using namespace std;

int dp[100002];
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--) {
			dp[j] = max(dp[j - w] + v, dp[j]);
		}
	}
	cout << dp[k] << '\n';
}