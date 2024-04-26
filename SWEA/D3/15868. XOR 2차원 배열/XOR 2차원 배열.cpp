#include<iostream>
#include<string>
#include<stack>
#include <vector>
using namespace std;

int n, m;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (v.size())v.clear();
		int a[6][6];
		bool flag = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (a[i][0] == a[i + 1][0]) {
				if (v[i] == v[i + 1]) continue;
				else {
					flag = 1;
					break;
				}
			}
			else {
				for (int j = 0; j < m; j++) {
					if (a[i][j] == a[i + 1][j]) {
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag) cout << "#" << test_case << " no" << '\n';
		else cout << "#" << test_case << " yes" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}