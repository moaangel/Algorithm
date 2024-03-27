#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

char a[1501][1501];
int visited[1501][1501];
int visited_duck[1501][1501];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int r, c, cnt, ducky,duckx;
queue<pair<int, int>> duck;
queue<pair<int, int>> nextduck;
queue<pair<int, int>> waterlist;
queue<pair<int, int>> nextwater;

void Qclear(queue<pair<int, int>> &q) {
	queue<pair<int, int>> temp;
	swap(q, temp);
}

void nextday() {
	while (waterlist.size()) {
		int y = waterlist.front().first;
		int x = waterlist.front().second;

		waterlist.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
			if (a[ny][nx] == 'X') {
				nextwater.push({ ny,nx });
				visited[ny][nx] = 1;
				a[ny][nx] = '.';
			}
		}
	}
}

bool findduck() {
	while (duck.size()) {
		int y = duck.front().first;
		int x = duck.front().second;

		duck.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited_duck[ny][nx]) continue;
			visited_duck[ny][nx] = 1;
			if (a[ny][nx] == 'X') {
				nextduck.push({ ny,nx });
			}
			if (a[ny][nx] == '.') {
				duck.push({ ny,nx });
			}
			if (a[ny][nx] == 'L')
				return true;
		}
	}
	return false;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') {
				ducky = i;
				duckx = j;
			}
			if (a[i][j] == 'L' || a[i][j] == '.') {
				visited[i][j] = 1;
				waterlist.push({ i,j });
			}
		}
	}
	visited_duck[ducky][duckx] = 1;
	duck.push({ ducky,duckx });
	while (1) {
		if (findduck())
			break;
		nextday();
		duck = nextduck;
		waterlist = nextwater;
		Qclear(nextduck);
		Qclear(nextwater);
		cnt++;
	}
	cout << cnt << endl;
}