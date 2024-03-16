#include <iostream>
#include <string>

using namespace std;

int flag, same, tri;

bool ismoeum(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	else
		return false;
}

int main() {
	string s;

	while (1) {
		flag = 0;
		tri = 0;
		same = 0;
		cin >> s;
		if (s == "end")
			break;

		for (int i = 0; i < s.length(); i++) {
			if (ismoeum(s[i]))
				flag = 1;
		}

		for (int i = 0; i < s.length(); i++) {
			if (i + 2 < s.length()) {
				if (ismoeum(s[i]) && ismoeum(s[i + 1]) && ismoeum(s[i + 2]))
					flag = 0;
				else if (!ismoeum(s[i]) && !ismoeum(s[i + 1]) && !ismoeum(s[i + 2]))
					flag = 0;
			}
		}

		for (int i = 0; i < s.length(); i++) {
			if (i + 1 < s.length()) {
				if (s[i] != 'e' && s[i] != 'o' && s[i] == s[i + 1])
					flag = 0;
			}
		}

		if (flag == 1)
			cout << "<" << s << "> is acceptable." << endl;
		else
			cout << "<" << s << "> is not acceptable." << endl;

	}
}