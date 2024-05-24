#include <iostream>
#include <string>

using namespace std;

int visited[11111];

void d(int num) {
	int temp = num;
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		temp += s[i] - '0';
	}
	visited[temp] = 1;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		d(i);
	}
	for (int i = 1; i <= 10000; i++) {
		if (!visited[i])
			cout << i << '\n';
	}
}