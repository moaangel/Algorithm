#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 50000;
int n, m, ret;
int	a[51][51];
vector<pair<int, int>> chick;
vector<pair<int, int>> home;
vector<vector<int>> chickL;

void combi(int index, vector<int> v) {
	if (v.size() == m) {
		chickL.push_back(v);
		return;
	}

	for (int i = index + 1; i < chick.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2)
				chick.push_back({ i,j });
			if (a[i][j] == 1)
				home.push_back({ i,j });
		}
	}
	vector<int> v;
	combi(-1, v);

	for (vector<int> list : chickL) {
		ret = 0;
		for (pair<int, int> hd : home) {
			int mindis = 50000;
			for (int cd : list) {
				int dis = abs(hd.first - chick[cd].first) + abs(hd.second - chick[cd].second);
				mindis = min(mindis, dis);
			}
			ret += mindis;
		}
		ans = min(ans, ret);
	}
	cout << ans << endl;
}