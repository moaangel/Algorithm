#include <iostream>

using namespace std;
typedef long long ll;
ll dp[501];
ll n;

ll fibo(ll num) {
	if (num == 0 || num == 1)return 1;

	if (dp[num]) return dp[num];

	return dp[num] = fibo(num - 1) + fibo(num - 2);
}

int main() {
		cin >> n;
		cout << fibo(n - 1) << '\n';
	
}