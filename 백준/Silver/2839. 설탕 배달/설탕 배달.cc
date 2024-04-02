#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int n,cnt,ret;
bool flag = 0;
int main() {
	cin >> n;
	for (int i = 0; i < 1500; i++) {
		for (int j = 0; j < 1500; j++) {
			if (n == i * 3 + j * 5) {
				ret += (i + j);
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	if (ret)
		cout << ret << endl;
	else
		cout << "-1" << endl;
}