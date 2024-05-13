#include<iostream>

using namespace std;

int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };

int dp[18][18][3];
int a[18][18];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (i == 0) {
				if (j < n && a[i][j] != 1) dp[i][j][0] = dp[i][j - 1][0];
				
				continue;
			}
			if (a[i][j] != 1) {
				dp[i][j][2] += (dp[i - 1][j][2] + dp[i-1][j][1]);
				dp[i][j][0] += (dp[i][j - 1][1] + dp[i][j-1][0]);
				if (a[i - 1][j] == 0 && a[i][j - 1] == 0)
					dp[i][j][1] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
			}
		}
	}
	int ret = 0;
	ret += (dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2]);
	cout << ret << '\n';
}