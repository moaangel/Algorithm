#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int T;
int n;
vector<pair<int, int>>v;
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		if(v.size())v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int s, e;
			cin >> s >> e;
			if (s % 2 == 1)s+= 1;
			if (e % 2 == 1)e+= 1;
			if (s > e) v.push_back({ e,s });
			else v.push_back({ s,e });
		}
		sort(v.begin(), v.end());
		int ret = 0;
		while (1) {
			ret++;
			vector<pair<int, int>> temp;
			int i = 0;
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i].second >= v[j].first) temp.push_back({ v[j].first,v[j].second });
				else {

					i = j;
				}
			}
			if (temp.size()) v = temp;
			else break;
		}
		cout << "#" << tc << " " << ret << '\n';
	}
}