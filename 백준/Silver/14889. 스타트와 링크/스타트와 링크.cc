#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[22][22];
int n, ret = 2000;
int visited[22];
vector<int> v;

int cal(vector<int> &v,vector<int>&v2){
	int tp=0, ep=0;
	
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j)continue;
			tp += a[v[i]][v[j]];
			ep += a[v2[i]][v2[j]];
		}
	}
	return abs(tp-ep);
}

void dfs(int num, vector<int>&v) {
	if (v.size() == n / 2) {
		vector<int> enemy;
		vector<int> team;
		for (int i = 1; i <= n; i++) {
			if (visited[i])team.push_back(i);
			else enemy.push_back(i);
		}
		ret = min(ret, cal(team, enemy));
		return;
	}
	for (int i = num + 1; i <= n; i++) {
		visited[i] = 1;
		v.push_back(i);
		dfs(i, v);
		visited[i] = 0;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0,v);
	cout << ret << '\n';
}