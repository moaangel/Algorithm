#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[50];
int visited[50];
int n,ls,cnt,p;
bool isleaf;

void dfs(int i) {
	visited[i] = 1;
	if (tree[i].size()) {
		for (int a : tree[i]) {
			if (a == ls && tree[i].size() == 1) {
				cnt++;
				return;
			}
			if (visited[a] == 0 && a != ls)
				dfs(a);
		}
	}
	else cnt++;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int parant;
		cin >> parant;
		if (parant == -1) {
			p = i;
			continue; 
		}
		else tree[parant].push_back(i);
	}
	cin >> ls;
	if (ls != p) {
		dfs(p);
	}
	cout << cnt << endl;
}