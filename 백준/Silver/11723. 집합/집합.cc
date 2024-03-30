#include <iostream>
#include <string>
using namespace std;

int s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string op;
		int x;
		cin >> op;
		if (op == "all")
			s |= ((1 << 21) - 1);
		else if (op == "empty")
			s = 0;
		else {
			cin >> x;
			if (op == "add") {
				s |= (1 << x);
			}
			else if (op == "remove") {
				s &= ~(1 << x);
			}
			else if (op == "check") {
				if (s & (1 << x))cout << "1" << '\n';
				else cout << "0" << '\n';
			}
			else if (op == "toggle") {
				s ^= (1 << x);
			}
		}
	}
}