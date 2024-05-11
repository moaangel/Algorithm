#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int a[4][8];
int temp[4][8];
int k;

void rtt(int num, int dir) {
	if (dir == 1) {
		temp[num][0] = a[num][7];
		for (int i = 0; i < 7; i++) {
			temp[num][i + 1] = a[num][i];
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			temp[num][i] = a[num][i+1];
		}
		temp[num][7] = a[num][0];
	}

	for (int i = 0; i < 8; i++) {
		a[num][i] = temp[num][i];
	}
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
		int ret = 0;
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < k; i++) {
			int num, dir;
			cin >> num >> dir;
			num-=1;
			vector<pair<int, int>>v;
			v.push_back({ num,dir });
			for (int j = num - 1; j >= 0; j--) {
				if (a[j][2] != a[j + 1][6]) {
					if ((num - j) % 2 == 0) v.push_back({ j,dir });
					else v.push_back({ j,-dir });
					continue;
				}
				else break;
			}
			for (int j = num + 1; j < 4; j++) {
				if (a[j-1][2] != a[j][6]) {
					if ((j- num) % 2 == 0) v.push_back({ j,dir });
					else {
						v.push_back({ j,-dir });
					}
					continue;
				}
				else break;
			}
			for (pair<int,int> vn : v) {
				rtt(vn.first, vn.second);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (a[i][0] == 1) {
				if (i == 0) ret++;
				if (i == 1) ret += 2;
				if (i == 2) ret += 4;
				if (i == 3) ret += 8;

			}
		}
		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}