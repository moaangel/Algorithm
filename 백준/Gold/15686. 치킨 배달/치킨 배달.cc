#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>>home;
vector<pair<int, int>>chk;
vector<vector<int>> selectchk;

void combi(int idx, vector<int> v) {
	if (v.size() == m) {
		selectchk.push_back(v);
		return;
	}

	for (int i = idx + 1; i < chk.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num == 1)home.push_back({ i,j });
			if (num == 2)chk.push_back({ i,j });
		}
	}
	vector<int> v;
	combi(-1, v);
	int ret = 50000;
	for (auto slct : selectchk) {
		int dir = 0;
		for (pair<int, int> h : home) {
			int temp = 500000;
			for (int a : slct) {
				temp = min(temp, abs(chk[a].first - h.first) + abs(chk[a].second - h.second));
			}
			dir += temp;
		}
		ret = min(ret, dir);
	}
	cout << ret << '\n';
}