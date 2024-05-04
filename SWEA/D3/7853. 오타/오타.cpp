#include <iostream>
#include <string>
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
		string s;
		cin >> s;
		long long ret = 1;
		for (int i = 0; i < s.size(); i++) {
			int temp = 1;
			if (i - 1 >= 0 && s[i - 1] != s[i]) temp++;
			if (i + 1 < s.size() && s[i + 1] != s[i]) {
				temp++;
				if (i - 1 >= 0 && s[i - 1] == s[i + 1])temp--;
			}
			ret = (ret * temp) % 1000000007;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}