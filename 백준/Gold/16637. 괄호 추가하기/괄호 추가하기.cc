#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ret = -987654321;
int n;
string s;
vector<int> num;
vector<char> oper;

int cal(char a, int b, int c) {
	if (a == '*')
		return b * c;
	if (a == '+')
		return b + c;
	if (a == '-')
		return b - c;
}

void go(int index, int n) {
	if (index == num.size() - 1) {
		ret = max(ret, n);
		return;
	}

	go(index + 1, cal(oper[index], n, num[index + 1]));
	if (index + 2 <= num.size() - 1) {
		int temp = cal(oper[index + 1], num[index + 1], num[index + 2]);
		go(index + 2, cal(oper[index], n, temp));
	}
}

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			num.push_back(s[i] - '0');
		else
			oper.push_back(s[i]);
	}

	go(0, num[0]);
	cout << ret << endl;
}