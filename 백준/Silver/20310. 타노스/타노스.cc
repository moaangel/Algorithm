#include <iostream>
#include <string>

using namespace std;

int arr[2];

string s;
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0')arr[0]++;
		else arr[1]++;
	}
	arr[0] /= 2;
	arr[1] /= 2;
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			if (arr[0]) {
				ans += '0';
				arr[0]--;
			}
		}
		else {
			if (arr[1]) {
				arr[1]--;
			}
			else ans += '1';
		}
	}
	cout << ans << endl;

}