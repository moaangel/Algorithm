#include <iostream>
#include <queue>

using namespace std;

int n, m;
int visited[100001];
int cnt[100001];
int main() {
	cin >> n >> m;
	if (n == m) {
		cout << "0" << '\n' << "1" << endl;
		return 0;
	}

	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);
	while (q.size()) {
		int num = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int newnum;
			if (i == 0)
				newnum = num + 1;
			if (i == 1)
				newnum = num - 1;
			if (i == 2)
				newnum = num * 2;

			if (newnum < 0 || newnum > 100000)continue;
			if (!visited[newnum]) {
				q.push(newnum);
				visited[newnum] = visited[num] + 1;
				cnt[newnum] += cnt[num];
			}
			else if (visited[newnum] == visited[num] + 1) {
				cnt[newnum] += cnt[num];
			}
		}
	}
	cout << visited[m] - 1 << '\n' << cnt[m];
}