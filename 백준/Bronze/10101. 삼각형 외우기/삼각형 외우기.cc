#include <iostream>

using namespace std;

int a, b, c;
int main() {
	cin >> a >> b >> c;
	if (a + b + c == 180) {
		if (a == b && b == c)
			cout << "Equilateral" << endl;
		else if (a == b || a == c || b == c)
			cout << "Isosceles" << endl;
		else if (a != b && b != c && a != c) 
			cout << "Scalene" << endl;
	}
	else
		cout << "Error" << endl;
}