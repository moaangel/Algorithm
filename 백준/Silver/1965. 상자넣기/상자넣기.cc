#include <iostream>
#include <algorithm>
using namespace std;

int dp[1002];
int a[1002];
int n,ret;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp[i]);
	}
	cout << ret << '\n';
}