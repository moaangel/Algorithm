#include <iostream>

int a[9][9];
int max = -1, r, t;
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cin >> a[i][j];

			if (a[i][j] >= max) {
				max = a[i][j];
				r = i+1;
				t = j+1;
			}
		}
	}
	std::cout << max << "\n" << r << " " << t;
}