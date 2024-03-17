#include <iostream>
#include <string>
#include <stack>

using namespace std;


int n;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s== ".")break;
		stack<char> s1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')s1.push(s[i]);
			if (s[i] == '[')s1.push(s[i]);
			
			if (s[i] == ')') {
				if (s1.size() && s1.top() == '(')
					s1.pop();
				else
					s1.push(s[i]);
			}
			if (s[i] == ']') {
				if (s1.size() && s1.top() == '[')
					s1.pop();
				else
					s1.push(s[i]);
			}
		}
		if (s1.size())
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
}