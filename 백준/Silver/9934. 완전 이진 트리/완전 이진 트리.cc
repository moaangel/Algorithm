#include <iostream>
#include <vector>
using namespace std;

int a[1025];
int lv, sz;
vector<int> v[10];

void maketree(int startindex, int endindex, int level) {
	if (startindex > endindex)
		return;
	if (level == lv)
		return;
	if (startindex == endindex) {
		v[level].push_back(a[startindex]);
		return;
	}
	


	int root = (startindex + endindex) / 2;
	v[level].push_back(a[root]);

	maketree(startindex , root-1, level + 1);
	maketree(root+1, endindex, level + 1);
}

int main() {
	cin >> lv;
	sz = 1;
	for (int i = 1; i <= lv; i++) {
		sz *= 2;
	}
	sz--;

	for (int i = 0; i < sz; i++) {
		cin >> a[i];
	}

	maketree(0,sz,0);

	for (int i = 0; i < lv; i++) {
		for (int a : v[i]) {
			cout << a << " ";
		}
		cout << '\n';
	}
}