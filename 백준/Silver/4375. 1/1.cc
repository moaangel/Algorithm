#include <stdio.h>
#include <string>

int n;
int main() {
	while (scanf("%d", &n) != EOF) {
		int cnt = 1, ret = 1;
		while (1) {
			if (cnt % n == 0) {
				printf("%d\n", ret);
				break;
			}
			else {
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
}