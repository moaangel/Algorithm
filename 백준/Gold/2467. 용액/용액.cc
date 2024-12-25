#include <iostream>
#include <algorithm>

using namespace std;

int n,ret1,ret2;
int arr[100002];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	int s = 0, e = n - 1;
	int temp = 2000000001;
	while (s < e) {
		int mid = arr[s] + arr[e];
		if (abs(mid) < temp) {
			temp = abs(mid);
			ret1 = arr[s];
			ret2 = arr[e];
		}
		if (mid > 0)e--;
		else s++;
	}
	cout << ret1 << " " << ret2 << '\n';
}