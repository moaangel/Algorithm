#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[12][12];
int yangbun[12][12];
vector<int> tree[12][12];
int n, m, k,ret;

const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void springsummer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size()) {
				int dietree = 0;
				vector<int> temp;
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int age : tree[i][j]) {
					if (yangbun[i][j] >= age) {
						yangbun[i][j] -= age;
						temp.push_back(age + 1);
					}
					else dietree += age / 2;
				}
				yangbun[i][j] += dietree;
				tree[i][j] = temp;
			}
		}
	}
}

void autumn() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() == 0)continue;
			for (int age : tree[i][j]) {
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];

						if (ni < 0 || nj < 0 || ni >= n || nj >= n)continue;
						tree[ni][nj].push_back(1);
					}					
				}
			}
		}
	}
 }

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			yangbun[i][j] += a[i][j];
		}
	}
}

int main() {
	fill(&yangbun[0][0], &yangbun[0][0] + 12 * 12, 5);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x - 1][y - 1].push_back(age);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(tree[i][j].size())
				sort(tree[i][j].begin(), tree[i][j].end());
		}
	}
	for (int i = 0; i < k; i++) {
		springsummer();
		autumn();
		winter();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size())
				ret += tree[i][j].size();
		}
	}
	cout << ret << '\n';
}