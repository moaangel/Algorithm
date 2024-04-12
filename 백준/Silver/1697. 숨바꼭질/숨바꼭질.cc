#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m,ret;
int visited[200004];
int cnt[200004];
int pre[200004];
int main() {
	cin >> n >> m;


	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	vector<int> v;
	q.push(n);
	while (q.size()) {
		int num = q.front();
		q.pop();
		if (num == m) {
			ret = visited[m];
			break;
		}
		for (int i = 0; i < 3; i++) {
			int newnum;
			if (i == 0)
				newnum = num + 1;
			if (i == 1)
				newnum = num - 1;
			if (i == 2)
				newnum = num * 2;

			if (newnum < 0 || newnum > 200004)continue;
			if (!visited[newnum]) {
				q.push(newnum);
				visited[newnum] = visited[num] + 1;
				pre[newnum] = num;
			}
		}
	}
	cout << ret - 1 << '\n';
	return 0;
}