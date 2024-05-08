#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

char a[10][10];
int n, m;

void eat(int y, int x, int dir, char col) {
	char findc;
	if (col == 'B') findc = 'W';
	else findc = 'B';
	int ny = y, nx = x;
	a[y][x] = findc;
	while (1) {
		ny += dy[dir];
		nx += dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) return;
		if (a[ny][nx] == col) a[ny][nx] = findc;
		else if (a[ny][nx] == findc) return;
		else return;
	}
}

bool check(int y, int x, int dir, char col) {
	char findc;
	if (col == 'B') findc = 'W';
	else findc = 'B';
	int ny = y, nx = x;
	while (1) {
		ny += dy[dir];
		nx += dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
		if (a[ny][nx] == col) continue;
		else if (a[ny][nx] == findc) return true;
		else return false;
	}
}

void go(int y, int x, char color) {
	char findc;
	if (color == 'B') findc = 'W';
	else findc = 'B';
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (a[ny][nx] == findc)
			if (check(ny, nx, i, findc))
				eat(ny, nx, i, findc);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		fill(&a[0][0], &a[0][0] + 100, 0);
		int bcnt = 0, wcnt = 0;
		cin >> n >> m;
		if (n == 4) {
			a[1][1] = a[2][2] = 'W';
			a[1][2] = a[2][1] = 'B';
		}
		else if (n == 6) {
			a[2][2] = a[3][3] = 'W';
			a[3][2] = a[2][3] = 'B';
		}
		else {
			a[3][3] = a[4][4] = 'W';
			a[4][3] = a[3][4] = 'B';
		}
		for (int i = 0; i < m; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			y--; x--;
			if (c == 1) {
				a[y][x] = 'B';
				go(y, x, 'B');
			}
			else {
				a[y][x] = 'W';
				go(y, x, 'W');
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 'B')bcnt++;
				else if (a[i][j] == 'W')wcnt++;
			}
		}
		cout << "#" << test_case << " " << bcnt << " " << wcnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}