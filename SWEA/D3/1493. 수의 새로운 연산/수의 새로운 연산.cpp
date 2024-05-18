#include <iostream>
#include <map>
#include <vector>
using namespace std;

int dp[300][300];
map<int, pair<int, int>> itopair;
map<pair<int, int>, int> pairtoi;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	dp[1][1] = 1;

	for (int i = 1; i < 300; i++) {
		dp[i][1] = (i * (i + 1)) / 2;
		pairtoi[{i, 1}] = dp[i][1];
		itopair[dp[i][1]] = make_pair(i, 1);
	}
	for (int j = 2; j < 300; j++) {
		for (int i = 1; i < 300; i++) {
			dp[i][j] = dp[i][j-1] + i + (j-2);
			pairtoi[{i,j}] = dp[i][j];
			itopair[dp[i][j]] = make_pair(i, j);
		}
	}


	for (test_case = 1; test_case <= T; ++test_case)
	{
		int numa, numb;
		cin >> numa >> numb;
		int x = itopair[numa].first + itopair[numb].first;
		int y = itopair[numa].second + itopair[numb].second;
		cout << "#" << test_case << " " << pairtoi[{x, y}] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}