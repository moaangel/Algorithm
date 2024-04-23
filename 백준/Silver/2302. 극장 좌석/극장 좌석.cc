#include <iostream>
#include <vector>
using namespace std;

int dp[42];
int a[42];
int n,m;
int ret = 1;
vector<int> v;
int main() {
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 42; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		a[num] = 1;
	}
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			if (temp) {
				v.push_back(temp);
				temp = 0;
			}
		}
		else
			temp++;
	}
	if (temp) v.push_back(temp);
	if (v.size()) {
		for (int num : v) {
			ret *= dp[num];
		}
	}
	cout << ret << '\n';
}