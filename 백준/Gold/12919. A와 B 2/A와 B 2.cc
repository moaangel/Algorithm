#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;
int ret;

void go(string str) {
	if (str.length() == s.length()) {
		if (str == s)ret = 1;
		return;
	}
	if (str[str.size() - 1] == 'A') {
		string temp = str.substr(0, str.length() - 1);
		go(temp);
	}
	if (str[0] == 'B') {
		string temp = "";
		for (int i = str.length() - 1; i > 0; i--) {
			temp += str[i];
		}
		go(temp);
	}

}

int main() {
	cin >> s >> t;

	go(t);
	cout << ret << '\n';
}