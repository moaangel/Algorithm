#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;
map<string, int> mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size()-i; j++) {
			string temp = s.substr(j, i+1);
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << '\n';
}