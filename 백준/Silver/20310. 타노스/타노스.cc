#include <iostream>
#include <string>

using namespace std;

int arr[2];

string s;
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0')arr[0]++;
		else arr[1]++;
	}
	arr[0] /= 2;
	arr[1] /= 2;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i;
		}
	}
}