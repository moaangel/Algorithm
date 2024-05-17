#include <iostream>
#include <string>
using namespace std;

int T,n,ret;
int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			int temp = abs(i - (int)s.size()/2);
			for (int j = temp; j < s.size() - temp; j++) {
				ret += s[j] - '0';
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
}