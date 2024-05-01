#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

int n,a,b;
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> a >> b;
		int mxret = min(a, b);
		int mnret = 0;
		if (a + b > n) mnret = a + b - n;
		cout << "#" << test_case << " " << mxret << " " << mnret << '\n';
	}
	return 0;
}