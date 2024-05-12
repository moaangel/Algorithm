#include<iostream>
#include <string>
using namespace std;

string s;
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
		cin >> s;
		while (s.size() != 1) {
			int temp = 0;
			for (int i = 0; i < s.size(); i++) {
				temp += s[i] - '0';
			}
			s = to_string(temp);
		}
		cout << "#" << test_case << " " << s << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}