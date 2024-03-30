#include <iostream>

using namespace std;

int has = 64;
int tomak[7];
int x,cnt;
int main() {
	cin >> x;

	if (x == 64) {
		cout << "1" << endl;
		return 0;
	}
	while (1) {
		if ((has >> 1) > x)
			has = (has >> 1);
		else {
			cnt++;
			has = (has >> 1);
			x -= has;
		}

		if (x == 0)
			break;
	}
	cout << cnt << endl;
}

