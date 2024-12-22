#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
stack<pair<int,int>> stk;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		if (stk.empty()) {
			cout << "0 ";
			stk.push({ i,k });
		}
		else {
			bool flag = true;
			while (!stk.empty())
			{
				if (stk.top().second > k) {
					flag = false;
					cout << stk.top().first << " ";
					break;
				}
				else {
					stk.pop();
				}
			}
			if (flag)cout << "0 ";
			stk.push({ i,k });
		}
	}
}