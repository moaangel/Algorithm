#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,ret= 50000;
int a[11][11];
int visited[11][11];
vector<pair<int,int>> v;
vector<pair<int, int>> flower;

int price(vector<pair<int, int>> flower) {
	int total=0;
	for (pair<int, int> here : flower) {
		int pri=0;
		pri = a[here.first][here.second] + a[here.first + 1][here.second] + a[here.first - 1][here.second] + a[here.first][here.second + 1] + a[here.first][here.second - 1];
		total += pri;
	}
	return total;
}

bool check(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		if (a.second == b.second || a.second == b.second + 1 || a.second == b.second + 2
			|| a.second == b.second - 1 || a.second == b.second - 2)
			return false;
	}
	if (a.first == b.first + 1 || a.first == b.first - 1) {
		if (a.second == b.second || a.second == b.second + 1 || a.second == b.second - 1)
			return false;
	}
	if (a.first == b.first + 2 || a.first == b.first - 2)
		if (a.second == b.second)
			return false;
	return true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				if (check(v[i], v[j]) && check(v[i], v[k]) && check(v[k], v[j])) {
					flower.push_back(v[i]);
					flower.push_back(v[j]);
					flower.push_back(v[k]);
					ret = min(ret,price(flower));
					flower.clear();
				}
				else continue;
			}
		}
	}
	cout << ret << endl;
}