#include<iostream>

using namespace std;

int fibo[42];
int n;

int f(int num) {
	if (num == 1 || num == 2) return 1;

	if (fibo[num])return fibo[num];
	fibo[num] = f(num - 1) + f(num - 2);

	return fibo[num];
}

int main() {
	cin >> n;
	f(n);
	cout << fibo[n] << " " << n - 2 << '\n';
}