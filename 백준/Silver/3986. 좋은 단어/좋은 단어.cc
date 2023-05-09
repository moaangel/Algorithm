#include <iostream>
#include <string>
#include <stack>
int n,cnt;
int main() {
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		std::stack<char> stk;
		for (char a : str) {
			if (stk.size() && stk.top() == a) // size 사용 이유:참조오류 방지(스택에 값이 있는가)
				stk.pop();
			else
				stk.push(a);
		}
		if (stk.size() == 0)cnt++;
	}
	std::cout << cnt;
}
