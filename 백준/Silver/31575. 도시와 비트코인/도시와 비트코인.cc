#include <iostream>

using namespace std;


bool dp[302][302];
int a[302][302];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < m; i++) {
		if (dp[0][i - 1] && a[0][i])dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (dp[i - 1][0] && a[i][0]) dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if ((dp[i - 1][j] || dp[i][j - 1]) && a[i][j]) dp[i][j] = 1;
		}
	}
	if (dp[n - 1][m - 1]) cout << "Yes" << '\n';
	else cout << "No" << '\n';

	return 0;
}