#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int visited[19];
int a[9];
int win, loss;
void dfs(int idx, int my, int enemy) {
	if (idx == 9) {
		if (my > enemy)win++;
		else if (my < enemy)loss++;
		return;
	}
	if (my > 85) {
		int ret = 1;
		for (int i = 9 - idx; i >= 1; i--) {
			ret *= i;
		}
		win += ret;
		return;
	}
	if (enemy > 85) {
		int ret = 1;
		for (int i = 9 - idx; i >= 1; i--) {
			ret *= i;
		}
		loss += ret; 
		return;
	}

	for (int i = 1; i <= 18; i++) {
		if (visited[i])continue;
		if (i > a[idx]) {
			visited[i] = 1;
			dfs(idx + 1, my, enemy + i + a[idx]);
			visited[i] = 0;
		}
		else {
			visited[i] = 1;
			dfs(idx + 1, my + i + a[idx], enemy);
			visited[i] = 0;
		}
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
		win = 0; loss = 0;
		fill(visited, visited + 19, 0);
		for (int i = 0; i < 9; i++) {
			int num;
			cin >> num;
			a[i] = num;
			visited[num] = 1;
		}
		dfs(0, 0, 0);
		cout << "#" << test_case << " " << win << " " << loss << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}