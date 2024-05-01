#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int a[1002];
int n;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = a[i] * a[j];
				string s = to_string(temp);
				bool flag = 1;
				for (int k = 0; k < s.size() - 1; k++) {
					if (s[k] - '0' + 1 != s[k + 1] - '0') {
						flag = 0;
						break;
					}
				}
				if (flag) ret = max(ret, temp);
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}