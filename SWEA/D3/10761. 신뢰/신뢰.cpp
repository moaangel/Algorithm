#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		int n;
		cin >> n;
		int ohere = 1, bhere = 1, worktime =0;
		char last='a';
		for (int i = 0; i < n; i++) {
			char a; int b;
			cin >> a >> b;
			if (last == a) {
				if (a == 'O') {
					if (b == ohere) {
						ret++;
						worktime++;
					}
					else {
						worktime += abs(ohere - b) + 1;
						ret += abs(ohere - b) + 1;
						ohere = b;
					}
				}
				else {
					if (b == bhere) {
						ret++;
						worktime++;
					}
					else {
						worktime += abs(bhere - b) + 1;
						ret += abs(bhere - b) + 1;
						bhere = b;
					}
				}
			}
			else {
				if (a == 'O') {
					if (b == ohere) {
						ret++;
						worktime = 1;
					}
					else {
						if (worktime >= abs(ohere - b)) {
							ret++;
							worktime = 1;
							ohere = b;
						}
						else {
							worktime = abs(ohere - b) - worktime + 1;
							ret += worktime;
							ohere = b;
						}
					}
				}
				else {
					if (b == bhere) {
						ret++;
						worktime = 1;
					}
					else {
						if (worktime >= abs(bhere - b)) {
							ret++;
							worktime = 1;
							bhere = b;
						}
						else {
							worktime = abs(bhere - b) - worktime + 1;
							ret += worktime;
							bhere = b;
						}
					}
				}
				last = a;
			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}