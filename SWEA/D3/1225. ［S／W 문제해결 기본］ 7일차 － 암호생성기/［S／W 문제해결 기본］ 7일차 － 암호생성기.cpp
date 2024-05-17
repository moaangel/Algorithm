#include <iostream>
#include <string>
using namespace std;

int a[10];
int T= 10,n,ret;
int main() {
	for (int test_case = 1; test_case <= T; test_case++) {
		int g;
		cin >> g;
		for (int i = 0; i < 8; i++) {
			cin >> a[i];
		}
		bool flag = 1;
		while (flag) {
			for (int i = 1; i <= 5; i++) {
				a[0] -= i;
				if (a[0] <= 0) {
					flag = 0;
					a[0] = 0;
				}
				a[8] = a[0];
				for (int j = 0; j < 8; j++) {
					a[j] = a[j + 1];\
				}
				if (!flag)break;
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < 8; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
	}
}