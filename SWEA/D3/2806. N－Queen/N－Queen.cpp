#include <iostream>

using namespace std;

int a[12];
int T,n,ret;

bool check(int col,int row) {
	for (int i = 0; i < row; i++) {
		if (col == a[i] || (row - i) == abs(col - a[i]))return false;
	}
	return true;
}

void nqueen(int row) {
	if (row == n) {
		ret++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check(i, row)) {
			a[row] = i;
			nqueen(row + 1);
		}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ret = 0;
		cin >> n;
		nqueen(0);

		cout << "#" << tc << " " << ret << '\n';
	}
}