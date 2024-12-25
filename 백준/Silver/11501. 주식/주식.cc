#include <iostream>
#include <stack>
using namespace std;

long long t,n, ret;
int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		ret = 0;
		cin >> n;
		stack<long long> stk;
		for (int i = 0; i < n; i++) {
			long long num = 0;
			cin >> num;
			stk.push(num);
		}
		long long topPrice = 0;
		while (stk.size()) {
			if (stk.top() > topPrice) {
				topPrice = stk.top();
				stk.pop();
			}
			else if (stk.top() < topPrice) {
				ret += (topPrice - stk.top());
				stk.pop();
			}
			else stk.pop();
		}
		cout << ret << '\n';
	}
}