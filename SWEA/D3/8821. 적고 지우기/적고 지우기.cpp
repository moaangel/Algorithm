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
		int ret = 0;
		int a[10] = { 0, };
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (a[s[i] - '0'] == 1) a[s[i] - '0'] = 0;
			else a[s[i] - '0'] = 1;
		}
		for (int i = 0; i < 10; i++) {
			if (a[i]) ret++;
		}
;		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}