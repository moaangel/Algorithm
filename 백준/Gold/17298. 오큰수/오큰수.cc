#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> stk;
int a[1000002];
int ret[1000002];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!stk.size()) stk.push({ a[i], i });
		else {
			while (stk.size()) {
				if (stk.top().first < a[i]) {
					ret[stk.top().second] = a[i];
					stk.pop();
				}
				else break;
			}
			stk.push({ a[i],i });
		}
	}
	while (stk.size()) {
		ret[stk.top().second] = -1;
		stk.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
	cout << '\n';
}