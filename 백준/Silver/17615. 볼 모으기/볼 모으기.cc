#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int n;
map<char, int> mp;
char arr[500002];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	if (mp['R'] == 0 || mp['B'] == 0) {
		cout << 0 << endl;
		return 0;
	}
	int leftCnt = 0, rightCnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[0]) {
			leftCnt++;
		}
		else 
			break;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == arr[n - 1]) {
			rightCnt++;
		}
		else 
			break;
	}
	int ans = min(mp[arr[0]] - leftCnt, mp[arr[n - 1]] - rightCnt);
	ans = min(ans, mp['R']);
	ans = min(ans, mp['B']);
	cout << ans << endl;
}