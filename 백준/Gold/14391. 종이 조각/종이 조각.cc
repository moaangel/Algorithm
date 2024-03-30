#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[5][5];
int n, m, ret;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char nu;
			cin >> nu;
			a[i][j] = nu - '0';
		}
	}


	for (int s = 0; s < (1 << (n * m)); s++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int temp=0;
			for (int j = 0; j < m; j++) {
				int k = i * m + j;
				if ((s & (1 << k)) == 0) {
					temp = temp * 10 + a[i][j];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}

		for (int j = 0; j < m; j++) {
			int temp=0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				if ((s & (1 << k)) != 0) {
					temp = temp * 10 + a[i][j];
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}
		ret = max(ret, sum);
	}

	cout << ret << endl;
}