#include <iostream>
#include <string>

using namespace std;

int A, B, C, d, e;
int cnt[101];
int ret;
int main()
{
	
	cin >> A >> B >> C;
	
	for (int i = 0; i < 3; i++)
	{
		cin >> d >> e;
		for (int j = d; j < e; j++)
		{
			cnt[j]++;
		}
	}

	for (int i = 1; i < 100; i++)
	{
		if (cnt[i] == 1)
			ret += A;
		else if (cnt[i] == 2)
			ret += B * 2;
		else if (cnt[i] == 3)
			ret += C * 3;
	}
	cout << ret << endl;
	return 0;
}