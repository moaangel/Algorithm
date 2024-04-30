#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[10002];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(dp, dp + 10002, 0);
		int a[100];
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		dp[0] = 1;
		dp[sum] = 1;
		for (int i = 0; i < n; i++) {
			int num = a[i];
			for (int j = sum-1; j >= 0; j--) {
				if (dp[j]) dp[j + num]++;
			}
		}
		int ret = 0;
		for (int i = 0; i <= sum; i++) {
			if (dp[i]) ret++;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}