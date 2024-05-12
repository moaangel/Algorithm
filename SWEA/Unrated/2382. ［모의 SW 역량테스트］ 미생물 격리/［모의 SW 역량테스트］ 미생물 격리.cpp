#include<iostream>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

pair<int, int> a[102][102];
pair<int, int> temp[102][102];
pair<int, int> best[102][102];
int n, m, k;

void go(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny == 0) { dir = 1; a[y][x].first /= 2; }
	else if (ny == n - 1) { dir = 0; a[y][x].first /= 2; }
	else if (nx == 0) { dir = 3; a[y][x].first /= 2; }
	else if (nx == n - 1) { dir = 2; a[y][x].first /= 2; }
	if (temp[ny][nx].first) {
		if (a[y][x].first > best[ny][nx].first) {
			best[ny][nx].first = a[y][x].first;
			best[ny][nx].second = dir;
			temp[ny][nx].second = dir;
		}
		temp[ny][nx].first += a[y][x].first;
	}
	else {
		best[ny][nx].first = a[y][x].first;
		best[ny][nx].second = dir;
		temp[ny][nx].first += a[y][x].first;
		temp[ny][nx].second = dir;
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
		fill(&a[0][0], &a[0][0] + 102 * 102, make_pair(0,0));
		int ret = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int y, x, num, dir;
			cin >> y >> x >> num >> dir;
			a[y][x].first = num;
			a[y][x].second = dir-1;
		}
		
		for (int i = 0; i < m; i++) {
			fill(&temp[0][0], &temp[0][0] + 102 * 102, make_pair(0, 0));
			fill(&best[0][0], &best[0][0] + 102 * 102, make_pair(0, 0));
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (a[j][k].first) go(j, k, a[j][k].second);
				}
			}
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					a[j][k].first = temp[j][k].first;
					a[j][k].second = temp[j][k].second;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j].first) ret += a[i][j].first;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}