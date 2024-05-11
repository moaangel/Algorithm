#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k, wordsize;
vector<string> v;


bool cmp(string a, string b) {
	for (int i = 0; i < wordsize; i++) {
		if (a[i] == b[i])continue;
		return a[i] > b[i];
	}
	return false;
}

string rtt(string s) {
	string temp = "";
	temp += s[s.size() - 1];
	for (int i = 0; i < s.size()-1; i++) {
		temp += s[i];
	}
	return temp;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		if (v.size())v.clear();
		cin >> n >> k;
		string s;
		cin >> s;
		wordsize = n / 4;
		int rttnum = n / 4;
		while (rttnum) {
			for (int i = 0; i < n; i += wordsize) {
				string temp = "";
				for (int j = i; j < wordsize + i; j++) {
					temp += s[j];
				}
				v.push_back(temp);
			}
			s = rtt(s);
			rttnum--;
		}
		sort(v.begin(), v.end(), cmp);
		v.erase(unique(v.begin(), v.end()), v.end());
		string ret = v[k - 1];
		reverse(ret.begin(), ret.end());
		int ans = 0;
		int temp=0;
		for (int i = 0; i < ret.size(); i++) {
			if (ret[i] - '0' < 10)temp = ret[i] - '0';
			else temp = ret[i] - 'A' + 10;
			ans += (pow(16, i) * temp);
		}
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}