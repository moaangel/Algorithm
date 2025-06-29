#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long x, y, w, s;
	cin >> x >> y >> w >> s;

	long long result = 0;

	if (2 * w <= s) {
		result = (x + y) * w;
	}
	else if (s <= w) {
		long long maxNum = max(x, y);
		long long minNum = min(x, y);

		if ((maxNum - minNum) % 2 == 0) {
			result = minNum * s + (maxNum - minNum) * s;
		}
		else {
			result = minNum * s + (maxNum - minNum - 1) * s + w;
		}
	}
	else {
		long long minNum = min(x, y);
		long long maxNum = max(x, y);
		result = minNum * s + (maxNum - minNum) * w;
	}

	cout << result << endl;
}
