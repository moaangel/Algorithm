#include <iostream>

using namespace std;

int t;
int cnt;
void go(int now, int num) {
	if (now == num) {
		cnt++;
		return;
	}
	if (now > num) {
		return;
	}
	go(now + 1, num);
	go(now + 2, num);
	go(now + 3, num);
}

int main() {
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cnt = 0;
		int num;
		cin >> num;
		go(0,num);
		cout << cnt << '\n';
	}
}