#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, mxret, mnret;
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
		string num;
		cin >> num;
		mxret = stoi(num);
		mnret = stoi(num);
		for (int j = 0; j < num.size(); j++) {
			for (int k = j - 1; k >= 0; k--) {
				if (num[j] < num[k]) {
					if (k == 0 && num[j] == '0')continue;
					else {
						string temp = num;
						char tmpchar = temp[j];
						temp[j] = temp[k];
						temp[k] = tmpchar;
						mnret = min(mnret, stoi(temp));
					}
				}
				else if (num[j] > num[k]) {
					string temp = num;
					char tmpchar = temp[j];
					temp[j] = temp[k];
					temp[k] = tmpchar;
					mxret = max(mxret, stoi(temp));
				}
			}
		}
		cout << "#" << test_case << " " << mnret << " " << mxret << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}