#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a[1002];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout.precision(6);
	cout << fixed;

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		int ret = 0;
		int cnt = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			a[i] = s[i] - '0';
		}

		for (int i = 0; i < s.size(); i++) {
			if (cnt < i) {
				ret += i - cnt;
				cnt += i - cnt;
			}
			cnt += a[i];
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}