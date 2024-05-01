#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int a[102];
string ret;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		fill(a, a + 102, 0);
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (s[i] == s[j] && a[i] == 0 && a[j] == 0) {
					a[i] = 1; a[j] = 1;
				}
			}
		}
		ret.clear();
		for (int i = 0; i < s.size(); i++) {
			if (a[i] == 0)ret += s[i];
		}
		if (ret.size()) {
			sort(ret.begin(), ret.end());
			cout << "#" << test_case << " " << ret << '\n';
		}
		else cout << "#" << test_case << " Good" << '\n';
	}
	return 0;
}