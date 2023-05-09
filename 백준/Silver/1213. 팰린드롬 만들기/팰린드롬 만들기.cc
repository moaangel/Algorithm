#include <iostream>
#include <string>

using namespace std;
int a[100];
int f;
string ret;
char mid;
int main() {
	string name;

	cin >> name;

	for (int i = 0; i < name.length(); i++){
		a[name[i]]++;
	}

	for (int i = 'Z'; i >= 'A'; i--) {
		if (a[i]) {
			if (a[i] % 2 == 1) {
				mid = char(i);
				f++;
				a[i]--;
			}
			if (f == 2) break;
			for (int j = 0; j < a[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	if (mid) ret.insert(ret.begin() + ret.length() / 2, mid);
	if (f == 2) cout << "I'm Sorry Hansoo";
	else cout << ret;
	return 0;
}