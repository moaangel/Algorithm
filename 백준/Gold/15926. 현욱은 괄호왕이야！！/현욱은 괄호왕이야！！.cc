#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int ret,n;
stack<pair<int,char>> stk;
int a[200001];
int main() {
	cin >> n;		
	string s;
	cin >> s;		
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			stk.push({ i,s[i] });
		else if (s[i] == ')') {
			if (stk.size() && stk.top().second == '(') {
				a[i] = 1;
				a[stk.top().first] = 1;
				stk.pop();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && temp) {
			ret = max(ret, temp);
			temp = 0;
		}
		else if (a[i] == 1) {
			temp++;
		}
	}
	if(temp)ret = max(ret, temp);

	cout << ret << endl;
}