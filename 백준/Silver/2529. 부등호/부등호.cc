#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n;
char a[10];
int numlist[12];
int visited[12];
vector<string> v;

bool oper(char a, char b, char op) {
	if (op == '<' && a < b)return true;
	if (op == '>' && a > b)return true;
	return false;
}

void dfs(int index, string s) {
	if (index == n + 1) {
		v.push_back(s);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i])continue;
		if (index == 0 || oper(s[index - 1], i + '0', a[index - 1])) {
			visited[i] = 1;
			dfs(index + 1, s + to_string(i));
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0, "");
	sort(v.begin(), v.end());

	cout << v[v.size() - 1] << '\n' << v[0] << endl;

}