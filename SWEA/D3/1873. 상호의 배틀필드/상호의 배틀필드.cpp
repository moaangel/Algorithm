#include<iostream>
#include <string>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

char a[22][22];
int n, m, p,sy,sx;
string ptn;

void shoot(int y, int x, char pnt){
	if (pnt == '<') {
		while (x) {
			if (a[y][x - 1] == '#')break;
			else if (a[y][x - 1] == '*') {
				a[y][x - 1] = '.';
				break;
			}
			else x -= 1;
		}
	}
	else if (pnt == '>') {
		while (x != m-1) {
			if (a[y][x + 1] == '#')break;
			else if (a[y][x + 1] == '*') {
				a[y][x + 1] = '.';
				break;
			}
			else x += 1;
		}
	}
	else if (pnt == '^') {
		while (y) {
			if (a[y-1][x] == '#')break;
			else if (a[y-1][x] == '*') {
				a[y-1][x] = '.';
				break;
			}
			else y -= 1;
		}
	}
	else if (pnt == 'v') {
		while (y != n-1) {
			if (a[y + 1][x] == '#')break;
			else if (a[y + 1][x] == '*') {
				a[y + 1][x] = '.';
				break;
			}
			else y += 1;
		}
	}
}

void go(int y, int x, int cnt) {
	if (cnt == p)return;

	if (ptn[cnt] == 'S') {
		shoot(y,x,a[y][x]);
		go(y, x, cnt + 1);
	}
	else if (ptn[cnt] == 'U') {
		if (y - 1 >= 0 && a[y - 1][x] == '.') {
			a[y][x] = '.';
			a[y - 1][x] = '^';
			go(y - 1, x, cnt + 1);
		}
		else {
			a[y][x] = '^';
			go(y, x, cnt + 1);
		}
	}
	else if (ptn[cnt] == 'D') {
		if (y + 1 <= n - 1 && a[y + 1][x] == '.') {
			a[y][x] = '.';
			a[y + 1][x] = 'v';
			go(y + 1, x, cnt + 1);
		}
		else {
			a[y][x] = 'v';
			go(y, x, cnt + 1);
		}
	}
	else if (ptn[cnt] == 'L') {
		if (x - 1 >= 0 && a[y][x - 1] == '.') {
			a[y][x] = '.';
			a[y][x - 1] = '<';
			go(y, x - 1, cnt + 1);
		}
		else {
			a[y][x] = '<';
			go(y, x, cnt + 1);
		}
	}
	else if (ptn[cnt] == 'R') {
		if (x + 1 <= m-1 && a[y][x + 1] == '.') {
			a[y][x] = '.';
			a[y][x + 1] = '>';
			go(y, x + 1, cnt + 1);
		}
		else {
			a[y][x] = '>';
			go(y, x, cnt + 1);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j];
				if (a[i][j] == '<' || a[i][j] == '>' || a[i][j] == '^' || a[i][j] == 'v') {
					sy = i; sx = j;
				}
			}
		}
		cin >> p;
		cin >> ptn;
		go(sy, sx, 0);
		cout << "#" << test_case << " ";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}