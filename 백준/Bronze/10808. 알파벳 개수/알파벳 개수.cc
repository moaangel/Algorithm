#include <iostream>
#include <string>
using namespace std;
string S;
int a[26];
int main()
{
	cin >> S;
	for (int i = 0; i < S.length(); i++)
	{
		char d = S[i];
		a[((int)d) - 97]++;
	}
	for (int i : a)
		cout << i << " ";
    return 0;
}