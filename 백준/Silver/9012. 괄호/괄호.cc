#include <iostream>
#include <string>
#include <stack>

using namespace std;


int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> stk;
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(')
				stk.push(s[j]);
			else if (s[j] == ')') {
				if (stk.size() && stk.top() == '(')
					stk.pop();
				else stk.push(s[j]);
			}
		}
		if (stk.size())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}