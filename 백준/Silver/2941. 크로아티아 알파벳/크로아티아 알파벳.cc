#include <iostream>
#include <string>

using namespace std;

int cnt;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i + 1 < s.size() && (s[i] == 'l' || s[i] == 'n')) {
			if (s[i + 1] == 'j') {
				cnt++;
				i++;
				continue;
			}
		}
		if (i + 1 < s.size() && (s[i] == 'c' || s[i] == 's' || s[i] == 'z')) {
			if (s[i + 1] == '=') {
				cnt++;
				i++;
				continue;
			}
		}
		if (i + 1 < s.size() && (s[i] == 'c' || s[i] == 'd')) {
			if (s[i + 1] == '-') {
				cnt++;
				i++;
				continue;
			}
		}
		if (i + 2 < s.size() && s[i] == 'd') {
			if (s[i + 1] == 'z' && s[i+2] == '=') {
				cnt++;
				i+=2;
				continue;
			}
		}
		cnt++;
	}
	cout << cnt << endl;
}