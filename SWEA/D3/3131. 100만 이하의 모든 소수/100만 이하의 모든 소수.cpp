#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool a[1000002];
int main(int argc, char** argv)
{
	for (int i = 2; i <= 1000000; i++) {
		if (a[i])continue;
		for (int j = i * 2; j <= 1000000; j += i) {
			a[j] = 1;
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (!a[i]) cout << i << " ";
	}
	cout << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}