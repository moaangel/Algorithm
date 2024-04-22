#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m,ret;
vector<int> v[102];
int visited[102];

void bfs(int num) {
	queue<int> q;
	q.push(num);
	
	while (q.size()) {
		int here = q.front();
		q.pop();

		for (int a : v[here]) {
			if (visited[a])continue;
			visited[a] = visited[here] + 1;
			q.push(a);
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{	
		ret = 0;
		fill(visited, visited + 102, 0);
		for (int i = 0; i < 102; i++) {
			if (v[i].size())v[i].clear();
		}
		cin >> n >> m;
		for (int i = 0; i < n/2; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		visited[m] = 1;
		bfs(m);
		int vmax = 0;
		for (int i = 1; i <= 100; i++) {
			if (visited[i] > vmax) {
				vmax = visited[i];
				ret = i;
			}
			else if (visited[i] == vmax) {
				ret = max(ret, i);
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}