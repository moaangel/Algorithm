#include<iostream>
#include<string>
#include <algorithm>
#include <map>
using namespace std;

int a[101];
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{		
		int tn;
		cin >> tn;
		fill(a, a + 101, 0);
		for (int i = 0; i < 1000; i++) {
			int num;
			cin >> num;
			a[num]++;
		}
		int mxidx = 0;
		int mxv = 0;
		for (int i = 0; i <= 100; i++) {
			if (mxv <= a[i]) {
				mxv = a[i];
				mxidx = i;
			}
		}

		cout << "#" << test_case << " " << mxidx << '\n';
	}
	return 0;
}