#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct medal {
	int gold, silver, bronze;
};


int n, k;
int num, g, s, b, fg,fs,fb;
vector<medal> v;

bool camp(medal a, medal b) {
	if (a.gold == b.gold && b.silver == a.silver)return a.bronze > b.bronze;
	else if (a.gold == b.gold)return a.silver > b.silver;
	return a.gold > b.gold;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num >> g >> s >> b;
		if (num == k) {
			fg = g;
			fs = s;
			fb = b;
		}
		v.push_back({ g,s,b });
	}
	sort(v.begin(), v.end(), camp);

	for (int i = 0; i < n; i++) {
		if (v[i].gold == fg && v[i].silver == fs && v[i].bronze == fb) {
			cout << i + 1 << endl;
			return 0;
		}
	}
}