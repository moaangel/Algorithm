// 1. 모음이 있어야 함
// 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안됨.
// 3. 같은 글자가 연속적으로 2번 오면 안됨. 단, ee, oo는 허용한다.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int f;

int isC(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;
	return 0;
}

int isG(char a) {
	if (a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u')
		return 1;
	return 0;
}

int main() {
	cin >> s;
	while (s != "end") {
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				f++; // 1번
			}
		}
		for (int i = 0; i < s.length(); i++) {
			
			if (i + 1 < s.length()) {
				if ((s[i] != 'e' && s[i] != 'o') && s[i] == s[i + 1]) {
					f = 0; // 3번
					break;
				}
			}
			if (i + 2 < s.length()) {
				if (((isC(s[i]) && isC(s[i + 1]) && isC(s[i + 2])) || (isG(s[i]) && isG(s[i + 1]) && isG(s[i + 2])))) {
					f = 0; // 2번
				}
			}
		
		}
		if (f == 0) {
			cout << "<" << s << "> is not acceptable." << '\n';
		}
		if (f) cout << "<" << s << "> is acceptable." << '\n';
		f = 0;
		cin >> s;
	}
	return 0;
}