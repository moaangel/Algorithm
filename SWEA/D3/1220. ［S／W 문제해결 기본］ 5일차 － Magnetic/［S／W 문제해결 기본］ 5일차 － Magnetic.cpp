#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dy[2] = { 1,-1 };

int a[102][102];
int visited[102][102];
int T,n,ret;
vector<pair<int, int>> v;

void check(int y, int x) {
	for (int i = y + 1; i < 100; i++) {
		if (a[i][x] == 2) {
			visited[i][x]++;
			break;
		}
	}
	return;
}

int main() {
	T = 10;
	for (int tc = 1; tc <= T; tc++) {
		fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
		v.clear();
		ret = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1) v.push_back({ i,j });
			}
		}
		for (pair<int, int> arr : v) {
			check(arr.first, arr.second);
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (visited[i][j])ret++;
			}
		}

		cout << "#" << tc << " " << ret << '\n';
	}
}