#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


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
		int mx = 0;
		int mn = 100;
		for (int i = 0; i < 10; i++) {
			string s;
			cin >> s;
			int ret = 0;
			for (int j = 0; j < s.size(); j++) {
				ret += s[j] - '0';
			}
			mx = max(mx, ret);
			mn = min(mn, ret);
		}
		cout << "#" << test_case << " " << mx << " " << mn << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}