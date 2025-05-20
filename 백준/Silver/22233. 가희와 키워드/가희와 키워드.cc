#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> keywords;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        keywords.insert(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        string temp;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ',') {
                keywords.erase(temp);
                temp.clear();
            }
            else temp += s[j];
        }
        keywords.erase(temp);
        cout << keywords.size() << '\n';
    }
}
