#include <iostream>
#include <string>

using namespace std;

string s,pok, ret;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s >> pok;
	for (char a : s) {
		ret += a;
		if (ret.size() >= pok.size() && ret.substr(ret.size() - pok.size(), pok.size()) == pok) {
			ret.erase(ret.size() - pok.size(), pok.size());
		}
	}
	if (ret.size())
		cout << ret << '\n';
	else cout << "FRULA" << '\n';
}