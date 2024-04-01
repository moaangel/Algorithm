#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[26];
char ret;
bool flag = 1;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (int(s[i]) > 95)
			a[s[i] - 'a']++;
		else
			a[s[i] - 'A']++;
	}

	int temp=0;
	for (int i = 0; i < 26; i++) {
		if (a[i] > temp) {
			flag = 1;
			temp = a[i];
			ret = i + 'A';
		}
		else if (a[i] == temp && temp != 0)
			flag = 0;
	}
	if (flag)
		cout << ret << endl;
	else
		cout << "?" << endl;
}