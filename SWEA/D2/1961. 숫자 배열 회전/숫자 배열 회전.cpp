#include<iostream>
#include<vector>
#include <string>
using namespace std;

int n;
int a[8][8];
vector<string> v[8];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 8; i++) {
			if (v[i].size())v[i].clear();
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			string s = "";
			for (int j = n - 1; j >= 0; j--) {
				s += to_string(a[j][i]);
			}
			v[i].push_back(s);
		}
		for (int i = n - 1; i >= 0; i--) {
			string s = "";
			for (int j = n - 1; j >= 0; j--) {
				s += to_string(a[i][j]);
			}
			v[(n-1) - i].push_back(s);
		}
		for (int j = n - 1; j >= 0; j--) {
			string s = "";
			for (int i = 0; i < n; i++) {
				s += to_string(a[i][j]);
			}
			v[(n-1) - j].push_back(s);
		}
		cout << "#" << test_case << '\n';
		for (int i = 0; i < n; i++) {
			for (string temp : v[i]) {
				cout << temp << " ";
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}