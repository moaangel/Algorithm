#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int test_case, n, k, t, m;

struct ScoreList
{
	int team, score, count, lastTime;
};

bool cmp(ScoreList a, ScoreList b) {
	if (a.score == b.score) {
		if (a.count == b.count) {
			return a.lastTime < b.lastTime;
		}
		return a.count < b.count;
	}
	return a.score > b.score;
}

int main() {
	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++) {
		cin >> n >> k >> t >> m;
		map<int, map<int, int>> mp;
		map<int, int> cnt;
		map<int, int> lastTime;
		vector<ScoreList> v;
		for (int i = 0; i < m; i++) {
			int teamId, j, s;
			cin >> teamId >> j >> s;
			mp[teamId][j] = max(mp[teamId][j], s);
			lastTime[teamId] = i;
			cnt[teamId]++;
		}

		for (int i = 1; i <= n; i++) {
			int score = 0;
			for (auto a : mp[i]) {
				score += a.second;
			}
			v.push_back({ i, score, cnt[i], lastTime[i] });
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			if (v[i].team == t) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
}