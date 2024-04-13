#include <iostream>
#include <algorithm>
using namespace std;

int a[301];
int dp[301];
int n,ret;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	dp[3] = a[3] + max(a[1], a[2]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 3] + a[i-1], dp[i - 2]) + a[i];
	}

	cout << dp[n] << '\n';
}