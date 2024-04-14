#include <iostream>
#include <algorithm>
using namespace std;

int dp[10002];
int n, k;
int main() {
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		for (int j = temp; j <= k; j++) {
			dp[j] += dp[j-temp];
		}
	}
	cout << dp[k] << '\n';
}