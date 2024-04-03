#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, string>a, pair<int, string>b) {
	if (a.first == b.first)
		return false;
	return a.first < b.first;
}

vector<pair<int, string>>v;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age;
		cin >> name;
		v.push_back({ age,name });
	}
	stable_sort(v.begin(), v.end(), cmp);
	for (auto a : v) {
		cout << a.first << " " << a.second << '\n';
	}
}