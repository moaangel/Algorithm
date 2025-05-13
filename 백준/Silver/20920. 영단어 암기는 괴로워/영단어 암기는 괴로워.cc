#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int n, m;
map<string, int> mp;
vector<pair<int, string>> note;
bool cmp(pair<int, string>& a, pair<int, string>& b) {
	if (a.first != b.first) // 1. 자주 나오는 단어가 먼저
		return a.first > b.first;
	if (a.second.length() != b.second.length()) // 2. 길이가 긴 단어가 먼저
		return a.second.length() > b.second.length();
	return a.second < b.second; // 3. 알파벳 순
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.length() < m)continue;
		mp[s]++;
	}
	for (auto a : mp) {
		note.push_back({ a.second, a.first });
	}
	sort(note.begin(), note.end(), cmp);
	for (int i = 0; i < note.size(); i++) {
		cout << note[i].second << '\n';
	}
}