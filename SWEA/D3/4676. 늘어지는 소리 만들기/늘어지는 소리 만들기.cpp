#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a[21];
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
		fill(a, a + 21, 0);
		string s;
		cin >> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			a[num]++;
		}
		string ret;
		for (int i = 0; i <= s.size(); i++) {
			if (i == s.size()) {
				if (a[s.size()]) {
					for (int j = 0; j < a[s.size()]; j++) {
						ret += '-';
					}
				}
				continue;
			}
			if (a[i]) {
				for (int j = 0; j < a[i]; j++) {
					ret += '-';
				}
			}
			ret += s[i];
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}