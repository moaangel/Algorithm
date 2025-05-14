#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = 0;
    int idx = 0;
    while (idx < s.size()) {
        n++;
        string num = to_string(n);
        for (char c : num) {
            if (c == s[idx]) {
                idx++;
                if (idx == s.size()) break;
            }
        }
    }

    cout << n << '\n';
}
