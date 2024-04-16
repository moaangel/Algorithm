#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> stk;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		if (s == "push") {
			int a;
			cin >> a;
			stk.push(a);
		}
		else if (s == "pop") {
			if (stk.size()) {
				cout << stk.top() << '\n';
				stk.pop();
			}
			else cout << "-1" << '\n';
		}
		else if (s == "size") {
			cout << stk.size() << '\n';
		}
		else if (s == "empty") {
			if (stk.empty())cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "top") {
			if (stk.size()) {
				cout << stk.top() << '\n';
			}
			else cout << "-1" << '\n';
		}
	}
}