#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };


queue<pair<int, int>> q[1002];
int a[202][202];
int n, k,t,rety,retx;

void go(int num) {
	queue<pair<int, int>> temp;
	while(q[num].size()) {
		int y = q[num].front().first;
		int x = q[num].front().second;

		q[num].pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx])continue;
			a[ny][nx] = num;
			temp.push({ ny,nx });
		}
	}
	q[num] = temp;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j])q[a[i][j]].push({ i,j });
		}
	}
	cin >> t;
	while (t--) {
		for (int i = 1; i <= k; i++) {
			if (q[i].size())
				go(i);
		}
	}
	cin >> rety >> retx;
	cout << a[rety - 1][retx - 1] << '\n';
}