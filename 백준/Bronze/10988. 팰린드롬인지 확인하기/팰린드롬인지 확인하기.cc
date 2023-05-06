#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[s.length() - (1+i)]) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
	return 0;
}