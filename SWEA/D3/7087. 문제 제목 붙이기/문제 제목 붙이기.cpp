#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a[26];
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
		fill(a, a + 26, 0);
		int ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			a[s[0] - 'A']++;
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] == 0)break;
			ret++;
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}