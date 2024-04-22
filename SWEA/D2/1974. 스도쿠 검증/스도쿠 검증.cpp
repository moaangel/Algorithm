#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int a[10][10];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 9; i++) {
			vector<int> v;
			for (int j = 0; j < 9; j++) {
				v.push_back(a[i][j]);
			}
			sort(v.begin(), v.end());
			for (int k = 0; k < 9; k++) {
				if (v[k] != k + 1) {
					ret = 0;
					break;
				}
			}
			if (ret == 0)break;
		}
		if (ret) {
			for (int j = 0; j < 9; j++) {
				vector<int> v;
				for (int i = 0; i < 9; i++) {
					v.push_back(a[i][j]);
				}
				sort(v.begin(), v.end());
				for (int k = 0; k < 9; k++) {
					if (v[k] != k + 1) {
						ret = 0;
						break;
					}
				}
				if (ret == 0)break;
			}
		}
		if (ret) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if ((i == 0 || i == 3 || i == 6) && (j == 0 || j == 3 || j == 6)) {
						vector<int> v;
						for (int k = i; k < i + 3; k++) {
							for (int l = j; l < j + 3; l++) {
								v.push_back(a[k][l]);
							}
						}
						sort(v.begin(), v.end());
						for (int k = 0; k < 9; k++) {
							if (v[k] != k + 1) {
								ret = 0;
								break;
							}
						}
						if (ret == 0)break;
					}
				}
				if (ret == 0)break;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}