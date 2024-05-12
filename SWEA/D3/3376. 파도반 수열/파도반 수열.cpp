#include<iostream>
#include <string>
using namespace std;

long long dp[102];
int n;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		dp[1] = dp[2] = dp[3] = 1;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << "#" << test_case << " " << dp[n] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}