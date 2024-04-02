#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int n,cnt;
int main() {
	cin >> n;
	for (int i = 1; i < 10000000; i++) {
		if (to_string(i).find("666") != string::npos) {
			cnt++;
			if (cnt == n) {
				cout << i << endl;
				break;
			}
		}
	}
}