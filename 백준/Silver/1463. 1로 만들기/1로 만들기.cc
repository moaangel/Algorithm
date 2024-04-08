#include <iostream>
#include <algorithm>
using namespace std;

int n, ret = 1000000;

void go(int num,int cnt) {
	if (num == 1) {
		ret = min(ret, cnt);
		return;
	}
	if (cnt >= ret)return;
	if (num % 3 == 0)
		go(num / 3, cnt + 1);
	if (num % 2 == 0)
		go(num / 2, cnt + 1);
	if (num > 1)
		go(num - 1, cnt + 1);

}

int main() {
	cin >> n;
	go(n,0);
	cout << ret << '\n';
}