#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v;
map<int,int> sy;
vector<int> numlist;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		numlist.push_back(a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size();i++) {
		sy[v[i]] = i;
	}
	for (int a : numlist) {
		cout << sy[a] << " ";
	}
}