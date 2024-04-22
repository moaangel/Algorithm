#include<iostream>
#include<string>
#include<stack>
#include <vector>
using namespace std;

int n, ret;
string s;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	T= 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 1;
		stack<char> stk;
		cin >> n;
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') stk.push(s[i]);
			else if (s[i] == '{') stk.push(s[i]);
			else if (s[i] == '[') stk.push(s[i]);
			else if (s[i] == '<') stk.push(s[i]);
			else if (s[i] == ')') {
				if (stk.size() && stk.top() == '(')
					stk.pop();
				else {
					ret = 0;
					break;
				}
			}
			else if (s[i] == '}') {
				if (stk.size() && stk.top() == '{')
					stk.pop();
				else {
					ret = 0;
					break;
				}
			}
			else if (s[i] == '>') {
				if (stk.size() && stk.top() == '<')
					stk.pop();
				else {
					ret = 0;
					break;
				}
			}
			else if (s[i] == ']') {
				if (stk.size() && stk.top() == '[')
					stk.pop();
				else {
					ret = 0;
					break;
				}
			}
		}
		if (stk.size())ret = 0;
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}