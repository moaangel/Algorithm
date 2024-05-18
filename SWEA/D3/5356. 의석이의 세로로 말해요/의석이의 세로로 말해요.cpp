#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<string> v;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int mxsize = 0;
		v.clear();
		for (int i = 0; i < 5; i++) {
			string s;
			cin >> s;
			mxsize = max(mxsize, (int)s.size());
			v.push_back(s);
		}
		cout << "#" << tc << " ";
		int i = 0;
		while (i < mxsize) {
			if (v[0].size() - 1 >= i) cout << v[0][i];
			if (v[1].size() - 1 >= i) cout << v[1][i];
			if (v[2].size() - 1 >= i) cout << v[2][i];
			if (v[3].size() - 1 >= i) cout << v[3][i];
			if (v[4].size() - 1 >= i) cout << v[4][i];
			i++;
		}
		cout << '\n';
	}
}