#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans = 9999999;
int dp[8][8][3], arr[8][8];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	fill(&dp[0][0][0], &dp[0][0][0] + 64 * 3, 9999999);
	for (int i = 0; i < m; i++) {
		dp[0][i][0] = arr[0][i];
		dp[0][i][1] = arr[0][i];
		dp[0][i][2] = arr[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				dp[i][j][0] = min(arr[i][j] + dp[i - 1][j + 1][1], arr[i][j] + dp[i-1][j+1][2]);
				dp[i][j][1] = arr[i][j] + dp[i - 1][j][0];
			}
			else if (j == m - 1) {
				dp[i][j][1] = arr[i][j] + dp[i - 1][j][2];
				dp[i][j][2] = min(arr[i][j] + dp[i - 1][j-1][1], arr[i][j] + dp[i - 1][j - 1][0]);
			}
			else {
				dp[i][j][0] = min(arr[i][j] + dp[i - 1][j + 1][1], arr[i][j] + dp[i - 1][j + 1][2]);
				dp[i][j][1] = min(arr[i][j] + dp[i - 1][j][0], arr[i][j] + dp[i - 1][j][2]);
				dp[i][j][2] = min(arr[i][j] + dp[i - 1][j - 1][1], arr[i][j] + dp[i - 1][j - 1][0]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		ans = min(ans, min(dp[n - 1][i][1],min(dp[n - 1][i][0],dp[n - 1][i][2])));
	}
	cout << ans << '\n';
}