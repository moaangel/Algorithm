#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;
int main() {
	while (1) {
		if (v.size())
			v.clear();
		cin >> n;
		if (n == -1)
			break;
		int temp = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				v.push_back(i);
				temp += i;
			}
		}
		if (temp == n) {
			cout << n << " = ";
			for (int a : v) {
				if (a == v[v.size() - 1])
					cout << a << endl;
				else
					cout << a << " + ";
			}
		}
		else
			cout << n << " is NOT perfect." << endl;
	}
}