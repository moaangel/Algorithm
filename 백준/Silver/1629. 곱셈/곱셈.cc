#include <iostream>

long long a, b, c;

long long oper(long long a, long long b) {
	if (b == 1) return a % c;

	long long ret = oper(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2) ret = (ret * a) % c;

	return ret;
}

int main() {

	std::cin >> a >> b >> c;

	std::cout << oper(a, b);
}