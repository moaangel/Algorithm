#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[5][5][100002];
vector<int>v;

int n;

int check(int from, int to) {
	//처음에는 2
	if (from == 0) return 2;
	//다시 누르면 1
	if (from == to) return 1;
	//반대일 경우
	if (abs(from - to) == 2) return 4;
	//인접할 경우
	return 3;
}

int go(int l, int r, int tar) {
	if (tar == n) return 0;
	if (dp[l][r][tar] != -1) return dp[l][r][tar];

	int left = go(v[tar], r, tar + 1) + check(l, v[tar]);
	int right = go(l, v[tar], tar + 1) + check(r, v[tar]);
	return dp[l][r][tar] = min(left, right);
}

int main() {
	while (1) {
		int num;
		cin >> num;
		if (num == 0) break;
		v.push_back(num);
	}
	fill(&dp[0][0][0], &dp[0][0][0] + 5 * 5 * 100002, -1);
	n = v.size();
	cout << go(0, 0, 0) << '\n';
}