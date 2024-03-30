#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k, ret;
int word[51];
int canalpha[26];

int gotest(int mask) {
	int cnt = 0;
	for (int w : word) {
		if (w && (w & mask) == w)cnt++;
	}
	return cnt;
}

int dfs(int idx, int study, int mask) {
	if (study < 0)
		return 0;
	if (idx == 26)
		return gotest(mask);
	int ret = dfs(idx + 1, study - 1, (mask | (1 << idx)));
	if (idx + 'a' != 'a' && idx + 'a' != 'n' &&idx + 'a' != 'c' &&idx + 'a' != 't' &&idx + 'a' != 'i')
		ret = max(ret,dfs(idx + 1, study, mask));
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			word[i] |= (1 << s[j] - 'a');
		}
	}
	cout << dfs(0, k, 0) << '\n';
}