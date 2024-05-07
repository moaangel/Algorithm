#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int n, m, ret;
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
		ret = 0;
		string s, b;
		cin >> s >> b;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == b[0] && i + b.size() - 1 < s.size()) {
				bool flag = 1;
				for (int j = i; j < i + b.size(); j++) {
					if (s[j] != b[j - i])flag = 0;
				}
				if (flag) {
					ret += 1;
					i += b.size() - 1;
				}
				else {
					ret++;
					continue;
				}
			}
			else ret++;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}