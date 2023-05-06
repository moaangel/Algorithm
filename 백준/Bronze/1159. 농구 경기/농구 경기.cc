#include <iostream>
#include <string>

using namespace std;

int N;
int a[26];
string person;
int cnt;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> person;
		int e = person[0] - 'a';
		a[e]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i] >= 5)
		{
			cout << char(i+'a');
		}
		else cnt++;
	}
	if (cnt == 26)
		cout << "PREDAJA";
	return 0;
}