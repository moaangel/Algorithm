#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[1002];
int T,n,k,ret;

void check(string s) {
	if (s.size() == 1) ret = max(ret, stoi(s));

	else {
		bool flag = 0;
		for (int i = 0; i < s.size()-1; i++) {
			if (s[i]-'0' <= s[i + 1]-'0')continue;
			else flag = 1;
		}
		if (flag) return;
		else ret = max(ret, stoi(s));
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fill(a, a + 1002, 0);
		ret = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = a[i] * a[j];
				if (ret < temp)
					check(to_string(temp));
			}
		}
		cout << "#" << tc << " " << ret << '\n';
	}
}