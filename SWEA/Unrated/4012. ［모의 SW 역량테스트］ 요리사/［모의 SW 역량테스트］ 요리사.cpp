#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,ret;
int a[18][18];

int cal(vector<int> &at, vector<int> &bt) {
	int as = 0, bs = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j) continue;
			as += a[at[i]][at[j]];
			bs += a[bt[i]][bt[j]];
		}
	}
	return abs(as - bs);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 987654321;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int num;
				cin >> num;
				a[i][j] = num;
			}
		}
		for (int i = 0; i < (1 << n); i++) {
			vector<int> ateam, bteam;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j))ateam.push_back(j);
				else bteam.push_back(j);
			}
			if (ateam.size() == n / 2) ret = min(ret, cal(ateam, bteam));
			else {
				if (ateam.size())ateam.clear();
				if (bteam.size())bteam.clear();
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}