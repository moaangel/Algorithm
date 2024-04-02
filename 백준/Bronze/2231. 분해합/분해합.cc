#include <iostream>

using namespace std;

int n,ret;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int num = i;
		int temp = num;
		while (num) {
			temp += num % 10;
			num /= 10;
		};
		if (temp == n) {
			ret = i;
			break;
		}
	}
	cout << ret << endl;
}