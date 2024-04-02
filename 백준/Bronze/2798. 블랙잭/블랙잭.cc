#include <iostream>

using namespace std;

int n, m, ret, ch = 300001;
int a[101];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				temp = a[i] + a[j] + a[k];
				if (temp <= m && m-temp < ch) {
					ret = temp;
					ch = abs(temp - m);
				}
			}
		}
	}
	cout << ret << endl;
}