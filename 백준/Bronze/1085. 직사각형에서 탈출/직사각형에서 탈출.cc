#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d, ret;
int main() {
	cin >> a >> b >> c >> d;
	ret = min(min(b,(d-b)), min(a, (c - a)));
	cout << ret << endl;
}