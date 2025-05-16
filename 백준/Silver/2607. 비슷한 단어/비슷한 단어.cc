#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

int n, ans;
string word;
int arr[26];
int main() {
	cin >> n;
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		arr[word[i] - 'A']++;
	}
	for (int i = 0; i < n-1; i++) {
		string s;
		int tempArr[26] = { 0, };
		cin >> s;
		if (abs(int(word.length()) - int(s.length())) > 1)continue;
		for (int j = 0; j < s.length(); j++) {
			tempArr[s[j] - 'A']++;
		}
		int cnt = 0;
		bool flag = false;
		for (int j = 0; j < 26; j++) {
			if (abs(arr[j] - tempArr[j]) > 1) {
				flag = true;
			}
			else if (abs(arr[j] - tempArr[j]) == 1) {
				cnt++;
				if (cnt > 2)flag = true;
			}
			if (flag)break;
		}
		if (!flag)ans++;
		
	}
	cout << ans << endl;
}