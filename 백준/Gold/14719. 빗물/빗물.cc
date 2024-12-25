#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ret;
int arr[502];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < m - 1; i++) {
		int l = 0, r = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i] && arr[j] > l) {
				l = arr[j];
			}
		}
		for (int j = i + 1; j < m; j++) {
			if (arr[j] > arr[i] && arr[j] > r) {
				r = arr[j];
			}
		}
		int temp = min(l, r);
		if (temp != 0) ret += (temp - arr[i]);
	}
	cout << ret << '\n';
}