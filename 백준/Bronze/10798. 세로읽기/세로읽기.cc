#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char a[16][16];
int bsize;
int main() {
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		int siz = s.size();
		bsize = max(bsize, siz);
		for (int j = 0; j < s.size(); j++) {
			a[i][j] = s[j];
		}
	}
	for (int i = 0; i < bsize; i++) {
		for (int j = 0; j < 5; j++) {
			if(a[j][i])
				cout << a[j][i];
		}

	}
	cout << endl;
}