#include <iostream>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;

int p, m;
vector<vector<pair<int, string>>> gameRoom;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.second <= b.second;
}

int main() {
	cin >> p >> m;
	for (int i = 0; i < p; i++) {
		int level;
		string nickname;
		cin >> level >> nickname;
		int j = 0;
		bool flag = false;
		while (!flag && j < gameRoom.size()) {
			if (gameRoom[j].front().first - 10 <= level && gameRoom[j].front().first + 10 >= level) {
				if (gameRoom[j].size() < m) {
					gameRoom[j].push_back({ level, nickname });
					flag = true;
				}
			}
			j++;
		}
		if (!flag) {
			vector<pair<int, string>> v;
			v.push_back({ level,nickname });
			gameRoom.push_back(v);
		}
	}
	for (int i = 0; i < gameRoom.size(); i++) {
		sort(gameRoom[i].begin(), gameRoom[i].end(), cmp);
		if (gameRoom[i].size() == m)
			cout << "Started!" << '\n';
		else
			cout << "Waiting!" << '\n';
		for (pair<int, string> user : gameRoom[i]) {
			cout << user.first << " " << user.second << '\n';
		}
	}
}