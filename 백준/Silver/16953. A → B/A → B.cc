#include <iostream>
#include <algorithm>
using namespace std;

long long a, b, ret = 1000000000;

void go(long long num, long long cnt) {
	if (num == b) {
		ret = min(ret, cnt);
	}
	if (num < 0 || num > b)return;

	go(num * 2, cnt + 1);
	go(num * 10 +1, cnt + 1);
}

int main() {
	cin >> a >> b;
	go(a,1);
	if(ret != 1000000000) cout << ret << '\n';
	else cout << -1 << '\n';
}