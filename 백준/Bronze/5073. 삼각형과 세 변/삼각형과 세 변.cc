#include <iostream>
#include<algorithm>
using namespace std;


int main() {
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		int temp = max(a, b);
		int ll = max(temp, c);
		if (ll == a && a >= b + c) {
			cout << "Invalid" << endl;
			continue;
		}
		else if (ll == b && b >= a + c) {
			cout << "Invalid" << endl;
			continue;
		}
		else if (ll == c && c >= b + a) {
			cout << "Invalid" << endl;
			continue;
		}
		else {
			if (a == b && b == c)
				cout << "Equilateral" << endl;
			else if (a == b || a == c || b == c)
				cout << "Isosceles" << endl;
			else if (a != b && b != c && a != c)
				cout << "Scalene" << endl;
		}
	}
}