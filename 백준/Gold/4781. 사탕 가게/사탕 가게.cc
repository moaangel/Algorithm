#include <iostream>
#include <algorithm>
using namespace std;

int dp[10004];
int main() {
	while (1) {
		fill(dp, dp + 10004, 0);
		int n;
		double m;
		cin >> n;
		cin >> m;
		int cost = m * 100 + 0.5;
		if (n == 0 && cost == 0)break;
		for (int i = 0; i < n; i++) {
			int cal;
			double p;
			cin >> cal;
			cin >> p;
			int price = p * 100 + 0.5;
			for (int j = price; j <= cost; j++) {
				dp[j] = max(dp[j - price] + cal, dp[j]);
			}
		}
		cout << dp[cost] << '\n';
	}
}