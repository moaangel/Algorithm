#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int n;
vector<string> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		double a, b;
		cin >> a >> b;
		double c1, c2;
		c1 = (1 - a) * b;
		c2 = a * (1-b) * b;
		if (c2 > c1)
			cout << "#" << test_case << " YES" << '\n';
		else
			cout << "#" << test_case << " NO" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}