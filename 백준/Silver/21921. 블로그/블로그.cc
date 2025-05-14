#include <iostream>

using namespace std;

int x, n;
int pSum[250002];
int main() {
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		int num = 0;
		cin >> num;
		pSum[i] = pSum[i - 1] + num;
	}
	int maxNum = 0, cnt = 0;
	int j = 0;
	for (int i = x; i <= n; i++) {
		int num = pSum[i] - pSum[j];
		if (num > maxNum) {
			maxNum = num;
			cnt = 1;
		}
		else if (num == maxNum)cnt++;
		j++;
	}
	if (maxNum == 0) {
		cout << "SAD" << '\n';
		return 0;
	}
	cout << maxNum << '\n' << cnt << '\n';
}