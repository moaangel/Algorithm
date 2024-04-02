#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,ns;
int num[5];
int main() {
	for (int i = 0; i < 5; i++) {
		int a;
		cin >> a;
		ns += a;
		num[i] = a;
	}
	sort(num, num + 5);
	cout << ns / 5 << '\n' << num[2] << endl;

}