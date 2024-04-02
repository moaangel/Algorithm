#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n,k;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	cout << v[k - 1] << endl;
}