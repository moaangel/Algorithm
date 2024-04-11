#include <iostream>
#include <algorithm>
using namespace std;

int n;
double ret = -1;
int main() {
	cout << fixed;
	cout.precision(3);
	cin >> n;
	double temp = 1;
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		temp *= num;
		ret = max(ret, temp);
		if (temp < 1)
			temp = 1;
	}
	cout << ret << '\n';
}