#include <iostream>
#include <algorithm>
using namespace std;

int n,idx,temp, ret = -1000;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		temp += num;
		ret = max(ret, temp);
		if (temp < 0)
			temp = 0;
	}
	cout << ret << '\n';
}