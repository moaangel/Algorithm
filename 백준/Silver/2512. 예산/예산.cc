#include <iostream>
#include <algorithm>

using namespace std;

int n, cost;
int arr[10002];

bool check(int num) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > num)temp += num;
		else temp += arr[i];
	}
	return temp <= cost;
}

int main() {
	cin >> n;
	int totalCost = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		totalCost += arr[i];
		ans = max(ans, arr[i]);
	}
	cin >> cost;
	if (totalCost <= cost) {
		cout << ans << endl;
		return 0;
	}
	int l = 1, r = ans;
	while (l <= r) {
		int temp = (l + r) / 2;
		if (check(temp)) {
			ans = temp;
			l = temp + 1;
		}
		else r = temp - 1;
	}
	cout << ans << endl;
}

