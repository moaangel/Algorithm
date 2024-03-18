#include <iostream>
#include <stack>

using namespace std;

int n,now,best;
int a[1000001];
stack<int> stk;
int ret[1000001];


int main() {
	cin >> n;
	fill(ret,ret+1000001,-1);
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		a[i] = num;
		while (stk.size() && a[stk.top()] < a[i]) {
			ret[stk.top()] = a[i];
			stk.pop();
		}
		stk.push(i);
	}


	for (int i = 1; i <= n; i++) {
		cout << ret[i] << " ";
	}
}
