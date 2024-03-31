#include <iostream>
#include <string>
#include <deque>

using namespace std;


int t, n;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		deque<int> dq;
		string op, arr;
		cin >> op;
		int arrsize, temp = 0;
		cin >> arrsize;
		cin >> arr;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == '[' && arr[j] == ']') continue;
			if (arr[j] >= '0' && arr[j] <= '9') {
				temp = temp * 10 + (arr[j] - '0');
			}
			else {
				if (temp > 0) {
					dq.push_back(temp);
					temp = 0;
				}
			}
		}
		if (temp > 0)dq.push_back(temp);
		
		bool flag = false, err = false;
		for (int k = 0; k < op.size(); k++) {
			if (op[k] == 'R') {
				if (flag)flag = 0;
				else flag = 1;
			}
			if (op[k] == 'D') {
				if (!dq.size()) {
					err = true;
					break;
				}
				else {
					if (flag)dq.pop_back();
					else dq.pop_front();
				}
			}
		}
		if (err) {
			cout << "error" << endl;
		}
		else {
			cout << "[";
			if (flag) {
				for (int l = dq.size()-1; l >= 0; l--) {
					if (l == 0) {
						cout << dq[l];
						continue;
					}
					cout << dq[l] << ",";
				}
			}
			else {
				for (int l = 0; l < dq.size(); l++) {
					if (l == dq.size() - 1) {
						cout << dq[l];
						continue;
					}
					cout << dq[l] << ",";
				}
			}
			cout << "]" << endl;
		}
	}
}