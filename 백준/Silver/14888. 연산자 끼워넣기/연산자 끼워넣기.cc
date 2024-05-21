#include <iostream>
#include <algorithm>
using namespace std;

int n, mn = 1000000001, mx= -1000000001;
int a[13];
int oper[4];

void go(int num, int idx, int plus, int minus, int mul, int div) {
	if (idx == n) {
		mn = min(mn, num);
		mx = max(mx, num);
		return;
	}

	if (plus) go(num + a[idx], idx + 1, plus - 1, minus, mul, div);
	if (minus) go(num - a[idx], idx + 1, plus, minus - 1, mul, div);
	if (mul) go(num * a[idx], idx + 1, plus, minus, mul - 1, div);
	if (div) go(num / a[idx], idx + 1, plus , minus, mul, div - 1);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	go(a[0], 1, oper[0], oper[1], oper[2], oper[3]);
	cout << mx << '\n' << mn << '\n';
}