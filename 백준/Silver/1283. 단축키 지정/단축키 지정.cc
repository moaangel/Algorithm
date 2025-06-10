#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<char, int> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mp[' '] = 1;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		vector<string> words;
		string word;
		while (getline(ss, word, ' ')) {
			words.push_back(word);
		}
		int flag = 0;
		for (int j = 0; j < words.size(); j++) {
			if (mp[words[j][0]] != 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int j = 0; j < s.length(); j++) {
				if (mp[s[j]] != 1) {
					flag = 2;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << s << '\n';
		}
		else if (flag == 1) {
			bool vFlag = false;
			for (int j = 0; j < words.size(); j++) {
				if (vFlag) {
					cout << words[j];
				}
				else {
					if (mp[words[j][0]] != 1) {
						mp[words[j][0]] = 1;
						mp[words[j][0] + 32] = 1;
						mp[words[j][0] - 32] = 1;

						vFlag = true;
						cout << '[' << words[j][0] << ']';
						for (int k = 1; k < words[j].length(); k++) {
							cout << words[j][k];
						}

					}
					else {
						cout << words[j];
					}
				}
				if (j == words.size() - 1)
					cout << '\n';
				else
					cout << " ";
			}
		}
		else {
			bool vFlag = false;
			for (int j = 0; j < s.length(); j++) {
				if (vFlag) {
					cout << s[j];
				}
				else {
					if (mp[s[j]] != 1) {
						vFlag = true;
						mp[s[j]] = 1;
						mp[s[j] + 32] = 1;
						mp[s[j] - 32] = 1;
						cout << '[' << s[j] << ']';
					}
					else
						cout << s[j];
				}
			}
			cout << '\n';
		}
	}
}