#include <iostream>

int n, m;
int a[15005];
int cnt = 0;
int main() {
	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == m) cnt++;
		}
	}
	std::cout << cnt;

}
