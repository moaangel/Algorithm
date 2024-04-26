#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,ret;
int a[1001][1001];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

vector<pair<int, int>> v;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

void dfs(int y, int x) {
	ret++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (a[ny][nx] == a[y][x] + 1)
			dfs(ny, nx);
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (v.size()) v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = 0;
				dfs(i,j);
				v.push_back({ ret,a[i][j] });
			}
		}
		sort(v.begin(), v.end(), cmp);
		cout << "#" << test_case << " " << v[0].second << " " << v[0].first << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}