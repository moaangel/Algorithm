#include <iostream>
#include <string>
using namespace std;

long long ggung[70];
int t, n;
int main() {
	ggung[0] = 1;
	ggung[1] = 1;
	ggung[2] = 2;
	ggung[3] = 4;
	for (int i = 4; i < 70; i++) {
		ggung[i] = ggung[i-1] + ggung[i-2] + ggung[i-3] + ggung[i-4];
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << ggung[n] << '\n';
	}
}