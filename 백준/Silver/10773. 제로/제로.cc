#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (!num)stk.pop();
		else stk.push(num);
	}
	int ret = 0;
	int sz = stk.size();
	for (int i = 0; i < sz; i++) {
		ret += stk.top();
		stk.pop();
	}
	cout << ret << '\n';
}