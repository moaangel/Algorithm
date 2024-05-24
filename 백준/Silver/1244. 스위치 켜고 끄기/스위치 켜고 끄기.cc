#include <iostream>

using namespace std;

int a[102];
int n,m;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int gen, num;
		cin >> gen >> num;
		if (gen == 1) {
			for (int j = num; j <= n; j += num) {
				a[j] ^= 1;
			}
		}
		if (gen == 2) {
			int temp = 1;
			while (1) {
				if ((num - temp > 0 && num + temp <= n) && a[num - temp] == a[num + temp]) {
					temp++;
				}
				else {
					temp--;
					break;
				}
			}
			for (int j = num - temp; j <= num + temp; j++) {
				a[j] ^= 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
		if (i % 20 == 0)cout << '\n';
	}
	cout << '\n';
}