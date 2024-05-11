#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int month[12];
int a, b, c, d,ret;

void swim(int m,int cost) {
	if (m >= 12) {
		ret = min(ret, cost);
		return;
	}
	if (cost >= ret) return;

	swim(m + 1, cost + month[m] * a);
	swim(m + 1, cost + b);
	swim(m + 3, cost + c);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ret = 987654321;
		cin >> a >> b >> c >> d;
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}
		swim(0,0);
		ret = min(ret, d);
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}