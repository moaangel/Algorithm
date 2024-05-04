#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


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
		int ret = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (i == 0) {
				ret = num;
				continue;
			}
			ret = max(ret + num, ret*num);
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}